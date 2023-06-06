//#include"String.h"
//#include<iostream>
//#include<STDDEF.H >
//#include<climits>
//
//int main()
//{
//	CString sName;
//	char szArr[80] = "��ð���";               //vsִ���ַ���֧��unicode
//	char ��[6] = "��";                         //VSԴ�ַ���֧��unicode
//	std::cout << ��;
//
//	std::cout << szArr << std::endl;
//	std::cout << "ÿ���ַ�ռ���ֽ���Ŀ��" << sizeof(char) << std::endl;;
//	std::cout << "ÿ������ռ���ֽ���Ŀ��" << sizeof(int) << std::endl;;
//
//	std::cout << "������һ�����֣�\n";
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
	char szName[] = "����";
	cout << "��strlen������\"����\"���ֽ����ǣ�" << strlen(szName) << endl;
	wchar_t szTemp[] = L"nihao";
	cout << "��wcslen()������L\"nihao\"���ֽ����ǣ�" << wcslen(szTemp) << endl;
	char szNew[] = "nihao";
	cout << "��strlen()������\"nihao\"���ֽ����ǣ�" << strlen(szNew) << endl;

	return 0;
}