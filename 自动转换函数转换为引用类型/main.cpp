/*本文件主要研究了自动转换函数转换为引用类型时的情况*/

#include<iostream>

//定义类
class cTest
{
public:
	int m_iCount;
	int m_iOther;
public:
	cTest();
	cTest(int iCount,int iOther);

	//这是一个非常精彩的应用，转换函数直接返回一个成员变量的引用；这样就能修改这个成员变量；
	//并且，返回引用节省了返回临时变量（从概念讲，返回值被存储在一个临时位置，然后再去使用）的开销
	operator int& ();		
};

cTest::cTest(int iCount, int iOther)
{
	m_iCount = iCount;
	m_iOther = 0;
}

cTest::cTest()
{
}

cTest::operator int& ()
{
	return m_iCount;
}


int main()
{
	using namespace std;
	cTest cTemp(5,5);
	cout << "类中的数据为m_iCout=" << cTemp.m_iCount << ";m_iOther:" << cTemp.m_iOther << endl;

	int m = cTemp;			//调用了operator int&()接口，
	cout << "现在m为：" << m << endl;

	(int)cTemp = 10;		//调用了operator int&()接口，并且顺利修改了成员变量的值
	cout << "现在m_iCount为:" << cTemp.m_iCount << endl;
}
