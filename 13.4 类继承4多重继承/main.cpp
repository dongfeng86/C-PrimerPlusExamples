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

	//���漸�д���ֻ��˵�����ڶ�̳��У�����������ָ��ǿ��ת��Ϊ����ָ�룬ָ��ָ��ĵ�ַ���
	//������仯��ĵ�ַʵ���ǲ�ͬ�麯����ĵ�ַ
	SingingWaiter* pSingerWait = new SingingWaiter;
	Worker* pWor = (Worker*)pSingerWait;
	Singer* pSinger = (Singer*)pSingerWait;
	Waiter* pWaiter = (Waiter*)pSingerWait;
	//ע�⣬delete�˶��ؼ̳��л����ָ�룬���ڻ���Ĺ��캯����virtual�ģ���ˣ�������������������������������ε��û������������
	delete pWor;
	//delete pSingerWait;

	cout << "\nHere is your staff:\n";
	for (int i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (int i = 0; i < ct; i++)
		delete lolas[i];                         //�ͷ��ڴ�
	cout << "Bye.\n";
	return 0;                
}