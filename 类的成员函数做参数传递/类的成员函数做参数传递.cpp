#include <iostream>

class Test
{
public:
	// 示例1，类内部的typeDef函数声明，属于Test成员，声明时必须加Test声明作用域，且赋值的函数必须为Test成员.
	// 核心原理为类的成员函数实际上参数压栈时多了一个this指针，所以匹配时会做类型检查
	typedef void (Test::*MEMBERFUNC) (); 

	// 示例2，类内部的typeDef函数声明，属于Test成员，声明时必须加Test声明作用域，且赋值的函数必须不为Test成员
	typedef void(*GLOBALFUNC) (); 

	Test() { m_iMember = 0; }
	~Test() {};

	void Print() 
	{
		std::cout << "this is member fun in Test\n";
	}

	int Simple(int i)
	{
		std::cout << "user input " << i << std::endl;
		return i;
	}

	int m_iMember;
};

//示例3，类外部的typeDef函数声明，不属于Test成员，声明时不能加Test声明作用域，赋值的函数必须为Test成员
typedef void (Test::*MEMBERFUNC2) (); 

//示例4，类外部的typeDef函数声明，不属于Test成员，声明时不能加Test声明作用域，赋值的函数必须不为Test成员
typedef void(*GLOBALFUNC)(); 

void GlobalFunc()
{
	printf("this is external GlobalFunc\n");
}

//这个模板函数，实际上可以适配所有相同类型的类成员函数；也就是说，根据类类型T的不同，调用不同类的成员函数
template<class T>
void GlobalTemplateFun(int j, T* obj, int (T::*pFun)(int))
{
	std::cout <<"全局模板函数输出："<< (obj->*pFun)(j)<<std::endl;
}

int main()
{
	Test t;
	Test::MEMBERFUNC pMemFunc = NULL;
	Test::GLOBALFUNC pGlobalFunc1 = NULL;
	MEMBERFUNC2 pMemFunc1 = NULL;
	GLOBALFUNC pGlobalFunc2 = NULL;

	//此句打印成员函数地址
	printf("the addr of Test::testfunc is %p\n", &Test::Print);

	//实例1：类中定义了成员函数指针类型，该类型应当赋值成员函数地址
	printf("demo1:\n");
	pMemFunc = &Test::Print;
	//pMemFunc();					//无法输出，pfunc的实际指向是类的成员，必须依赖类的对象或者静态化来输出；
	(t.*pMemFunc)();				//.*运算符为成员函数的解除引用
	//pMemFunc = &GlobalFunc;		//无法转换，赋值函数必须为类成员类型
	
	//实例2：类中定义了全局函数指针类型，该类型应当被赋值全局函数地址
	printf("demo2:\n");
	//pGlobalFunc1 = &Test::Print;	//无法转换，赋值函数必须为全局void (*)()类型，不能为类成员
	pGlobalFunc1 = &GlobalFunc;		//&可用可不用，全局函数名表示函数地址
	pGlobalFunc1();	//可以输出

	//实例3：类外定义了成员函数指针类型，该类型应当赋值成员函数地址
	printf("demo3:\n");
	pMemFunc1 = &Test::Print;
	//pMemFunc1();					//无法编译，因为pFunc1本质来讲是个成员函数
	(t.*pMemFunc1)();				//借助类对象进行输出
	//pMemFunc1 = GlobalFunc;		//无法转换，全局函数无法赋值给成员函数指针

	//实例4：全局函数指针应该被赋值全局函数地址
	printf("demo4:\n");
	//pGlobalFunc2 = &Test::Print;	//无法转换，全局函数地址无法赋给成员函数指针
	//pGlobalFunc2();				//可以输出，但注意测试并没有被赋值
	pGlobalFunc2 = &GlobalFunc;
	pGlobalFunc2();

	//接下来，我们看看如何给一个成员变量指针赋值
	//成员变量的地址是多少呢?成员变量在每个类对象中都有副本，因此每个对象的成员变量均有地址
	printf("the addr of t.m_iMember is %p\n", &t.m_iMember);
	int (Test::* pMemFunc2)(int);
	pMemFunc2 = &Test::Simple;
	int Test::* pInt;		//类中的成员变量
	pInt = &Test::m_iMember;
	t.*pInt = 3;			//也可以写成(&t)->*pInt = 3;	
	(t.*pMemFunc2)(t.*pInt);
	//GlobalTemplateFun(8, &t, &Test::Simple);	//这是一种简单写法
	GlobalTemplateFun(8, &t, pMemFunc2);	

	return 0;
}