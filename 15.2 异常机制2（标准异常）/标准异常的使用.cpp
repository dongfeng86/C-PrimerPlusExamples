//该文件主要是试了一下bad_cast异常和out_of_range标准异常，自己刚刚才明白了一件事情，如果在运行过程中出现错误，
//程序会崩溃，仅仅在函数抛出异常并且有异常处理的情况下，程序才不会崩溃，而是沿着异常处理的路径进行解退。
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Base
{
	virtual void func(){}
};

class Derived :public Base
{
public:
	void Print(){}
};

void PrintObj(Base & b)
{
	try {
		/*A null pointer value is converted to the null pointer value of the destination type by dynamic_cast.
		When you use dynamic_cast < type-id > ( expression ), if expression cannot be safely converted to 
		type type-id, the run-time check causes the cast to fail.
		The value of a failed cast to pointer type is the null pointer.
		A failed cast to reference type throws a bad_cast Exception.
*/
		Derived & rd = dynamic_cast<Derived &>(b);
		rd.Print();
	}
	catch (bad_cast & e)
	{
		cerr << e.what() << endl;
	}
}

int main()
{
	vector<int> v(10);
	double arr[10] = { 5,4,3 };                
	try 
	{
		cout << "请输入一个字符\n";
		int m;
		cin >> m;
		arr[m] = 8;

		/*如果将v.at(100)换成v[100]，将s.at(100)换成s[100]，程序就不会引发异常（但可能导致程序崩溃）。
		因为 at 成员函数会检测下标越界并拋出异常，而 operator[] 则不会。operator [] 相比 at 的好处
		就是不用判断下标是否越界，因此执行速度更快。*/
		//如果直接用下标运算符，程序可能会崩溃
		//v.at(100) = 100;
	}
	catch (out_of_range &e)
	{
		cerr << e.what() << endl;
	}

	Base b;
	PrintObj(b);
	return 0;
}