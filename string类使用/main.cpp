#include<iostream>	
#include<string>
//#include<cstring>

int main()
{
	using namespace std;
	char charr[20];
	string str;

	//string�����C-��������β�ѯ�ַ�������
	cout << "length of string in charr before input:\n"
		<< strlen(charr) << endl;                           //���������31����Ϊstrlen()��һֱ�����ַ���ֱ���������ַ�
	cout << "length of string in str befor input: "
		<< str.length() << endl;
	cout << "enter a line of text:\n";
	cin.getline(charr, 20);
	cout << "you entered: " << charr << endl;
	cout << "enter anoter line of text:\n";
	getline(cin, str);
	cout << "you entered: " << str << endl;
	cout << "length of string in charr after input:"
		<< strlen(charr) << endl;
	cout << "length of string in str after input:"
		<< str.length() << endl;

	//string����Ĳ��ֲ���
	string s1;
	string s2;

	s1 = "nihao��";
	s2 = "�ö���";

	string s = s1 + s2;
	cout << s << endl;
	cout << "���仰һ����" << s.length() << "���ַ�";

	return 0;
}