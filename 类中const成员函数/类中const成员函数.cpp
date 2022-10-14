// 类中const成员函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//类中的const和非const成员函数可以重载，对于const的重载形式其返回值也应该是const的

#include <iostream>
#include "String.h"

class MyName
{
public:
	MyName(const char* name);
	~MyName();

	const std::string& GetName() const;
	std::string& GetName();
private:
	std::string m_sName;
};

MyName::MyName(const char* name)
{
	m_sName = name;
}

MyName::~MyName()
{
}

const std::string& MyName::GetName() const
{
	return m_sName;
}

std::string& MyName::GetName()
{
	return m_sName;
}

int main()
{
	const MyName name("She");
	std::cout << "\n当前string=" << name.GetName().c_str() << std::endl;

	MyName test("She");
	test.GetName() = "张三";
	std::cout << "\n当前string=" << test.GetName().c_str() << std::endl;
}
