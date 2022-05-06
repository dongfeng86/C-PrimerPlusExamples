// C++_THREAD.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
注意:
(1) C++主线程终止时，同时也会终止所有主线程创建的子线程，不管子线程有没有执行完毕。
(2) 如果某线程挂起，然后有调用WaitForSingleObject等待该线程，就会导致死锁。
(3) 线程执行时候, 事件处于未触发, 执行完毕后自动设为触发状态.
*/

#define WHICH_ONE_ 2

#if WHICH_ONE_==1
#include <windows.h>
#include <stdio.h>
#include <process.h>

unsigned Counter;
unsigned __stdcall SecondThreadFunc(void* pArguments)
{
	printf("In second thread...\n");

	while (Counter < 1000000)
		Counter++;

	_endthreadex(0);
	return 0;
}

int main()
{
	HANDLE hThread;
	unsigned threadID;

	printf("Creating second thread...\n");

	// Create the second thread.
	hThread = (HANDLE)_beginthreadex(NULL, 0, &SecondThreadFunc, NULL, 0, &threadID);

	// Wait until second thread terminates. If you comment out the line
	// below, Counter will not be correct because the thread has not
	// terminated, and Counter most likely has not been incremented to
	// 1000000 yet.
	WaitForSingleObject(hThread, INFINITE);
	printf("Counter should be 1000000; it is-> %d\n", Counter);
	// Destroy the thread object.
	CloseHandle(hThread);
}

#else

// crt_BEGTHRD.C
// compile with: /MT /D "_X86_" /c
// processor: x86
#include <windows.h>
#include <process.h>    /* _beginthread, _endthread */
#include <stddef.h>
#include <stdlib.h>
#include <conio.h>

void Bounce(void *ch);
void CheckKey(void *dummy);

/* GetRandom returns a random integer between min and max. */
#define GetRandom( min, max ) ((rand() % (int)(((max) + 1) - (min))) + (min))

BOOL repeat = TRUE;     /* Global repeat flag and video variable */
HANDLE hStdOut;         /* Handle for console window */
CONSOLE_SCREEN_BUFFER_INFO csbi;    /* Console information structure */

int main()
{
	TCHAR    ch = 'A';

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	/* Get display screen's text row and column information. */
	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	/* Launch CheckKey thread to check for terminating keystroke. */
	_beginthread(CheckKey, 0, NULL);

	/* Loop until CheckKey terminates program. */
	while (repeat)
	{
		/* On first loops, launch character threads. */
		_beginthread(Bounce, 0, (void *)(ch++));

		/* Wait one second between loops. */
		Sleep(1000L);
	}
}

/* CheckKey - Thread to wait for a keystroke, then clear repeat flag. */
void CheckKey(void *dummy)
{
	_getch();
	repeat = 0;    /* _endthread implied */

}

/* Bounce - Thread to create and and control a colored letter that moves
 * around on the screen.
 *
 * Params: ch - the letter to be moved
 */
void Bounce(void *ch)
{
	/* Generate letter and color attribute from thread argument. */
	TCHAR    blankcell = 0x20;
	TCHAR    blockcell = (TCHAR)ch;
	BOOL    first = TRUE;
	COORD   oldcoord, newcoord;
	DWORD   result;


	/* Seed random number generator and get initial location. */
	srand(_threadid);
	newcoord.X = GetRandom(0, csbi.dwSize.X - 1);
	newcoord.Y = GetRandom(0, csbi.dwSize.Y - 1);
	while (repeat)
	{
		/* Pause between loops. */
		Sleep(100L);

		/* Blank out our old position on the screen, and draw new letter. */
		if (first)
			first = FALSE;
		else
			WriteConsoleOutputCharacter(hStdOut, &blankcell, 1, oldcoord, &result);
		WriteConsoleOutputCharacter(hStdOut, &blockcell, 1, newcoord, &result);

		/* Increment the coordinate for next placement of the block. */
		oldcoord.X = newcoord.X;
		oldcoord.Y = newcoord.Y;
		newcoord.X += GetRandom(-1, 1);
		newcoord.Y += GetRandom(-1, 1);

		/* Correct placement (and beep) if about to go off the screen. */
		if (newcoord.X < 0)
			newcoord.X = 1;
		else if (newcoord.X == csbi.dwSize.X)
			newcoord.X = csbi.dwSize.X - 2;
		else if (newcoord.Y < 0)
			newcoord.Y = 1;
		else if (newcoord.Y == csbi.dwSize.Y)
			newcoord.Y = csbi.dwSize.Y - 2;

		/* If not at a screen border, continue, otherwise beep. */
		else
			continue;
		Beep(((TCHAR)ch - 'A') * 100, 175);
	}
	/* _endthread given to terminate */
	_endthread();
}

#endif


