#include<iostream>

struct Inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	using namespace std;
	Inflatable guest[3]=
	{
		{"badi",80,9.2},
		{"hah",29,3.2},
		{"ming",39,4.2}
	};                                      //����һ����ʼ����䣬��˺���ӷֺ�

	for (int i = 0; i < 3; i++)
	{
		cout << "�˿͵������ǣ�" << guest[i].name << ";�˿�Ҫ��������ǣ�" << guest[i].volume << ";�ܵļ۸�Ϊ:" << guest[i].price << endl;
	}
	cout << "���������й˿���Ϣ." << endl;

	cout << "\n���ڣ���������һ�½ṹ��ĸ�ֵ��" << endl;
	guest[2] = guest[1];
	for (int i = 0; i < 3; i++)
	{
		cout << "�˿͵������ǣ�" << guest[i].name << ";�˿�Ҫ��������ǣ�" << guest[i].volume << ";�ܵļ۸�Ϊ:" << guest[i].price << endl;
	}
	cout << "�����Ǹ��º�˿���Ϣ." << endl;
}