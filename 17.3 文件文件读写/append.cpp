#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include <atlstr.h>


const char * file = "guestsNew22.txt";
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::ifstream;
	using std::ofstream;
	using std::cerr;
	using std::string;

	//��ԭʼ�ļ�
	std::wifstream fin;
	wchar_t ch;
	fin.open(file);
	if (fin.is_open())
	{
		cout << "here are the current contents of the " << file << " file:\n";
		while (fin.get(ch));
		fin.close();
	}

	std::wofstream fout(file, std::ios::out | std::ios::app);
	if (!fout.is_open())
	{
		cerr << "can not open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "enter guest names (enter a blank line to quit):\n";
	string name;
	while (getline(cin, name) && name.size() > 0)
	{
		fout << CString(CA2T(name.c_str()));
	}

	
	////��ԭʼ�ļ�
	//char ch;
	////��������������ֻ��3����1.����һ��ifstream����2.������ض��ļ�����������3.����ʹ��cinһ��ʹ������
	//ifstream fin;
	//fin.open(file);
	//if (fin.is_open())               //true if the file is open, false otherwise.
	//{
	//	cout << "Here are the current contents of the "
	//		<< file << " file:\n";
	//	while (fin.get(ch))
	//		cout << ch;
	//	fin.close();
	//}

	////���ļ�������������
	////�������������ֻ��3����1.����һ��ofstream����2.������ض��ļ�����������3.����ʹ��coutһ��ʹ������
	//ofstream fout(file, std::ios::out | std::ios::app);       //Ĭ�ϵĴ�ģʽΪ ios::out | ios::trunc���⽫ɾ���ļ���ԭ����
	//if (!fout.is_open())
	//{
	//	cerr << "can't open " << file << " file for output.\n";
	//	exit(EXIT_FAILURE);
	//}

	//cout << "enter guest names (enter a blank line to quit):\n";
	//string name;
	//while (getline(cin, name) && name.size() > 0)
	//{
	//	fout << name << endl;
	//}
	//fout.close();

	////��ʾ�޸ĺ���ļ�
	//fin.clear();                     //�������д����־
	//fin.open(file);
	//if (fin.is_open())
	//{
	//	cout << "here are the new contents of the "
	//		<< file << " file:\n";
	//	while (fin.get(ch))
	//		cout << ch;
	//	fin.close();
	//}
	//cout << "Done.\n";
	//return 0;
}