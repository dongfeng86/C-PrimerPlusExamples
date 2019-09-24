//���ļ���Ҫ������һ��bad_cast�쳣��out_of_range��׼�쳣���Լ��ող�������һ�����飬��������й����г��ִ���
//���������������ں����׳��쳣�������쳣���������£�����Ų�����������������쳣�����·�����н��ˡ�
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
		cout << "������һ���ַ�\n";
		int m;
		cin >> m;
		arr[m] = 8;

		/*�����v.at(100)����v[100]����s.at(100)����s[100]������Ͳ��������쳣�������ܵ��³����������
		��Ϊ at ��Ա���������±�Խ�粢�����쳣���� operator[] �򲻻ᡣoperator [] ��� at �ĺô�
		���ǲ����ж��±��Ƿ�Խ�磬���ִ���ٶȸ��졣*/
		//���ֱ�����±��������������ܻ����
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