#include<iostream>
#include<string>
#include <iomanip>

struct SCar
{
	std::string sName;
	unsigned int nYear;
};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "how many cars do you have?\n";
	int iQuantity;
	while (!(cin >> iQuantity))                  //�������������������
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "�����������������룺\n";
		continue;
	}
	while (cin.get() != '\n')
		continue;
	SCar * pCar = new SCar[iQuantity];
	for (int i = 0; i < iQuantity; i++)
	{
		cout << "Car #" << i + 1 << ":" << endl;
		cout << "please enter th make:\n";
		getline(cin, pCar[i].sName);
		while (cin.fail() || pCar[i].sName == "")
		{
			cout << "�����������������룺";
			cin.clear();
			getline(cin, pCar[i].sName);
		}
		
		cout << "please enter the year made:";
		while (!(cin >> pCar[i].nYear))
		{
			cout << "���������������������룺";
			cin.clear();
			while (cin.get() != '\n')
				continue;
			continue;
		}
		while (cin.get() != '\n')
			continue;
	}

	cout << "here is your collection��" << endl;
	for (int i = 0; i < iQuantity; i++)
	{
		cout << std::setw(12) << "������ݣ�" <<pCar[i].nYear
			<< ";�������̣�" <<pCar[i].sName<<endl;
	}
	delete[] pCar;
	return 0;

}