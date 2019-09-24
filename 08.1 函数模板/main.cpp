/*本文件是模板函数的使用方法介绍，特别着重强调了显示具体化/*/
#include <iostream>

//声明模板函数
template<class T>
void Swap(T &a, T &b);

struct Job
{
	char name[40];
	double salary;
	int floor;
};
void Show(Job & j);

//explicit specialization，显式具体化（特化），注意是是template <>开头的，并且Swap后面的<Job>是可选的
template <> void Swap<Job>(Job & j1, Job & j2);

//模板函数实例化，注意Swap后面的<int>是可选的。注意实例化不能在main()函数当中进行。
template void Swap<int>(int &, int &);
int main()
{
	//template void Swap<int>(int &, int &);        //注意，不能在此进行模板函数实例化，不允许在函数内部定义其他函数                   
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i,j= " << i << "," << j << ".\n";
	cout << "using complier-generated int swapper:\n";

	Swap(i, j);                                    //用的是通用模板，通过函数调用生成一个模板函数实例，也称隐式实例化
	cout << "now i,j=" << i << "," << j << ".\n";

	Job sue = { "Susan",730.6,7 };
	Job sidney = { "Sidney",760,9 };
	cout << "before job swapping:\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);                             //用的是具体化的模板
	cout << "after job swapping:\n";
	Show(sue);
	Show(sidney);
	return 0;
}

template<class T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void Swap<Job>(Job & j1, Job & j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(Job & j)
{
	using namespace std;
	cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}