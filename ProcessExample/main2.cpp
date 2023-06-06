//#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <Psapi.h>
#include <string.h>
#include <tchar.h>
#pragma comment ( lib, "Psapi.lib" )

HWND lmshwnd;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, DWORD lParam)
{
	DWORD mpid;
	GetWindowThreadProcessId(hwnd, &mpid);

	if (mpid == lParam)
	{
		int i = GetWindowTextLength(hwnd);
		char szhello[255];
		char lmschar[255] = _T("����");
		GetWindowText(hwnd, szhello, i + 1);
		if (strstr(szhello, lmschar))
		{
			printf("%s\n", szhello);
			lmshwnd = hwnd;
		}

	}
	return TRUE;
}



void PrintProcessNameAndID(DWORD processID)
{
	TCHAR szProcessName[MAX_PATH] = TEXT("unknow");
	//���ݽ���ID,�򿪽��̷��ؽ��̵ľ��
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	//�õ�������
	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;
		//EnumProcessModules���ݾ����ȡʵ�������浽hMod��
		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
		{
			//��ȡ���ݽ��̾����ȡ�������� szProcessName
			GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
		}
	}
	//��ӡ�������ͽ���ID,����̾��ΪhProcess
	TCHAR *lmsname = TEXT("LMSVirtualLab.EXE");
	if (!strcmp(szProcessName, lmsname))
	{
		_tprintf(TEXT("%s  (PID: %x)\n"), szProcessName, processID);
		EnumWindows((WNDENUMPROC)EnumWindowsProc, processID);
		//HDESK hDesk=OpenDesktop(_T(""),0,FALSE,DESKTOP_ENUMERATE);  
		//EnumDesktopWindows(hDesk,(WNDENUMPROC)EnumWindowsProc,processID);
	}

	CloseHandle(hProcess);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// �õ�����ID���б�
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;
	//�о����н��̵�ID�����ص�aProcesses������
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		return 0;
	//����һ�������˶��ٸ�����ID
	cProcesses = cbNeeded / sizeof(DWORD);
	//��ӡÿ�����̵����ƺͶ�Ӧ��ID
	for (i = 0; i < cProcesses; i++)
	{
		if (aProcesses[i] != 0)
		{
			PrintProcessNameAndID(aProcesses[i]);
		}
	}
	printf("%x\n", lmshwnd);
	ShowWindow(lmshwnd, SW_MAXIMIZE);
	return 0;
}

