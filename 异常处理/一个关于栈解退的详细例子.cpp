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
				demo d3("found in try");              //�����׽�����쳣��d3Ҳ�ᱻ������ʵ������try�鵽��Ӧ��catch��֮���Զ��������ᱻ����
				                                      //ע�⣬����쳣���˵����try�飬������ִ�е���Ӧ��catch�飬���try�����б������ᱻ����
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
				//exit(EXIT_FAILURE);            //���ִ�и���䣬�����������ֹ������ִ��d1�����������ǣ����d1��static����Ļ����ᱻ������
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
		throw bad_gmean(a, b);              //throw��佫����Ȩ���Ϸ��ص���һ�������ĺ����������ܹ�������Ӧ�쳣��try-catch��ϡ�
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

		//�������������쳣�ķ�ʽ���ǳ���Ҫ��

		//exit(EXIT_FAILURE);    //ע�⣬��ִ�и���䣬�����������ֹ������ִ��d2��������

		throw;                   //ע�⣬catch���е�throw��䵼��mean()������ִֹ�У������쳣���ݸ��������ĺ�����
								 //���ǣ�һ��Ҫע�⣬�������ջ�����Իص��ܹ���׽�쳣�ĵط�ʱ�����ͷ�ջ�е��Զ��洢�ͱ�����
		                         //�������������󣬽�Ϊ�ö��������������
	}
	d2.show();
	return(am + hm + gm) / 3.0;
}

