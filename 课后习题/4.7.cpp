/*
�����ĿҪ����new�����ڴ棬����������������ӡ�
ʵ���ϣ������Ŀʹ��vector��̬��������Ϊ���ʵġ�
*/
#include<iostream>
#include<string>

struct SPizza
{
	std::string sName;
	double dDiameter;
	double dWeight;
};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "������Pizza��������";
	SPizza* pPizza = new SPizza[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "������pizza�������ƣ�\n";
		if (getline(cin, pPizza[i].sName) && pPizza[i].sName != "")
		{
			cout << "������Pizza����ֱ����" << endl;
			cin >> pPizza[i].dDiameter;
			while (cin.get() != '\n')
				continue;
			cout << "������Pizza����������\n";
			cin >> pPizza[i].dWeight;
			while (cin.get() != '\n')
				continue;
		}
		else
			break;
	}

	cout << "���ڣ������ǿ������������Ϣ�ɣ�\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Pizza�������ƣ�" << pPizza[i].sName << ";Pizza����������"
			<< pPizza[i].dWeight << "Pizza����ֱ����" << pPizza[i].dDiameter << endl;
	}

	delete[] pPizza;                //�����������
	return 0;
}