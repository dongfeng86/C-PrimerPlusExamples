#include <iostream>

#include "Test.h"

int main()
{
	Test hehe(3, 5);
	Test hehe2(9,8);
	
	//问题一：默认提供的成员函数仅仅声明不提供实现会怎样？
	//通过试验发现，如果说在类声明仅仅声明了一个方法，但是没有定义；那么，如果主函数
	//没有调用这个方法，一切OK，如果调用了，就会出现“无法解析的外部符号省略号...”的错误
	//包括那些类会默认生成的成员函数，也是一样的情况。如果完全没有声明，类会提供声明和实现。
	//但是一旦声明了，却没有提供实现，主函数还引用了，就会报错。
	//Test mmm(hehe);		//这句会报错

	std::cout << "hehe结构体中的m=" << hehe.m << ";n=" << hehe.n << std::endl;

	hehe = hehe2;
	std::cout << "hehe结构体中的m=" << hehe.m << ";n=" << hehe.n << std::endl;

	//注意，下面的没办法通过编译，因为==没有定义
	//if (hehe == hehe2)
	//	std::cout << "奇怪了，竟然相等!\n";
}
