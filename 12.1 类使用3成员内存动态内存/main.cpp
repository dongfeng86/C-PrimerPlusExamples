//#include"String.h"
//#include<iostream>
//#include<STDDEF.H >
//#include<climits>
//
//int main()
//{
//	CString sName;
//	char szArr[80] = "你好啊。";               //vs执行字符集支持unicode
//	char 我[6] = "你";                         //VS源字符集支持unicode
//	std::cout << 我;
//
//	std::cout << szArr << std::endl;
//	std::cout << "每个字符占用字节数目：" << sizeof(char) << std::endl;;
//	std::cout << "每个整形占用字节数目：" << sizeof(int) << std::endl;;
//
//	std::cout << "请输入一个名字：\n";
//	std::cin >> sName;
//	std::cout << sName << std::endl;
//	return 0;
//}

#include<iostream>
#include"String.h"
const int ArSize = 4;
const int MaxLen = 81;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	String name;
	cout << "Hi,what is your name?\n>>";
	cin >> name;

	name = "hello";
	String sNew = name;
	name = "MyHello";
	sNew = name;

	cout << name << ",please enter up to " << ArSize
		<< " short sayings <empty line to quit>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;

	if (total > 0)
	{
		cout << "here are your sayings:\n";
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ":" << endl;

		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}
		cout << "Shortest saying:\n" << sayings[shortest] << endl;
		cout << "First alphabetically :\n" << sayings[first] << endl;
		cout << "This program used " << String::HowMany()
			<< " string objects.Bye\n";
	}
	else
		cout << "No input!Bye.\n";


	cout << "now,let us see another problem,about a string's bytes\n";
	char szName[] = "东风";
	cout << "用strlen函数，\"东风\"的字节数是：" << strlen(szName) << endl;
	wchar_t szTemp[] = L"nihao";
	cout << "用wcslen()函数，L\"nihao\"的字节数是：" << wcslen(szTemp) << endl;
	char szNew[] = "nihao";
	cout << "用strlen()函数，\"nihao\"的字节数是：" << strlen(szNew) << endl;

	return 0;
}