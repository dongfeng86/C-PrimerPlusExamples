//����쳲���������
//����Ϊ���һ���ݹ������ʾ������ˣ����õݹ����ʽ���б��

#include<iostream>
#include<string>
using namespace std;

void ReverseStr(void);
long fabor(int num);

long result;

int main()
{
	cout << "please input a  num:" << endl;
	int num;
	cin >> num;
	cout << "���������ֵ�쳲�����ֵӦΪ��"<<fabor(num) << endl;

	ReverseStr();

	return 0;
}

//����ǵݹ�
long fabor(int num)
{
	if (num == 1)
		result = 1;
	else
		result = fabor(num - 1)*num;

	return result;
}

//�ú���˵����һ�����飬�ַ������Ժ�����һ��������������
void ReverseStr(void)
{
	cout << "enter a string :" << endl;
	string str;
	cin >> str;
	cin.get();
	for (int i = 0, j = str.length() - 1; j > i; j--, i++)
	{
		char temp;
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	cout << str<<endl;
}
