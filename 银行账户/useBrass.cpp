#include<iostream>
#include"brass.h"
#include<string>
const int CLIENTS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	Brass Piggy("proce", 381299, 4000);
	BrassPlus Hoggy("hoggy", 382288, 3000);

	Piggy.WithDraw(1000);
	Hoggy.WithDraw(2000);
	Piggy.ViewAcct();
	Hoggy.ViewAcct();


	Brass * pClients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempBal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "enter client's name:";
		getline(cin, temp);
		cout << "enter client's account number:";
		cin >> tempnum;
		cout << "enter opening balance:$";
		cin>> tempBal;
		cout << "enter 1 for brass account or "
			<< "2 for brassplus account:";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "enter either 1 or 2:";
		if (kind == '1')
			pClients[i] = new Brass(temp, tempnum, tempBal);
		else
		{
			double tmax, trate;
			cout << "enter the overdraft limit:$";
			cin >> tmax;
			cout << "enter the interest rate "
				<< "as a decimal fraction:";
			cin >> trate;
			pClients[i] = new BrassPlus(temp, tempnum, tempBal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}

	cout << endl;
	//基类指针可以在不进行显示类型转换的情况下指向派生类对象；基类引用可以在不进行显示类型转换的情况下引用派生类对象
	//注意，下面的代码展示了多态性；如果方法为虚方法，程序将根据引用或指针指向的对象的类型选择方法。
	for (int i = 0; i < CLIENTS; i++)
	{
		pClients[i]->ViewAcct();
		cout << endl;
	}

	//由于基类的析构函数为虚函数，因此，delete将调用指针指向的对象的析构函数；当调用派生类的析构函数时，
	//派生类首先自己的析构函数，然后自动调用基类的析构函数。使用虚析构函数可以确保正确的析构函数序列被调用。
	for (int i = 0; i < CLIENTS; i++)
	{
		delete pClients[i];
	}
	cout << "Done.\n";
	return 0;
}