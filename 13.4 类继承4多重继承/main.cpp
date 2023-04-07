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

	SingingWaiter* pSingWaitor = new SingingWaiter;
	Worker* pWorker = (Worker*)pSingWaitor;
	Singer* pSinger = (Singer*)pSingWaitor;
	Waiter* pWaiter = (Waiter*)pSingWaitor;

	Singer* pSingerNew = (Singer*)pWaiter;	//这种同级别的转换会出错
	delete pWorker;
	

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