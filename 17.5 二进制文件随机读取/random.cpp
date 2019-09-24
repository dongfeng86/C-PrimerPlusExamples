/*
本文件主要展示了文件随机访问的应用。随机访问的关键是理解seekp()和seekg()两个函数
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
const int LIM = 20;
struct planet
{
	char name[20];
	double population;
	double g;
};

const char * file = "planets.dat";
inline void Eatline() { while (std::cin.get() != '\n') continue; }

int main()
{
	using namespace std;
	planet pl;
	cout << fixed;

	//下面用读写模式打开文档，显示其初始内容
	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if (finout.is_open())
	{
		//将输入指针定位到文件开始的地方，注意，在这种文件流模式下，输入和输出指针实际上是一样的
		finout.seekg(0);               
		cout << "Here are the current contents of the"
			<< file << " file:\n";
		while (finout.read((char *)&pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		if (finout.eof())
			finout.clear();
		else
		{
			cerr << "Error in reading " << file << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " could not be opened -- bye.\n";
		exit(EXIT_FAILURE);
	}

	//更改一个条目
	cout << "Enter the record number you wish to change:";
	long rec;
	cin >> rec;
	Eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "invalid record number -- bye\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof pl;           //计算文件指针的偏移量
	finout.seekg(place);                         //将输入指针放置到place这个位置
	if (finout.fail())
	{
		cerr << "Error on attempt seek\n";
		exit(EXIT_FAILURE);
	}

	finout.read((char *)& pl, sizeof pl);         //开始在place这个位置读取，注意，随着读取的进行，指针（输入/输出）一直在移动
	cout << "your selection:\n";
	cout << rec << ":" << setw(LIM) << pl.name << ":"
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
		finout.clear();                  //清除eof 标志

	cout << "Enter planet name: ";
	cin.get(pl.name, LIM);
	//Eatline();
	cout << "enter planetary population:";
	cin >> pl.population;
	cout << "enter planet's acceleration of gravity:";
	cin >> pl.g;
	finout.seekp(place);                         //将输出指针放置到place这个位置
	finout.write((char *)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "Error on attemped write\n";
		exit(EXIT_FAILURE);
	}

	//show revised file
	ct = 0;
	finout.seekg(0);                             //将输入指针放置到初始位置
	cout << "Here are the new contents of the " << file
		<< " file:\n";
	while (finout.read((char *)&pl, sizeof pl))
	{
		cout << ct++ << ": " << setw(LIM) << pl.name << ":"
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "Done.\n";
	return 0;
}