/*
��ȡһ�������ַ���������д��ĸת��ΪСд����Сд�ַ�ת��Ϊ��д
*/

#include<iostream>
#include<string>
#include<cctype>
#include <algorithm>

int main()
{
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;

	string strInput;
	cout << "������һ���ַ�����ֱ��@Ϊֹ������quit�˳���\n";
	while (std::getline(cin, strInput, cin.widen('@')) && "quit"!=strInput)
	{
		////��һ��string�����ַ������д�Сдת��
		//std::transform(strInput.begin(), strInput.end(), strInput.begin(), ::tolower);
		//cout << "��������ǣ�\n";
		//cout << strInput;
		while (cin.get() != '\n')
			continue;
		string::iterator it;
		for (it = strInput.begin(); it != strInput.end(); it++)
		{
			//if (*it >= 'A' && *it <= 'Z')
			//	*it += 32;
			//else if (*it >= 'a' && *it <= 'z')
			//	*it -= 32;
			//���·�������cctype��ʵ�ֵĺ���������ʶ���Сд�Լ�ת����Сд��
			if (islower(*it))
				*it = toupper(*it);
			else if (isupper(*it))
				*it = tolower(*it);
		}
		cout << "���ַ����д�д��ĸת��ΪСд����Сд��ĸת��Ϊ��д�Ľ����\n";
		cout << strInput << endl;
		cout << "������һ���ַ�����ֱ��@Ϊֹ������quit�˳���\n";
	}

	return 0;
}