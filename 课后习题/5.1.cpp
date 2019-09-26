/*
计算阶乘值，这里应用了递归调用和异常处理
*/

#include<iostream>
#include <stdexcept>
#include<vector>
#include <iomanip>
#include<limits>

long double Factorial(int n);
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "请输入一个阶乘的值吧,输入任意字母退出:\n";
	int m;
	while (cin >> m)
	{
		while (cin.get() != '\n')
			continue;
		try
		{
			cout << m << "的阶乘结果为：" << Factorial(m) << endl;
			//建立一个vector数组，存储各个整数的阶乘
			std::vector<long double> arRes(m);
			for (int i = 0; i < m; i++)
			{
				arRes[i] = Factorial(i + 1);
			}
			cout << "现在，我们看看详细结果：\n";
			std::vector<long double>::iterator it;
			int iCount = 1;
			for (it = arRes.begin(),iCount=1; it != arRes.end(); it++,iCount++)
			{
				cout <<std::setw(2)<< iCount << ":" <<std::setw(20)<< *it << endl;
			}
		}
		catch (std::exception & e)
		{
			cout << "error caught:";
			cout<<e.what()<<endl;
			cout << "请输入一个阶乘的值吧,输入任意字母退出:\n";
			continue;
		}
		cout << "请输入一个阶乘的值吧,输入任意字母退出:\n";
	}
	cout << "\nBye.\n";	
	return 0;
}


long double Factorial(int n)
{
	if (n <= 0)
		//throw std::out_of_range("输入的n小于等于0，应大于0.\n");
		throw std::exception("输入的n小于等于0，应大于0.\n");           //标准异常的构造
	if (1==n)
		return 1;
	else
	{
		return n*Factorial(n - 1);
	}
}