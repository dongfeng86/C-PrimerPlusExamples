// 对象切割.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class CBase {
public:
	virtual ~CBase() = default;

	virtual void foo() {
		printf("print in Class CBase,this address:%p\n", this);
	}
};

class CDerive : public CBase {
public:
	virtual void foo() override {
		printf("print in Class CDerive,this address:%p\n", this);
	}
};

int main() 
{
	CBase base;
	CDerive derive;
	CBase* pBase = &derive;

	cout << "\n本次调用的是pBase->CBase::foo()\n\t";
	pBase->CBase::foo();

	cout << "\n本次调用的是pBase->foo()\n\t";
	pBase->foo();

	cout << "\n本次调用的是 (static_cast<CBase>(derive)).foo() \n\t";
	(static_cast<CBase>(derive)).foo();
}