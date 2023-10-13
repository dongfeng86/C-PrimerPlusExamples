#include <iostream>

//自定义类的转换
class A {
public:
	virtual void GetInt(){}	//必须有虚函数（更准确的说是虚函数表），才能使用dynamic_cast
};
class B : public A {};
class C {};

int main() 
{
	double dValue = 12.12;
	float fValue = 3.14; // warning C4305: “初始化”: 从“double”到“float”截断
	int nDValue = static_cast<int>(dValue); // 12
	int nFValue = static_cast<int>(fValue); // 3

	A *pA = new A;
	B *pB = static_cast<B*>(pA); // 编译不会报错, B类继承于A类
	pB = new B;
	pA = static_cast<A*>(pB); // 编译不会报错, B类继承于A类
	//C *pC = static_cast<C*>(pA); // 编译报错, C类与A类没有任何关系。error C2440: “static_cast”: 无法从“A *”转换为“C *”


	A a;
	const A* pConstA = &a;
	A* pNoConstA = const_cast<A*>(pConstA);	//合法
	//B* pNoConstB = const_cast<A*>(pConstA);	//非法

	B* pB2 = new B;
	A* pA2 = dynamic_cast<A*>(pB2);	//up-cast ,合法
	B* pB3 = dynamic_cast<B*>(pA2);	//合法，dynamic_cast进行安全检查以后，认为pA2实际指向B对象

	A* pA3 = new A;
	//pB3 = dynamic_cast<A*>(pA3);	//编译错误，error C2440，dynamic_cast进行安全检查以后，认为此转换不安全，禁止转换

	delete pA3;
	delete pB2;
}