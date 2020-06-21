//这是关于宏重定义一个经典的案例，在预处理阶段，宏并不是按照最后一次
//定义的数值进行替换，相反，在程序的不同位置，宏均是按照这个位置以前
//宏的最后一次定义数值进行替换。
//这和汇编语言中等号伪指令对符号常量的处理一致
#include<iostream>
#define _I_COUNT 10
int main()
{
	int iN = _I_COUNT;
	std::cout << "现在宏的数值为：" << iN << std::endl;	//此时iN为10
#define _I_COUNT 5
	int iM = _I_COUNT;
	std::cout << "现在宏的数值为：" << iM << std::endl;	//此时iM为5
	return 0;
}