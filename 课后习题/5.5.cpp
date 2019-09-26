/*
����map���ϼ�¼ÿ���µ���������
*/

#include<iostream>
#include<string>
#include <iomanip>

struct SSale 
{
	unsigned int nYear;
	unsigned int nMonth;
	unsigned int nQuantity;
};

#define YEARS 2
#define MONTHS 12
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	const std::string arMonth[MONTHS]{ "January","February" ,"March","April","May"
	,"June","July","August","September","October","November","December"};

	unsigned int arSale[YEARS][MONTHS];
	for (int i = 0; i < YEARS; i++)
	{
		cout << "�������" << i+1<< "�������\n";
		for (int j = 0; j < MONTHS; j++)
		{
			cout << arMonth[j]<< ":";
			unsigned int nTemp;
			cin >> arSale[i][j];
			while (cin.get() != '\n')
				continue;
		}
	}

	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < YEARS; i++)
	{
		cout << "��" << i + 1 << "��" << endl;
		double dQuantity=0;
		for (int j = 0; j < MONTHS; j++)
		{
			cout <<std::left<< std::setw(15) << arMonth[j] << ":" <<std::setw(10)<< arSale[i][j] << endl;
			dQuantity += arSale[i][j];
		}
		cout << "��" << i + 1 << "���������Ϊ��" << dQuantity << endl;
	}

	return 0;
}