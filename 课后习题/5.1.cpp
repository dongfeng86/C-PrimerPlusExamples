/*
����׳�ֵ������Ӧ���˵ݹ���ú��쳣����
*/

#include<iostream>
#include <stdexcept>
#include<vector>
#include <iomanip>
#include<limits>

long double Factorial(int n);
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "������һ���׳˵�ֵ��,����������ĸ�˳�:\n";
	int m;
	while (cin >> m)
	{
		while (cin.get() != '\n')
			continue;
		try
		{
			cout << m << "�Ľ׳˽��Ϊ��" << Factorial(m) << endl;
			//����һ��vector���飬�洢���������Ľ׳�
			std::vector<long double> arRes(m);
			for (int i = 0; i < m; i++)
			{
				arRes[i] = Factorial(i + 1);
			}
			cout << "���ڣ����ǿ�����ϸ�����\n";
			std::vector<long double>::iterator it;
			int iCount = 1;
			for (it = arRes.begin(),iCount=1; it != arRes.end(); it++,iCount++)
			{
				cout <<std::setw(2)<< iCount << ":" <<std::setw(20)<< *it << endl;
			}
		}
		catch (std::exception & e)
		{
			cout << "error caught:";
			cout<<e.what()<<endl;
			cout << "������һ���׳˵�ֵ��,����������ĸ�˳�:\n";
			continue;
		}
		cout << "������һ���׳˵�ֵ��,����������ĸ�˳�:\n";
	}
	cout << "\nBye.\n";	
	return 0;
}


long double Factorial(int n)
{
	if (n <= 0)
		//throw std::out_of_range("�����nС�ڵ���0��Ӧ����0.\n");
		throw std::exception("�����nС�ڵ���0��Ӧ����0.\n");           //��׼�쳣�Ĺ���
	if (1==n)
		return 1;
	else
	{
		return n*Factorial(n - 1);
	}
}