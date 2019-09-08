#include "ec_mean.h"
#include<cmath>
#include<string>
#include<iostream>
#include <stdlib.h>

class demo
{
private:
	std::string word;
public:
	demo(const std::string & str)
	{
		word = str;
		std::cout << "demo " << word << " created.\n";
	}
	~demo()
	{
		std::cout << "demo " << word << " destroyed\n";
	}
	void show() const 
	{
		std::cout << "demo " << word << " lives!\n";
	}
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	{
		demo d1("found in block in main()");
		cout << "enter two numbers:";
		while (cin >> x >> y)
		{
			try
			{
				demo d3("found in try");              //如果捕捉到了异常，d3也会被析构。实际上是try块到相应的catch块之间自动变量都会被析构
				                                      //注意，如果异常解退到这个try块，则程序会执行到相应的catch块，这个try块所有变量都会被析构
				z = means(x, y);
				cout << "the mean mean of " << x << " and " << y << " is " << z << endl;
				cout << "enter next pair:\n";
			}
			catch (bad_hmean & bg)
			{
				bg.mesg();
				cout << "try again.\n";
				continue;
			}
			catch (bad_gmean & hg)
			{
				cout << hg.mesg();
				cout << "values used: " << hg.v1 << ", " << hg.v2 << endl;
				cout << "sorry,you don't get to play any more.\n";
				//exit(EXIT_FAILURE);            //如果执行该语句，则程序将立刻终止，不会执行d1的析构。但是，如果d1是static对象的话，会被析构。
				break;
			}
		}
		d1.show();
	}
	cout << "Bye!\n";
	cin.get();
	cin.get();
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a,b);
	return 2.0*a*b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);              //throw语句将控制权向上返回到第一个这样的函数：包含能够捕获相应异常的try-catch组合。
	return std::sqrt(a*b);
}

double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in mean()");
	am = (a + b) / 2.0;
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch(bad_hmean & bg)                   
	{
		bg.mesg();
		std::cout << "caught in means()\n";

		//以下两个处理异常的方式，非常重要。

		//exit(EXIT_FAILURE);    //注意，若执行该语句，则程序立刻终止，不会执行d2的析构。

		throw;                   //注意，catch块中的throw语句导致mean()函数终止执行，并将异常传递给调用他的函数。
								 //但是，一定要注意，程序进行栈解退以回到能够捕捉异常的地方时，将释放栈中的自动存储型变量。
		                         //如果变量是类对象，将为该对象调用析构函数
	}
	d2.show();
	return(am + hm + gm) / 3.0;
}

