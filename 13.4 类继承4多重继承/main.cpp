#include "Worker.h"
#include <iostream>
#include <cstring>

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Worker * lolas[SIZE];
	
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "enter the employee category:\n"
			<< "w:waiter  s:singer "
			<< "t:singing waiter  q:quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "please enter a w,s,t or q:";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':
			lolas[ct] = new Waiter;
			break;
		case 's':
			lolas[ct] = new Singer;
			break;
		case 't':
			lolas[ct] = new SingingWaiter;
			break;
		default:
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	//下面几行代码只是说明：在多继承中，如果将子类的指针强制转换为基类指针，指针指向的地址会变
	//，这个变化后的地址实际是不同虚函数表的地址
	SingingWaiter* pSingerWait = new SingingWaiter;
	Worker* pWor = (Worker*)pSingerWait;
	Singer* pSinger = (Singer*)pSingerWait;
	Waiter* pWaiter = (Waiter*)pSingerWait;
	//注意，delete了多重继承中基类的指针，由于基类的构造函数是virtual的，因此，调用了子类的析构函数，子类再依次调用基类的析构函数
	delete pWor;
	//delete pSingerWait;

	cout << "\nHere is your staff:\n";
	for (int i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (int i = 0; i < ct; i++)
		delete lolas[i];                         //释放内存
	cout << "Bye.\n";
	return 0;                
}