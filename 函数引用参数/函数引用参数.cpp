// 函数引用参数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//
//class CBase
//{
//public:
//	CBase() {};
//	virtual ~CBase() {};
//	int m_iData;
//};
//
//class CDerive :public CBase
//{
//public:
//	CDerive() {};
//	~CDerive() {};
//};
//
//void TestPoiterRef(CBase*& pBase)
//{
//	pBase->m_iData = 3;
//}
//
//void TestObjRef(CBase& pBase)
//{
//	pBase.m_iData = 3;
//}
//
//int main()
//{
//	CDerive* pDerive = new CDerive;
//	//TestPoiterRef(pDerive);
//	TestObjRef(*pDerive);
//	delete pDerive;
//}

#include <stdio.h>

class CBase
{
public:
	CBase() {};
	virtual ~CBase() {};
};

class CDerive :public CBase
{
public:
	CDerive() {};
	~CDerive() {};
};

void TestPoiterRef(CBase*& pBase)
{
	printf("\nThis a simple fun!");
}

int main()
{
	CDerive* pDerive = new CDerive;
	TestPoiterRef(pDerive);		//这一步编译出错
	delete pDerive;
}