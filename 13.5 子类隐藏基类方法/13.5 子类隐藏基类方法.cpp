/*
13.5 子类隐藏基类方法.cpp :
	在这个CPP中，我们主要考察子类隐藏父类方法的这种情况
	这里“隐藏”是指派生类的函数屏蔽了与其同名的基类函数，规则如下：
	（1）如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏（注意别与重载混淆）。
	（2）如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏（注意别与覆盖混淆）。
*/

#include <iostream>
using namespace std;

class CBase
{
public:
	//three overloaded showperks()三种重载的函数
	virtual void showperks(int a) const {
		cout << "\n\t函数原型：void CBase::showperks(int a)；a=" << a;
	}
	virtual void showperks(double x) const {
		cout << "\n\t函数原型： void CBase::showperks(double x)；x=" << x;
	}
	virtual void showperks() const {
		cout << "\n\t函数原型： void CBase::showperks()；";
	}
};

class CDerive :public CBase
{
public:
	//请注意，以下方法覆盖了基类的 void CBase::showperks(int a) 方法；
	//但是隐藏了基类的其余两种重载方法
	virtual void showperks(int a) const {
		cout << "\n\t函数原型：void CDerive::showperks(int a)；a=" << a;
	}

	//如果子类想要正确的覆盖基类方法，应该补充下面两种重载形式，这里，我们暂且屏蔽
	//virtual void showperks(double x) const {
	//	cout << "\n\t函数原型： void CDerive::showperks(double x)；x=" << x;
	//}
	//virtual void showperks() const {
	//	cout << "\n\t函数原型： void CDerive::showperks()；";
	//}
};

int main()
{
	cout << "\n首先让我们看看派生类对象调用方法的结果：";
	CDerive cDerive;
	cDerive.showperks((int)5);
	cDerive.showperks(3.2);	//编译器在这句没报错，原因是将浮点值转为了int值，从而调用的是上面的方法
	//cDerive.showperks();	//请注意，编译器此处报错，原因是子类void CDerive::showperks(int a)方法屏蔽了基类的的其他两种重载形式

	cout << "\n现在让我们看看基类调用方法的结果";
	CBase* pBase = &cDerive;
	pBase->showperks((int)5);
	pBase->showperks(3.2);
	pBase->showperks();
}