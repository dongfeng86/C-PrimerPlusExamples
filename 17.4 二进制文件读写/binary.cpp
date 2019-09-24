/*
���ļ���Ҫ�����˶����Ƹ�ʽ�Ķ�д����
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<string>

inline void EatLIne() { while (std::cin.get() != '\n') continue; }
struct SPlant
{
	//std::string name;          //�����ԣ���string���߳������鶼���ԴﵽЧ��
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

	//��ʾ��ʼ����
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);             //�Զ�������ʽ��;
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

	//����������
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
		EatLIne();                     //��ȡʣ���˵��ַ���Ϊʹ��getlineɨ���ϰ�
		fout.write((char *)&pl, sizeof pl);
		cout << "Enter planet name(enter a blank line to quit):\n";
		//getline(cin, pl.name);
		cin.get(pl.name, 20);                
	}
	fout.close();

	//��ʾ��������ļ�
	fin.clear();                      //�������е�λ״̬
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