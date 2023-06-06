#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <Psapi.h>
#include <string.h>
#include <tchar.h>
#pragma comment ( lib, "Psapi.lib" )

typedef struct
{
	HWND hWnd;
	DWORD dwPid;
}WNDINFO;

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	WNDINFO* pInfo = (WNDINFO*)lParam;
	DWORD dwProcessId = 0;
	GetWindowThreadProcessId(hWnd, &dwProcessId);

	if (dwProcessId == pInfo->dwPid)
	{
		pInfo->hWnd = hWnd;
		return FALSE;
	}
	return TRUE;
}

HWND GetHwndByProcessId(DWORD dwProcessId)
{
	WNDINFO info = { 0 };
	info.hWnd = NULL;
	info.dwPid = dwProcessId;
	EnumWindows(EnumWindowsProc, (LPARAM)&info);
	return info.hWnd;
}