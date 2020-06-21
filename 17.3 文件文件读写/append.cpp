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

	//打开原始文件
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

	
	////打开原始文件
	//char ch;
	////创建输入流对象。只有3步：1.创建一个ifstream对象；2.将其和特定文件关联起来；3.就像使用cin一样使用它。
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

	////在文件中增加新内容
	////创建输出流对象。只有3步：1.创建一个ofstream对象；2.将其和特定文件关联起来；3.就像使用cout一样使用它。
	//ofstream fout(file, std::ios::out | std::ios::app);       //默认的打开模式为 ios::out | ios::trunc，这将删除文件的原内容
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

	////显示修改后的文件
	//fin.clear();                     //消除所有错误标志
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