#include<iostream>
using namespace std;

double betsy(int);
double pam(int);
void estimate(int lines, double(*pf)(int));

double betsy(int ins)
{
	return 0.05*ins;
}

double pam(int ins)
{
	return 0.03*ins+0.0004*ins*ins;
}

void estimate(int lines, double(*pf)(int))                     //函数指针的声明方法
{
	cout << lines << " lines will take ";
	cout << pf(lines) << " hours\n";
}

