#include"标头.h"
#include<iostream>

int main()
{
	MyClass m;
	std::cout << "m的长度为:" << sizeof(m) << endl;
	std::cout << "m的地址为：" << &m << endl;

	return 0;
}