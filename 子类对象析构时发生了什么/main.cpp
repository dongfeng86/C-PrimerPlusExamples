// 子类对象析构时发生了什么.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//基类
class CBase
{
public:
	CBase(int i) {
		m_base = i;
	}

	~CBase() {
		std::cout << "父类开始析构了,此时调用Print,结果为：" << std::endl;
		Print();
	}

	virtual void Print() const {
		std::cout << "	这是在父类中：m_base=" << m_base << std::endl;
	}
private:
	int m_base;
};

//派生类
class CDerived1 :public CBase
{
public:
	CDerived1(int i)
		:CBase(6 / 2) {
		m_Derive = i;
	}

	~CDerived1() {
		std::cout << "子类开始析构了,此时调用Print,结果为：" << std::endl;
		Print();
	}

	virtual void Print() const {
		std::cout << "\t这是在子类中：m_Derive=" << m_Derive << std::endl;
	}

private:
	int m_Derive;
};


int main()
{
	CDerived1 cSon(6);
	CBase* pBase = &cSon;
	std::cout << "第一次调用指向子类的方法Print,结果为：" << std::endl;
	pBase->Print();

	std::cout << "\n让我们看看析构时发生了什么" << std::endl;
}
