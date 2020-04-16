//本文件主要讨论非约束的模板友元函数
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

template<class T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T & i):item(i){}
	template<class C,class D> friend void show(C & c, D & d);
};

template<class C, class D>
void show(C & c, D & d)
{
	cout << c.item << ", " << d.item << endl;        //这是颇为经典的一个使用方法，友元函数获得了和类成员函数相同的访问权限，
                                                     //因为友元函数没有成员函数默认的this指针，所以使用了直接成员运算符
}

int main()
{
	ManyFriend<int> hfil(10);
	ManyFriend<int> hfil2(20);
	ManyFriend<double> hfdb(10.5);
	cout << "hfi1,hfi2:";
	show(hfil, hfil2);
	cout << "hfdb,hfi2:";
	show(hfdb, hfil2);
	return 0;
}
