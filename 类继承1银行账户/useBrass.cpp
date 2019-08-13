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
	//����ָ������ڲ�������ʾ����ת���������ָ����������󣻻������ÿ����ڲ�������ʾ����ת����������������������
	//ע�⣬����Ĵ���չʾ�˶�̬�ԣ��������Ϊ�鷽�������򽫸������û�ָ��ָ��Ķ��������ѡ�񷽷���
	for (int i = 0; i < CLIENTS; i++)
	{
		pClients[i]->ViewAcct();
		cout << endl;
	}

	//���ڻ������������Ϊ�麯������ˣ�delete������ָ��ָ��Ķ�����������������������������������ʱ��
	//�����������Լ�������������Ȼ���Զ����û��������������ʹ����������������ȷ����ȷ�������������б����á�
	for (int i = 0; i < CLIENTS; i++)
	{
		delete pClients[i];
	}
	cout << "Done.\n";
	return 0;
}