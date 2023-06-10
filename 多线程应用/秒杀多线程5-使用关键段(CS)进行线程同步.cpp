/*
�������ܣ���ʼ��
����ԭ�ͣ�void InitializeCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
����˵��������ؼ��α���������ȳ�ʼ����

�������ܣ�����
����ԭ�ͣ�void DeleteCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
����˵��������֮��ǵ����١�

�������ܣ�����ؼ�����
����ԭ�ͣ�void EnterCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
����˵����ϵͳ��֤���̻߳���Ľ���ؼ�����

Ϊ�˸����߳̿��Զ�ռʽ�ķ��ʹ�����Դ��ÿ���߳���Ҫͨ������EnterCriticalSection��TryEnterCriticalSection
��������ؼ��ε�����Ȩ��Ȼ��ִ����Щ���ʱ�����Դ�Ĵ��롣
To enable mutually exclusive access to a shared resource, each thread calls the EnterCriticalSection
or TryEnterCriticalSection function to request ownership of the critical section before executing any 
section of code that accesses the protected resource.

EnterCriticalSection������һֱ������ֱ���̻߳�ȡ���˹ؼ��ε�����Ȩ��
EnterCriticalSection blocks until the thread can take ownership of the critical section.

�������ܣ��뿪�عؼ�����
����ԭ�ͣ�void LeaveCriticalSection(LPCRITICAL_SECTIONlpCriticalSection);
*/

#include <stdio.h>
#include <process.h>
#include <windows.h>
long g_nNum;
unsigned int __stdcall Fun(void *pPM);
const int THREAD_NUM = 10;
//�ؼ��α�������
CRITICAL_SECTION  g_csThreadParameter, g_csThreadCode;

int main()
{
	printf("     �����߳�ͬ�� �ؼ���\n");
	printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

	//�ؼ��γ�ʼ��
	InitializeCriticalSection(&g_csThreadParameter);
	InitializeCriticalSection(&g_csThreadCode);

	HANDLE  handle[THREAD_NUM];
	g_nNum = 0;
	int i = 0;
	while (i < THREAD_NUM)
	{
		/* ��˿��Խ��ؼ��α����ùݵķ���������EnterCriticalSection()�����뷿�����õ��������Լ���Ȼ�ǿ��Զ�ν�������ģ�
		�������LeaveCriticalSection()��������֮ǰ��������Ȼ���޷�����÷��䡣�ص���������߳�ͬ�������ϣ����߳�����
		����ӵ�С��߳�����Ȩ���������������������ظ�����ؼ���������Ӷ��������߳��ڽ��ղ���֮ǰ���߳̾��Ѿ��޸������������
		���Թؼ��ο��������̼߳�Ļ��⣬������������ͬ����*/
		EnterCriticalSection(&g_csThreadParameter);//�������߳���Źؼ�����
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
	LeaveCriticalSection(&g_csThreadParameter);//�뿪���߳���Źؼ�����

	Sleep(50);//some work should to do

	//���´��뱣֤�˸������߳�֮���ǻ���ģ�һ���߳̽��������һ���߳�ֻ�ܵ�����һ���߳��ͷ�CS������ȨΪֹ
	EnterCriticalSection(&g_csThreadCode);//��������̻߳�������
	g_nNum++;
	Sleep(0);//some work should to do
	printf("�̱߳��Ϊ%d  ȫ����ԴֵΪ%d\n", nThreadNum, g_nNum);
	LeaveCriticalSection(&g_csThreadCode);//�뿪�����̻߳�������
	return 0;
}