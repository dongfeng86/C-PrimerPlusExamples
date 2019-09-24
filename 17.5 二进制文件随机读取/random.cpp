/*
���ļ���Ҫչʾ���ļ�������ʵ�Ӧ�á�������ʵĹؼ������seekp()��seekg()��������
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

	//�����ö�дģʽ���ĵ�����ʾ���ʼ����
	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if (finout.is_open())
	{
		//������ָ�붨λ���ļ���ʼ�ĵط���ע�⣬�������ļ���ģʽ�£���������ָ��ʵ������һ����
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

	//����һ����Ŀ
	cout << "Enter the record number you wish to change:";
	long rec;
	cin >> rec;
	Eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "invalid record number -- bye\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof pl;           //�����ļ�ָ���ƫ����
	finout.seekg(place);                         //������ָ����õ�place���λ��
	if (finout.fail())
	{
		cerr << "Error on attempt seek\n";
		exit(EXIT_FAILURE);
	}

	finout.read((char *)& pl, sizeof pl);         //��ʼ��place���λ�ö�ȡ��ע�⣬���Ŷ�ȡ�Ľ��У�ָ�루����/�����һֱ���ƶ�
	cout << "your selection:\n";
	cout << rec << ":" << setw(LIM) << pl.name << ":"
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
		finout.clear();                  //���eof ��־

	cout << "Enter planet name: ";
	cin.get(pl.name, LIM);
	//Eatline();
	cout << "enter planetary population:";
	cin >> pl.population;
	cout << "enter planet's acceleration of gravity:";
	cin >> pl.g;
	finout.seekp(place);                         //�����ָ����õ�place���λ��
	finout.write((char *)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "Error on attemped write\n";
		exit(EXIT_FAILURE);
	}

	//show revised file
	ct = 0;
	finout.seekg(0);                             //������ָ����õ���ʼλ��
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