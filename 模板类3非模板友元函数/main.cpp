#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template<class T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T & i) :item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void counts();
	friend void reports(HasFriend<T> &);
};

//每一个具体化都会有他自己的静态数据；注意这里竟然初始化的是一个private型静态变量
template<class T>
int HasFriend<T>::ct = 0;

//非模板友元函数
void counts()
{
	cout << "int count:" << HasFriend<int>::ct << ";";
	cout << "double count: " << HasFriend<double>::ct << endl;
}

void reports(HasFriend<int> & hf)
{
	cout << "hasFriend<int>:" << hf.item << endl;
}

void reports(HasFriend<double> & hf)
{
	cout << "hasFriend<double>:" << hf.item << endl;
}

int main()
{
	cout << "no objects declared:";
	counts();                         //类的静态成员是属于类的，哪怕没有生成类对象，静态成员依然可以访问；在访问前初始化类的静态成员函数

	HasFriend<int> hfil(10);
	cout << "after hfil declared:";
	counts();
	HasFriend<int> hfi2(20);
	cout << "after hfi2 declared:";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "after hfdb declared:";
	counts();

	reports(hfil);
	reports(hfi2);
	reports(hfdb);

	return 0;
}