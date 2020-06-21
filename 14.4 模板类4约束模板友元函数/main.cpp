/*模板类的约束模板友元函数，这使得模板类中的友元函数具有的模板的特性，更适合模板类的要求。
模板类的约束模板友元函数，其定义步骤分为3步：
	1：在类定义的前面声明每个模板函数；
	2：在函数中将模板函数声明为友元函数；
	3：为友元函数提供模板定义
*/
#include <iostream>
using std::cout;
using std::endl;

//在类定义的前面必须声明每个模板函数
template <class T> void counts();
template <class T> void report(T &);

//模板类
template<class TT>
class HasFriend
{
private:
	TT item;
	static int ct;
public:
	HasFriend(const TT & i) :item(i) { ct++; }
	~HasFriend() { ct--; }

	//以下两句并不是说要生成模板函数的具体化，而是说该具体化的模板函数是友元函数。编译器给出具体化的定义实在main函数调用模板函数时
	friend void counts<TT>();                       
	friend void report<HasFriend<TT>>(HasFriend<TT> &);
};

template<class TT>
int HasFriend<TT>::ct = 0;                          //注意，即便没有生成类对象，也可以访问静态成员变量；

template<class T>
void counts()
{
	cout << "template size:" << sizeof(HasFriend<T>) << ";";
	cout << "template counts():" << HasFriend<T>::ct << endl;
}

template<class T>
void report(T & hf)
{
	cout << hf.item << endl;
}

int main()
{
	counts<int>();
	HasFriend<int> hfil(10);               //类模板，必须显式的提供所需的参数类型；这和常规的函数模板并不相同，函数模板能够通过参数类型调用正确的函数
	HasFriend<int> hfi2(20);
	HasFriend<double> hfdb(10.5);

	report<HasFriend<int>>(hfil);          //该代码等价于 report(hfil);调用函数可以显示指定类型参数
	report(hfi2);
	report<HasFriend<double>>(hfdb);       //该代码等价于 report(hfdb);调用函数可以显示指定参数类型
	cout << "counts<int>() output:\n";
	counts<int>();
	cout << "counts<double>() output:\n";
	counts<double>();

	return 0;
}
