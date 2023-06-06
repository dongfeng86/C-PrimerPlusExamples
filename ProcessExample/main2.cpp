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
		char lmschar[255] = _T("名称");
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
	//根据进程ID,打开进程返回进程的句柄
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	//得到进程名
	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;
		//EnumProcessModules根据句柄获取实例，保存到hMod中
		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
		{
			//获取根据进程句柄获取进程名称 szProcessName
			GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
		}
	}
	//打印进程名和进程ID,其进程句柄为hProcess
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
	// 得到进程ID的列表
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;
	//列举所有进程的ID，返回到aProcesses数组中
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		return 0;
	//计算一共返回了多少个进程ID
	cProcesses = cbNeeded / sizeof(DWORD);
	//打印每个进程的名称和对应的ID
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

