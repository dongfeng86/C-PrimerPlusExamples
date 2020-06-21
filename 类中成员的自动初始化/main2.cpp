/*
如果没有初始化变量，则会执行默认初始化。
1.栈中的变量（函数体中的变量）和堆中的变量（动态内存）会有不确定的值；
2.全局变量和静态变量（包括局部静态变量）会初始化为0
3.关于类中的成员变量：
	a. 首先，类对象会调用（默认）构造函数进行初始化；
	b. 若类对象在全局作用域或为静态局部对象时，则类的内置成员变量被初始化为0.
	c. 若类对象在局部作用域定义时，则类的内置成员变量不被初始化为0。
	d. 对于类类型成员按照其自身的默认构造函数进行初始化。
*/


#include <iostream>

class A {
public:
	int value;
};

class B {
public:
	int value;
	A a;
	B(){}
};

B b1;

int main() 
{
	using namespace std;
	B b2;
	static B b3;
	cout << b1.value << "\t" << b1.a.value << endl;
	cout << b2.value << "\t" << b2.a.value << endl;
	cout << b3.value << "\t" << b3.a.value << endl;
	//cout << b2.value << "\t" << b2.a.value << endl;
	return 0;
}