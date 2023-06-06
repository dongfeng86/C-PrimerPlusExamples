#include <windows.h>
#include <stdint.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <tchar.h>
#include <oleacc.h>
using namespace std;

typedef struct EnumHWndsArg
{
	std::vector<HWND> *vecHWnds;
	DWORD dwProcessId;
}EnumHWndsArg, *LPEnumHWndsArg;

void ReadF(char* str, char* buffer)
{
	HANDLE pfile;
	pfile = ::CreateFile(str, GENERIC_READ, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (pfile == INVALID_HANDLE_VALUE)
	{
		cout << "打开文件失败" << endl;;
		CloseHandle(pfile); // 一定注意在函数退出之前对句柄进行释放
		return;
	}
	DWORD filesize = GetFileSize(pfile, NULL);
	DWORD readsize;
	ReadFile(pfile, buffer, filesize, &readsize, NULL);
	buffer[filesize] = 0;
	CloseHandle(pfile); // 关闭句柄

	DeleteFile(str);
}
void WriteF(char* str, const char* buffer, int size)
{
	HANDLE pfile;
	pfile = ::CreateFile(str, GENERIC_WRITE | GENERIC_READ, 0,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN | FILE_FLAG_WRITE_THROUGH, NULL);
	if (pfile == INVALID_HANDLE_VALUE)
	{
		cout << "打开文件失败" << endl;;
		CloseHandle(pfile); // 一定注意在函数退出之前对句柄进行释放
		return;
	}
	DWORD readsize;
	WriteFile(pfile, buffer, size, &readsize, NULL);
	CloseHandle(pfile); // 关闭句柄
	DeleteFile(str);
}

HANDLE GetProcessHandleByID(int nID)//通过进程ID获取进程句柄
{
	return OpenProcess(PROCESS_ALL_ACCESS, FALSE, nID);
}

DWORD GetProcessIDByName(const char* pName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return NULL;
	}
	PROCESSENTRY32 pe = { sizeof(pe) };
	for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
		printf(pe.szExeFile);
		printf("\n");
		if (strcmp(pe.szExeFile, pName) == 0) {
			CloseHandle(hSnapshot);
			return pe.th32ProcessID;
		}
		//printf("%-6d %s\n", pe.th32ProcessID, pe.szExeFile);
	}
	CloseHandle(hSnapshot);
	return 0;
}

BOOL CALLBACK lpEnumFunc(HWND hwnd, LPARAM lParam)
{
	EnumHWndsArg *pArg = (LPEnumHWndsArg)lParam;
	DWORD  processId;

	//The GetWindowThreadProcessId function retrieves the identifier of the thread that created the specified window and, 
	//optionally, the identifier of the process that created the window. 
	GetWindowThreadProcessId(hwnd, &processId);
	if (processId == pArg->dwProcessId)
	{
		pArg->vecHWnds->push_back(hwnd);
		//printf("%p\n", hwnd);
	}
	return TRUE;
}

void GetHWndsByProcessID(DWORD processID, std::vector<HWND> &vecHWnds)
{
	EnumHWndsArg wi;
	wi.dwProcessId = processID;
	wi.vecHWnds = &vecHWnds;
	EnumWindows(lpEnumFunc, (LPARAM)&wi);
}

#define MAX_TITLE_LENGTH 512
#define MAX_CLASS_LENGTH 512
struct WindowInformation
{
public:
	HWND handle;
	HWND parent;
	HWND owner;
	LONG style;
	DWORD pid;  // process id
	DWORD tid;  // creator thread id
	char title[MAX_TITLE_LENGTH];
	char cls[MAX_CLASS_LENGTH];      // window class name.
};

void GetWindowInfo(HWND hWnd,WindowInformation& windInfo)
{
	windInfo.handle = hWnd;
	windInfo.parent = GetParent(hWnd);
	windInfo.owner = GetWindow(hWnd, GW_OWNER);
	windInfo.style = GetWindowLong(hWnd, GWL_STYLE);
	GetWindowText(hWnd, windInfo.title, MAX_TITLE_LENGTH);
	GetClassName(hWnd, windInfo.cls, MAX_CLASS_LENGTH);
	windInfo.tid = GetWindowThreadProcessId(hWnd, &windInfo.pid);
}

bool IsMainWindow(HWND hWnd)
{
	WindowInformation windInfo;
	GetWindowInfo(hWnd,windInfo);
	DWORD visibleStyle = WS_VISIBLE;
	bool result = strlen(windInfo.title) 
		&& (windInfo.style & visibleStyle)	
		&& !windInfo.owner;
	return result;
}


BOOL CALLBACK NextChildWindowHandle(HWND hWnd, LPARAM lParam)
{
	WindowInformation* pWinInfo = (WindowInformation*)lParam;
	char psz[MAX_CLASS_LENGTH] = { 0 };
	GetClassName(hWnd, psz, MAX_CLASS_LENGTH);
	if (strcmp(psz, "EXCEL7") == 0)
	{
		GetWindowInfo(hWnd, *pWinInfo);
		return FALSE;
	}
	return TRUE;

}

//The caller is responsible for release memory
LPDISPATCH ExcelComFromMainWindowHandle(HWND hwndMainWin)
{
	//找到EXCEL的主窗口
	WindowInformation WinInfo;
	EnumChildWindows(hwndMainWin, NextChildWindowHandle, (LPARAM)&WinInfo);
	if (strcmp(WinInfo.cls, "EXCEL7") == 0)
	{
		int  ret;
		printf("%p		--->excel Main Wnd\n", WinInfo.handle);
		//GUID idDispatch{ 0x00024500,0x0000 ,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
		GUID idDispatch{ 0x00020400,0x0000 ,0x0000,{ 0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46 } };
		void* pVoid = NULL;
		if (S_OK == (ret = ::AccessibleObjectFromWindow(WinInfo.handle, OBJID_NATIVEOM, idDispatch, &pVoid)))
			return (LPDISPATCH)pVoid;
	}
	return NULL;
}


#define PID_NUMBER 256
int main()
{
	CoInitialize(NULL);
	DWORD pid = GetProcessIDByName("EXCEL.EXE");
	printf("pid = %u\n", pid);
	char strPid[PID_NUMBER];
	sprintf_s(strPid, PID_NUMBER, "%u", pid);
	char fileName[PID_NUMBER] = "pid.cfg";
	char snPid[PID_NUMBER] = {};
	ReadF(fileName, snPid);
	if (strncmp(snPid, "", strlen(snPid)) == 0) {
		WriteF(fileName, strPid, strlen(strPid));
	}
	else {
		ReadF(fileName, snPid);
	}

	if (pid != 0)
	{
		std::vector<HWND> vecHWnds;
		GetHWndsByProcessID(pid, vecHWnds);
		//判断是否为主窗口
		printf("vecHWnds.size() = %u\n", vecHWnds.size());
		for (const HWND &hwndMainWin : vecHWnds)
		{
			if(IsMainWindow(hwndMainWin))
			{
				printf("%p --->Main Wnd\n", hwndMainWin);
			}
		}
	}
	char szPid[PID_NUMBER] = "";
	ReadF(fileName, szPid);
	printf("[ReadF] szPid:%s\n", szPid);
	getchar();

	CoUninitialize();
	return S_OK;
}