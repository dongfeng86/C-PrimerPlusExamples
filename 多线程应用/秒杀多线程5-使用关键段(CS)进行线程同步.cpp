/*
函数功能：初始化
函数原型：void InitializeCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
函数说明：定义关键段变量后必须先初始化。

函数功能：销毁
函数原型：void DeleteCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
函数说明：用完之后记得销毁。

函数功能：进入关键区域
函数原型：void EnterCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
函数说明：系统保证各线程互斥的进入关键区域。

为了各个线程可以独占式的访问共享资源，每个线程需要通过调用EnterCriticalSection或TryEnterCriticalSection
函数请求关键段的所有权，然后执行那些访问保护资源的代码。
To enable mutually exclusive access to a shared resource, each thread calls the EnterCriticalSection
or TryEnterCriticalSection function to request ownership of the critical section before executing any 
section of code that accesses the protected resource.

EnterCriticalSection函数会一直阻塞，直到线程获取到了关键段的所有权。
EnterCriticalSection blocks until the thread can take ownership of the critical section.

函数功能：离开关关键区域
函数原型：void LeaveCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
*/

#include <stdio.h>
#include <process.h>
#include <windows.h>
long g_nNum;
unsigned int __stdcall Fun(void *pPM);
const int THREAD_NUM = 10;
//关键段变量声明
CRITICAL_SECTION  g_csThreadParameter, g_csThreadCode;

int main()
{
	printf("     经典线程同步 关键段\n");
	printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

	//关键段初始化
	InitializeCriticalSection(&g_csThreadParameter);
	InitializeCriticalSection(&g_csThreadCode);

	HANDLE  handle[THREAD_NUM];
	g_nNum = 0;
	int i = 0;
	while (i < THREAD_NUM)
	{
		/* 因此可以将关键段比作旅馆的房卡，调用EnterCriticalSection()即申请房卡，得到房卡后自己当然是可以多次进出房间的，
		在你调用LeaveCriticalSection()交出房卡之前，别人自然是无法进入该房间。回到这个经典线程同步问题上，主线程正是
		由于拥有“线程所有权”即房卡，所以它可以重复进入关键代码区域从而导致子线程在接收参数之前主线程就已经修改了这个参数。
		所以关键段可以用于线程间的互斥，但不可以用于同步。*/
		EnterCriticalSection(&g_csThreadParameter);//进入子线程序号关键区域
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, Fun, &i, 0, NULL);
		++i;
	}
	WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);

	DeleteCriticalSection(&g_csThreadCode);
	DeleteCriticalSection(&g_csThreadParameter);
	return 0;
}

unsigned int __stdcall Fun(void *pPM)
{
	int nThreadNum = *(int *)pPM;
	LeaveCriticalSection(&g_csThreadParameter);//离开子线程序号关键区域

	Sleep(50);//some work should to do

	//以下代码保证了各个子线程之间是互斥的，一个线程进入后，另外一个线程只能等着上一个线程释放CS的所有权为止
	EnterCriticalSection(&g_csThreadCode);//进入各子线程互斥区域
	g_nNum++;
	Sleep(0);//some work should to do
	printf("线程编号为%d  全局资源值为%d\n", nThreadNum, g_nNum);
	LeaveCriticalSection(&g_csThreadCode);//离开各子线程互斥区域
	return 0;
}