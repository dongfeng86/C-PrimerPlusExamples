
//���̱߳���
#include <stdio.h>
#include <process.h>
#include <windows.h>
int g_nCount;

//���̺߳���
unsigned int __stdcall ThreadFun(PVOID pM)
{
	g_nCount++;
	printf("�߳�ID��Ϊ%4d�����̱߳���%d\n", GetCurrentThreadId(), g_nCount);
	return 0;
}

//����������ν��������ʵ�������߳�ִ�еĺ�����
int main()
{
	printf("     ���̱߳��� \n");
	printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

	const int THREAD_NUM = 10;
	HANDLE handle[THREAD_NUM];

	g_nCount = 0;
	for (int i = 0; i < THREAD_NUM; i++)
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, NULL, 0, NULL);

	//Waits until one or all of the specified objects are in the signaled state or the time-out interval elapses.
	WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);
	return 0;
}