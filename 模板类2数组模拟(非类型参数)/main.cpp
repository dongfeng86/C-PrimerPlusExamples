#include <iostream>
//#include "ArrayTP.h"                   //ģ������Ԫ�����ĵ�һ�ַ���
#include "ArrayTP(another method).h"     //ģ������Ԫ�����ĵڶ��ַ���

int main()
{
	//����һ������
	ArrayTP<int, 3> arTemp1;
	arTemp1[0] = 3;
	arTemp1[1] = 2;
	arTemp1[2] = 1;

	//����Ļ����ʾ
	std::cout << "������ʾ����������:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << arTemp1[i] << std::endl;
	}

	std::cout << "������ʾ���������飺" << std::endl;
	ArrayTP<double, 3> arTemp2;
	arTemp2[0] = 2.3;
	arTemp2[1] = 4.6;
	arTemp2[2] = 5.3;
	//arTemp2[4] = 6.9;
	std::cout << arTemp2 << std::endl;

	std::cout << "������ʾ��ֵ������飺" << std::endl;
	ArrayTP<double, 3> arTemp4;
	arTemp4 = arTemp2;
	std::cout << arTemp4 << std::endl;

	std::cout << "������ʾ���ƺ�����飺" << std::endl;
	ArrayTP<double, 3> arTemp5(arTemp2);
	std::cout << arTemp5 << std::endl;

	return 0;
}



