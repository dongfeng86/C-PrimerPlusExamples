#include <windows.h>
#include <stdint.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <tchar.h>
#include <oleacc.h>

#define MAX_TITLE_LENGTH 256
#define MAX_CLASS_LENGTH 256

typedef struct EnumHWndsArg
{
	std::vector<HWND> *vecHWnds;
	DWORD dwProcessId;
}EnumHWndsArg, *LPEnumHWndsArg;

struct SWindowInformation
{
public:
	HWND handle;
	HWND parent;
	HWND owner;
	LONG style;
	DWORD pid;  // process id
	DWORD tid;  // creator thread id
	TCHAR title[MAX_TITLE_LENGTH];	//Window title
	TCHAR cls[MAX_CLASS_LENGTH];	// window class name.
};

DWORD GetProcessIDByName(const TCHAR* pName)
{
	HANDLE hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return NULL;
	}
	PROCESSENTRY32 pe = { sizeof(pe) };
	for (BOOL ret = ::Process32First(hSnapshot, &pe); ret; ret = ::Process32Next(hSnapshot, &pe)) 
	{
		if (_tcscmp(pe.szExeFile, pName) == 0) {
			::CloseHandle(hSnapshot);
			return pe.th32ProcessID;
		}
	}
	::CloseHandle(hSnapshot);
	return 0;
}

BOOL CALLBACK lpEnumFunc(HWND hwnd, LPARAM lParam)
{
	EnumHWndsArg *pArg = (LPEnumHWndsArg)lParam;
	DWORD  processId;

	//The GetWindowThreadProcessId function retrieves the identifier of the thread that created the specified window and, 
	//optionally, the identifier of the process that created the window. 
	::GetWindowThreadProcessId(hwnd, &processId);
	if (processId == pArg->dwProcessId)
		pArg->vecHWnds->push_back(hwnd);

	return TRUE;
}

void GetHWndsByProcessID(DWORD processID, std::vector<HWND> &vecHWnds)
{
	EnumHWndsArg wi;
	wi.dwProcessId = processID;
	wi.vecHWnds = &vecHWnds;
	::EnumWindows(lpEnumFunc, (LPARAM)&wi);
}

void GetWindowInfo(HWND hWnd, SWindowInformation& windInfo)
{
	windInfo.handle = hWnd;
	windInfo.parent = GetParent(hWnd);
	windInfo.owner = GetWindow(hWnd, GW_OWNER);
	windInfo.style = GetWindowLong(hWnd, GWL_STYLE);
	::GetWindowText(hWnd, windInfo.title, MAX_TITLE_LENGTH);
	::GetClassName(hWnd, windInfo.cls, MAX_CLASS_LENGTH);
	windInfo.tid = ::GetWindowThreadProcessId(hWnd, &windInfo.pid);
}

bool IsMainWindow(HWND hWnd)
{
	SWindowInformation windInfo;
	GetWindowInfo(hWnd, windInfo);
	DWORD visibleStyle = WS_VISIBLE;
	bool result = _tcslen(windInfo.title)
		&& (windInfo.style & visibleStyle)
		&& !windInfo.owner;
	return result;
}


BOOL CALLBACK NextChildWindowHandle(HWND hWnd, LPARAM lParam)
{
	SWindowInformation* pWinInfo = (SWindowInformation*)lParam;
	TCHAR psz[MAX_CLASS_LENGTH] = { 0 };
	::GetClassName(hWnd, psz, MAX_CLASS_LENGTH);
	if (_tcscmp(psz, _T("EXCEL7")) == 0)
	{
		GetWindowInfo(hWnd, *pWinInfo);
		return FALSE;
	}
	return TRUE;

}

//The caller is responsible for release memory
LPDISPATCH ExcelComFromMainWindowHandle2(HWND hwndMainWin)
{
	//找到EXCEL的主窗口
	SWindowInformation WinInfo;
	::EnumChildWindows(hwndMainWin, NextChildWindowHandle, (LPARAM)&WinInfo);
	if (_tcscmp(WinInfo.cls, _T("EXCEL7")) == 0)
	{
		int  ret;
		//GUID idDispatch{ 0x00024500,0x0000 ,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
		GUID idDispatch{ 0x00020400,0x0000 ,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
		void* pVoid = NULL;
		if (S_OK == (ret = ::AccessibleObjectFromWindow(WinInfo.handle, OBJID_NATIVEOM, idDispatch, &pVoid)))
			return (LPDISPATCH)pVoid;
	}
	return NULL;
}

LPDISPATCH ExcelComFromMainWindowHandle(HWND hwndMainWin)
{

	//找到EXCEL的主窗口
	SWindowInformation WinInfo;
	::EnumChildWindows(hwndMainWin, NextChildWindowHandle, (LPARAM)&WinInfo);
	if (_tcscmp(WinInfo.cls, _T("EXCEL7")) == 0)
	{
		int  ret;
		//GUID idDispatch{ 0x00024500,0x0000 ,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
		GUID idDispatch{ 0x00020400,0x0000 ,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
		void* pVoid = NULL;
		if (S_OK == (ret = ::AccessibleObjectFromWindow(WinInfo.handle, OBJID_NATIVEOM, idDispatch, &pVoid)))
			return (LPDISPATCH)pVoid;
	}
	return NULL;
}

int main()
{
	CoInitialize(NULL);
	DWORD pid = GetProcessIDByName(_T("EXCEL.EXE"));
	_tprintf(_T("pid = %u\n"), pid);

	CLSID clsID;
	CLSIDFromProgID(_T("Excel.Application"), &clsID);
	LPUNKNOWN pUnkown = NULL;
	if (S_OK == ::GetActiveObject(clsID, NULL, &pUnkown))
		pUnkown->Release();


	void* pUnkown2;
	GUID idDispatch{ 0x00020400,0x0000 ,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
	AccessibleObjectFromWindow((HWND)0x0006136A, OBJID_NATIVEOM, idDispatch, &pUnkown2);
	void* pUnkown3;
	((LPDISPATCH)pUnkown2)->QueryInterface(IID_IUnknown, &pUnkown3);


	if (pid != 0)
	{
		std::vector<HWND> vecHWnds;
		GetHWndsByProcessID(pid, vecHWnds);
		//判断是否为主窗口
		_tprintf(_T("vecHWnds.size() = %u\n"), vecHWnds.size());

		for (const HWND &hwndMainWin : vecHWnds)
		{

			int  ret;
			//GUID idDispatch{ 0x00024500,0x0000 ,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
			GUID idDispatch{ 0x00020400,0x0000 ,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
			void* pVoid = NULL;
			if (S_OK == (ret = ::AccessibleObjectFromWindow(hwndMainWin, OBJID_NATIVEOM, idDispatch, &pVoid)))
			{
				LPDISPATCH pDis = (LPDISPATCH)pVoid;
			}
		}

		for (const HWND &hwndMainWin : vecHWnds)
		{
			if (IsMainWindow(hwndMainWin))
			{
				_tprintf(_T("%p --->Main Wnd\n"), hwndMainWin);
				LPDISPATCH pDispath = NULL;
				pDispath = ExcelComFromMainWindowHandle(hwndMainWin);
				if (pDispath)
				{
					//_tprintf不支持中文
					_tprintf(_T("		succeed to find excel com interface\n"));
					pDispath->Release();
				}
			}
		}
	}
	getchar();

	CoUninitialize();
}