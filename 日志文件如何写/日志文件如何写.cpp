// 日志文件如何写.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


DWORD  WriteErrLog(CString strError)
{
	DWORD nWrite = 0, bytesWritten;
	HANDLE hFile;
	BOOL res;
	CString strErrorLog, strTime, strLogName;

	SYSTEMTIME dt;//错误信息 +日期
	GetLocalTime(&dt);
	strTime.Format("  %04d/%02d/%02d %02d:%02d:%02d\r\n", dt.wYear, dt.wMonth, dt.wDay, dt.wHour, dt.wMinute, dt.wSecond);
	TCHAR tstrCurrentPath[MAX_PATH];
	TCHAR g_pInfPath[MAX_PATH];
	memset(tstrCurrentPath, 0, MAX_PATH);
	memset(g_pInfPath, 0, MAX_PATH);
	//Get
	GetCurrentDirectory(MAX_PATH, tstrCurrentPath);
	CString strPath;
	strPath.Format(_T("%s"), tstrCurrentPath);
	strcpy(g_pInfPath, tstrCurrentPath);
	strcat(g_pInfPath, _T("\\错误日志.ini"));
	strLogName = g_pInfPath;
	hFile = CreateFile(strLogName, GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		DWORD lDistance = 0;
		DWORD dwPtr = SetFilePointer(hFile, lDistance, NULL, FILE_END);
		if (INVALID_SET_FILE_POINTER == dwPtr)
		{
			CloseHandle(hFile);
			return -1;
		}


		strErrorLog = strError + strTime;
		DWORD lengh = strErrorLog.GetLength();
		res = WriteFile(hFile, strErrorLog, lengh * sizeof(WCHAR), &nWrite, NULL);

	}
	else if (0x0 == GetLastError())
	{
		//LPCVOID
		BYTE   head[2];
		head[0] = 0xff;
		head[1] = 0xfe;

		//Unicode   格式文本，需要写入文件头两个字节　0xff   0xfe   
		WriteFile(hFile, (BYTE*)head, 2, &bytesWritten, NULL);
		//再写入内容    
		DWORD lDistance = 2;
		DWORD dwPtr = SetFilePointer(hFile, lDistance, NULL, FILE_BEGIN);
		if (INVALID_SET_FILE_POINTER == dwPtr)
		{
			CloseHandle(hFile);
			return -1;
		}

		strErrorLog = strError + strTime;
		DWORD lengh = strErrorLog.GetLength();
		res = WriteFile(hFile, strErrorLog, lengh * sizeof(WCHAR), &nWrite, NULL);
	}
	CloseHandle(hFile);
	return (DWORD)res;
}