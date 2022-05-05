// 杂项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
	int iNum = 0x84ea;
	for (int i = 0; i < sizeof(int); i++)
	{
		unsigned char c = (iNum>>8*i) & 0xff;
		printf("\n小端法中，第%d个字节为：%x", i, c);
	}
}