#include"��ͷ.h"
#include<iostream>

int main()
{
	MyClass m;
	std::cout << "m�ĳ���Ϊ:" << sizeof(m) << endl;
	std::cout << "m�ĵ�ַΪ��" << &m << endl;

	return 0;
}