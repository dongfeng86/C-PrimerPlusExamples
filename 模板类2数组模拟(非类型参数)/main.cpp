#include <iostream>
#include "ArrayTP.h"

int main()
{
	//创建一个数组
	ArrayTP<int, 3> arTemp1;
	arTemp1[0] = 3;
	arTemp1[1] = 2;
	arTemp1[2] = 1;

	//在屏幕上显示
	std::cout << "现在显示整数型数组:\n" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << arTemp1[i] << std::endl;
	}

	std::cout << "现在显示浮点型数组：\n" << std::endl;
	ArrayTP<double, 3> arTemp2;
	arTemp2[0] = 2.3;
	arTemp2[1] = 4.6;
	arTemp2[2] = 5.3;
	//arTemp2[4] = 6.9;
	for (int i = 0; i < 3; i++)
	{
		std::cout << arTemp2[i] << std::endl;
	}

	std::cout << "现在显示赋值后的数组：\n" << std::endl;
	ArrayTP<double, 3> arTemp4;
	arTemp4 = arTemp2;
	for (int i = 0; i < 3; i++)
	{
		std::cout << arTemp4[i] << std::endl;
	}

	std::cout << "现在显示复制后的数组：\n" << std::endl;
	ArrayTP<double, 3> arTemp5(arTemp2);
	for (int i = 0; i < 3; i++)
	{
		std::cout << arTemp5[i] << std::endl;
	}

	return 0;
}



