// 单例模式探究.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//验证1
//如果在栈上分配这个对象，编译器会报错，因为栈上分配的作用域结束时会自动调用析构函数，而析构函数权限是私有的；
//在堆上分配内存可以，但是不能delete，因为析构函数时私有的
//
//class OnlyHeapClass
//{
//public:
//	OnlyHeapClass()
//	{}
//private:
//	~OnlyHeapClass() {}
//};
//
//int main()
//{
//	//OnlyHeapClass *p = new OnlyHeapClass;
//	//delete p;			//报错
//
//	//OnlyHeapClass m;	//报错
//}

//ver1.1 懒汉式单例模式，可自动释放内存
//class Singleton
//{
//private:
//	static Singleton* instance;
//private:
//	Singleton() { };
//	~Singleton() { };
//	Singleton(const Singleton&);
//	Singleton& operator=(const Singleton&);
//private:
//	class Deletor {
//	public:
//		~Deletor() {
//			if (Singleton::instance != NULL)
//				delete Singleton::instance;
//		}
//	};
//	static Deletor deletor;
//public:
//	static Singleton* getInstance() {
//		if (instance == NULL) {
//			instance = new Singleton();
//		}
//		return instance;
//	}
//};
//
//// init static member
//Singleton* Singleton::instance = NULL;


// version 1.2 懒汉式单例模式，可自动释放内存
class Singleton
{
private:
	Singleton() { };
	~Singleton() { 
		std::cout << "\n进入了destructor!" << std::endl;
	};
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
	static Singleton& getInstance() {
		static Singleton instance;
		return instance;
	}

	Singleton* getSingle()
	{
		Singleton mm;	//这个是可以调用析构函数的，这很奇怪；但是可能也是合理的，毕竟，这个对象能够在作用域中看见析构函数。
						//这仅仅是初步理解
		return &mm;
	}
};


int main()
{
	Singleton* pSingle = &Singleton::getInstance();

	//Singleton::getSingle();
	pSingle->getSingle();

}