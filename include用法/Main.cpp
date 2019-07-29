#include "Head.h"       //注意，包含了头文件以后，连<iostream>都不需要声明了，因为头文件中有


void PrintHello();     //注意，反复使用多次函数原型声明，没有问题，对这个例子来说，不需要加这两个声明，头文件就有。
void PrintHello();

int main()
{
	std::cout << "开始调用PrintHello函数：" << std::endl;
	PrintHello();

	CTest cInfo1;
	cInfo1 = CTest("东风");
	CTest cInfo2 = CTest("银河");
	//std::cout << "现在类的信息是：" << std::endl;
	//std::cout << "姓名：" << cInfo.m_SName << endl;
}