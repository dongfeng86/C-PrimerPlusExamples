#pragma once

#include <iostream>
#include<string>

using namespace std;

void PrintHello()
{
	cout << "hello,world!" << endl;

}

class CTest
{
public:
	CTest();
	CTest(std::string sName);
	~CTest();

public:
	std::string m_sName;
	int age;
};

CTest::CTest()
{
}

CTest::CTest(std::string sName)
{
	m_sName = sName;
}

CTest::~CTest()
{
	std::cout << "���ù��캯�������캯����m_sNameΪ��" << m_sName << endl;
}