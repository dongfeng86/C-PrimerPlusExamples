// 虚函数表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Base1
{
public:
	int base1_1;
	int base1_2;
	virtual void base1_fun1() {}
	virtual void base1_fun2() {}
};
class Derive1 : public Base1
{
public:
	int derive1_1;
	int derive1_2;
	virtual void derive1_fun1() {}
};

int main()
{
	unsigned int s, off1, off2, off3;
	s = sizeof(Base1);
	off1 = offsetof(Base1, base1_1);
	off2 = offsetof(Base1, base1_2);

	Base1 base;
	s = sizeof(base);

	Derive1 derive;
	s = sizeof(derive);

	Derive1* pDerive = &derive;
	pDerive->derive1_fun1();
}
