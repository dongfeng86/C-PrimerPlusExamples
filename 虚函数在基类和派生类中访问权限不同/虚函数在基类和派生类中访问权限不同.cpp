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

	//情况1：如果基类是public，而派生类是Private
	virtual int GetInt()
	{
		return m_iBase;
	}
private:
	//情况2：如果基类是Private,派生类是Public
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
private:
	virtual int GetInt()
	{
		return m_iDerived;
	}

private:
	int m_iDerived;

};

int main()
{
	//第一种情况：我们考察对象类型
	CDerived derived;
	derived.Print();	//ok，对派生类CDerived来讲，Print()是Public的
	//derived.GetInt();	//编译错误，对派生类对象来说，GetInt()是Private的，不可访问。

	//第二种情况：我们考察指针类型
	CBase* pBase = &derived;
	//pBase->Print();	//编译错误，因为对基类CBase来讲，Print()是private型的，哪怕实际调用的派生类的Print是public的
	pBase->GetInt();	//ok,对基类指针来说，GetInt是public的，可以访问，而且调用的是派生类方法；哪怕在派生类中该方法是private的
}
