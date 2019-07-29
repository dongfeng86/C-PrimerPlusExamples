//#include<iostream>
//#include<atlstr.h>

#include <iostream>
#include <stdlib.h>
#include <string>

#include "atlbase.h"
#include "atlstr.h"
#include "comutil.h"
//
//using namespace std;
//using namespace System;



using std::wcout;
using std::wcin;
using std::endl;
using std::cout;
using std::cin;

int main()
{
	CString s1 = _T("This ");                       // Cascading concatenation
	s1 += _T("is a ");
	CString s2 = _T("test");
	CString message = s1 + _T("big ") + s2;      	// Message contains "This is a big test".
	wcout << (const wchar_t*)message<<endl;               //注意，这个输出必须要进行显示转换，不然会出错
	wcout << (LPCTSTR)message << endl;


														  // Create and display a C style string, and then use it 
														  // to create different kinds of strings.
	char *orig = "Hello, World!";
	cout << orig << " (char *)" << endl;

	// newsize describes the length of the 
	// wchar_t string called wcstring in terms of the number 
	// of wide characters, not the number of bytes.
	size_t newsize = strlen(orig) + 1;

	// The following creates a buffer large enough to contain 
	// the exact number of characters in the original string
	// in the new format. If you want to add more characters
	// to the end of the string, increase the value of newsize
	// to increase the size of the buffer.
	wchar_t * wcstring = new wchar_t[newsize];

	// Convert char* string to a wchar_t* string.
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, wcstring, newsize, orig, _TRUNCATE);
	// Display the result and indicate the type of string that it is.
	wcout << wcstring << _T(" (wchar_t *)") << ";转化后的字符数是：" <<convertedChars<< endl;

	//// Convert the C style string to a _bstr_t string.
	//_bstr_t bstrt(orig);
	//// Append the type of string to the new string
	//// and then display the result.
	//bstrt += " (_bstr_t)";
	//cout << bstrt << endl;

	//// Convert the C style string to a CComBSTR string.
	//CComBSTR ccombstr(orig);
	//if (ccombstr.Append(_T(" (CComBSTR)")) == S_OK)
	//{
	//	CW2A printstr(ccombstr);
	//	cout << printstr << endl;
	//}

	// Convert the C style string to a CstringA and display it.
	CStringA cstringa(orig);
	cstringa += " (CStringA)";
	cout << cstringa << endl;

	// Convert the C style string to a CStringW and display it.
	CStringW cstring(orig);
	cstring += " (CStringW)";
	// To display a CStringW correctly, use wcout and cast cstring
	// to (LPCTSTR).
	wcout << (LPCTSTR)cstring << endl;

	//convert the c style string to a Csting and display it
	CString strTemp(orig);
	strTemp += _T(" (CString)");
	wcout << (LPCTSTR)strTemp << endl;

	//输出一句带汉字的CString对象总是出现问题
	////输入一句话到CSting当中
	//cout <<"请输入一句话\n";
	//std::string sTemp2;
	//std::getline(cin, sTemp2);
	//cout << "这是用string对象输出的：" << sTemp2 << endl;
	////CString sWtemp(sTemp2.c_str());
	//CString sWtemp("hahahah哈哈哈");
	//wcout << "这是用CString对象输出的：";
	////wcout << (LPCTSTR)sWtemp << endl;


	// Convert the C style string to a basic_string and display it.
	std::string basicstring(orig);
	basicstring += " (basic_string)";
	cout << basicstring << endl;


	//// Convert the C style string to a System::String and display it.
	//String ^systemstring = gcnew String(orig);
	//systemstring += " (System::String)";
	//Console::WriteLine("{0}", systemstring);
	//delete systemstring;


}

