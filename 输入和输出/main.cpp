#include<iostream>
void InputNumAndChar();
using namespace std;
void ReaptedlyInput();

int main()
{
	ReaptedlyInput();
	InputNumAndChar();
	return 0;

	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	//��һ�ַ�ʽ������cin.getline()���д���
	cout << "Enter your name:\n";
	cin.getline(name, ArSize);                             //����ȡArSize-1���ַ����Զ��ڽ�β���'\0';��ȡ���з����ҽ�������
	cout << "enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";

	//�ڶ��ַ�ʽ������cin.get()���д���
	cout << "\n\nnow we will take another way!\n";
	cout << "enter your name:" << endl;
	cin.get(name, ArSize).get();                           //cin.get()���Զ�ȡ��һ���ַ�����ʹ�ǻ��з�
	cout << "enter your favorite dessert:\n";
	cin.get(dessert, ArSize).get();
	cout << "I have another delicious " << dessert << " for you, " << name << endl;

	return 0;
}


void InputNumAndChar()
{

	cout << "what year was your house built?\n";
	int year;
	cin >> year;                                                //cin���������ַ�����ȡ�ַ������з��������������
	cin.get();                                                  //��ȡ�������Ļس���
	cout << "what is its street address\n";
	char address[80];
	cin.getline(address, 80);                                   //cin.get��������ʱ������ʧЧλ������cin.getline()��������ʱ������ʧЧλ��
	cout << "year built: " << year << endl;
	cout << "address: " << address << endl;
	cout << "done!\n";

}

void ReaptedlyInput()
{
	//��һ�ַ���
	//char c;
	//c = cin.get();
	//while (cin.fail()==false)
	//{
	//	cout << c << endl;
	//	while (cin.get() != '\n')
	//		continue;
	//	cout << "��������һ���ַ�" << endl;
	//	c = cin.get();
	//}


	//cin�������հ��ַ�
	//char c;
	//cout << "please input a char:\n";
	//cin >> c;
	//while (cin.fail()!=true)
	//{
	//	cout << "��������ǣ�" << c << endl;
	//	cin >> c;
	//}

	char ch;
	int count=0;
	cout << "enter a string:" << endl;
	while (cin.get(ch))                                          //cin.get()��cin.get(ch)���ȡ�ո��Ʊ�λ���Լ����з�
	{
		cout << ch;
		count++;
	}
	cout << "��һ��������" << count << "�ַ�" << endl;
}

