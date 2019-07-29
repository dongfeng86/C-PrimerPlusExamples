//计算斐波那契数列
//我认为这个一个递归的完美示例，因此，采用递归的形式进行编程

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
	cout << "你输入数字的斐波那契值应为："<<fabor(num) << endl;

	ReverseStr();

	return 0;
}

//这就是递归
long fabor(int num)
{
	if (num == 1)
		result = 1;
	else
		result = fabor(num - 1)*num;

	return result;
}

//该函数说明了一个事情，字符串可以和数组一样，进行索引。
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
