#include <iostream>
//#include "ArrayTP.h"                   //模板类友元函数的第一种方法
#include "ArrayTP(another method).h"     //模板类友元函数的第二种方法

int main()
{
	//创建一个数组
	ArrayTP<int, 3> arTemp1;
	arTemp1[0] = 3;
	arTemp1[1] = 2;
	arTemp1[2] = 1;

	//在屏幕上显示
	std::cout << "现在显示整数型数组:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << arTemp1[i] << std::endl;
	}

	std::cout << "现在显示浮点型数组：" << std::endl;
	ArrayTP<double, 3> arTemp2;
	arTemp2[0] = 2.3;
	arTemp2[1] = 4.6;
	arTemp2[2] = 5.3;
	//arTemp2[4] = 6.9;
	std::cout << arTemp2 << std::endl;

	std::cout << "现在显示赋值后的数组：" << std::endl;
	ArrayTP<double, 3> arTemp4;
	arTemp4 = arTemp2;
	std::cout << arTemp4 << std::endl;

	std::cout << "现在显示复制后的数组：" << std::endl;
	ArrayTP<double, 3> arTemp5(arTemp2);
	std::cout << arTemp5 << std::endl;

	return 0;
}



