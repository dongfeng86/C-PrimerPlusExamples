#pragma once

struct Test
{
	int m;
	int n;

	Test(int x, int y);
	//Test(const Test &);					//声明了不实现，并且主函数引用了，就会报错
	void heheheh();
};

Test::Test(int x, int y)
{
	m = x;
	n = y;
}