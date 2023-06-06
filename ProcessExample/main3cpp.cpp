int ProcessUtilities::lookupProcesses(const std::string &procName, std::vector<PROCESSENTRY32> &pes)
{
	string lowProcName = procName;
	StringUtility::lower(lowProcName);
	vector<PROCESSENTRY32> totalEntries;
	int errorCode = snapshotProcesses(totalEntries);
	if (errorCode == NO_ERROR)
	{
		pes.clear();
		for (const PROCESSENTRY32& entry : totalEntries)
		{
			string execName = entry.szExeFile;
			StringUtility::lower(execName);
			if (lowProcName.compare(execName) == 0)
			{
				pes.push_back(entry);
			}
		}
	}
	return errorCode;
}

int ProcessUtilities::getPids(const std::string &procName, std::vector<DWORD> &pids)
{
	vector<PROCESSENTRY32> entries;
	int errorCode = lookupProcesses(procName, entries);
	if (errorCode == NO_ERROR)
	{
		for (PROCESSENTRY32 entry : entries)
		{
			pids.push_back(entry.th32ProcessID);
		}
	}
	return errorCode;
}

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

public:
	std::string& toString(int level = 0);

private:
	std::string text;
};

struct WindowTree
{
public:
	WindowInformation info;
	std::vector<WindowTree> children;

public:
	std::string& toString(int level = 0);

private:
	std::string text;
};

void getWindowInformation(const HWND hWnd, WindowInformation& windInfo)
{
	windInfo.handle = hWnd;
	windInfo.parent = GetParent(hWnd);
	windInfo.owner = GetWindow(hWnd, GW_OWNER);
	windInfo.style = GetWindowLong(hWnd, GWL_STYLE);
	GetWindowText(hWnd, windInfo.title, WindowUtilities::MAX_TITLE_LENGTH);
	GetClassName(hWnd, windInfo.cls, WindowUtilities::MAX_CLASS_LENGTH);
	windInfo.tid = GetWindowThreadProcessId(hWnd, &windInfo.pid);
}

bool enumWindowsProc(const HWND hWnd, LPARAM lParam)
{
	WindowUtilities::WindowTree thisWindow;
	getWindowInformation(hWnd, thisWindow.info);
	WindowUtilities::WindowTree *winTreeRoot = (WindowUtilities::WindowTree *)lParam;
	EnumChildWindows(hWnd, (WNDENUMPROC)enumChildProc, (LPARAM)(&thisWindow));
	winTreeRoot->children.push_back(thisWindow);

	return true;
}

int WindowUtilities::getWindows(WindowTree& windTree)
{
	getWindowInformation(GetDesktopWindow(), windTree.info);
	EnumWindows((WNDENUMPROC)enumWindowsProc, (LPARAM)(&windTree));

	return NO_ERROR;
}

int WindowUtilities::filterWindows(WindowUtilities::WindowTree& totalTree, DWORD pid, vector<WindowUtilities::WindowTree>& windTree)
{
	if (totalTree.info.pid == pid)
	{
		windTree.push_back(totalTree);
	}
	else
	{
		for (WindowUtilities::WindowTree wt : totalTree.children)
		{
			filterWindows(wt, pid, windTree);
		}
	}

	return windTree.size();
}

int WindowUtilities::getWindows(DWORD pid, vector<WindowUtilities::WindowTree>& windTree)
{
	WindowTree totalTree;
	getWindows(totalTree);
	filterWindows(totalTree, pid, windTree);
	return 0;
}

int WindowUtilities::getWindows(DWORD pid, std::vector<HWND> &hWnds)
{
	vector<WindowUtilities::WindowTree> wts;
	getWindows(pid, wts);
	hWnds.clear();
	for (WindowUtilities::WindowTree& wt : wts)
	{
		hWnds.push_back(wt.info.handle);
	}
	return 0;
}

bool WindowUtilities::isMainWindow(HWND hWnd)
{
	WindowInformation windInfo = getWindowInformation(hWnd);
	DWORD visibleStyle = WS_VISIBLE;
	bool result = (((string(windInfo.title).length() != 0) && (windInfo.style & (visibleStyle)) != 0) && (windInfo.owner == nullptr)) ? true : false;
	return result;
}

int WindowUtilities::getMainWindows(DWORD pid, std::vector<HWND> &hWnds)
{
	vector<HWND> totalWindows;
	getWindows(pid, totalWindows);
	for (HWND hWnd : totalWindows)
	{
		if (isMainWindow(hWnd))
		{
			hWnds.push_back(hWnd);
		}
	}
	return 0;
}