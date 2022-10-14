// 虚函数在基类和派生类中访问权限不同.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
在派生类中，如果改写了某个虚函数的访问权限，例如基类中某个函数A()的访问权限为Private，派生类中
将这个函数的访问权限改写为public，那么派生类对象及派生类指针可以在外部调用这个A();但是基类指针
无法调用A()。
这说明：类成员函数的访问权限仅仅影响当前类对象或指针。
*/

#include <iostream>

class CBase
{
public:
	CBase() {}

	virtual int GetInt()
	{
		return m_iBase;
	}
private:
	virtual void Print() {
		std::cout << "现在在基类中调用Print" << std::endl;
	}
	int m_iBase;
};

class CDerived :public CBase
{
public:
	CDerived() :CBase() {}
	virtual void Print() {
		std::cout << "现在在派生类中调用Print" << std::endl;
	}

	virtual int GetInt()
	{
		return m_iDerived;
	}

private:
	int m_iDerived;

};

int main()
{
	CDerived derived;
	derived.Print();	//ok，对派生类CDerived来讲，Print()是ppublic的

	CBase* pBase = &derived;
	//pBase->Print();	//编译错误，因为对基类CBase来讲，Print()是private型的，哪怕实际调用的派生类的Print是public的
}
