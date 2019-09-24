/*
本文件主要描述了二进制格式的读写操作
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<string>

inline void EatLIne() { while (std::cin.get() != '\n') continue; }
struct SPlant
{
	//std::string name;          //经测试，用string或者常规数组都可以达到效果
	char name[20];
	double population;
	double g;
};

const std::string file = "planets.dat";

int main()
{
	using namespace std;
	SPlant pl;
	cout << fixed << right;

	//显示初始内容
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);             //以二进制形式打开;
	if (fin.is_open())
	{
		cout << "here are the current contents of the "
			<< file << " file:\n";
		while (fin.read((char *)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ":"
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}

	//增加新数据
	ofstream fout(file, ios_base::out | ios_base::app | ios::binary);
	if (!fout.is_open())
	{
		cerr << "can' t open " << file << " file to output:\n";
		exit(EXIT_FAILURE);
	}

	cout << "enter planet name (enter a blank line to quit):\n";
	//getline(cin, pl.name);
	cin.get(pl.name, 20); 
	while(pl.name[0]!='\0')
	//while (pl.name[0] != '\0')
	{
		//EatLIne();
		cout << "enter planetary population:";
		cin >> pl.population;
		cout << "enter planet's acceleration of gravity:";
		cin >> pl.g;
		EatLIne();                     //抽取剩下了的字符，为使用getline扫清障碍
		fout.write((char *)&pl, sizeof pl);
		cout << "Enter planet name(enter a blank line to quit):\n";
		//getline(cin, pl.name);
		cin.get(pl.name, 20);                
	}
	fout.close();

	//显示修正后的文件
	fin.clear();                      //清理所有的位状态
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.read((char *)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ":"
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}
	cout << "Done.\n";
	return 0;
}