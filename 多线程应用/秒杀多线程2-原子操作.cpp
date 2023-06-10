
#include <stdio.h>
#include <windows.h>

volatile long g_nLoginCount; //登录次数
unsigned int __stdcall Fun(void *pPM); //线程函数
const DWORD THREAD_NUM = 50;//启动线程数

/*注意，后缀++操作在汇编层面是由3条指令构成的，这样由于线程执行的并发性，
很可能线程A执行到第二条指令时，线程B开始执行，线程B将原来的值又写入寄存器eax中，
这样线程A所主要计算的值就被线程B修改了。
这样执行下来，结果是不可预知的——可能会出现50，可能小于50。*/
DWORD WINAPI ThreadFun(void *pPM)
{
	Sleep(100);//some work should to do

	/* 在多线程环境中对一个变量进行读写时，我们需要有一种方法能够保证对一个值的递增操作是
	原子操作——即不可打断性，一个线程在执行原子操作时，其它线程必须等待它完成之后才能开始
	执行该原子操作。Windows系统为我们提供了一些以Interlocked开头的函数来完成这一任务
	（下文将这些函数称为Interlocked系列函数）。	*/
	//g_nLoginCount++;	//这种方式是线程不安全的
	InterlockedIncrement((LPLONG)&g_nLoginCount);
	Sleep(50);
	return 0;
}

int main()
{
	printf("     原子操作 Interlocked系列函数的使用\n");
	printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

	//重复20次以便观察多线程访问同一资源时导致的冲突
	int num = 20;
	while (num--)
	{
		g_nLoginCount = 0;
		int i;
		HANDLE  handle[THREAD_NUM];
		for (i = 0; i < THREAD_NUM; i++)
			handle[i] = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);
		WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);
		printf("有%d个用户登录后记录结果是%d\n", THREAD_NUM, g_nLoginCount);
	}
	return 0;
}