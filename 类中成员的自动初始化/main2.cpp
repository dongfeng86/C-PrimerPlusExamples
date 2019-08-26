#include <iostream>

class A {
public:
	int value;
};

class B {
public:
	int value;
	A a;
	B(){}
};

B b1;

int main() 
{
	using namespace std;
	B b2;
	cout << b1.value << "\t" << b1.a.value << endl;
	cout << b2.value << "\t" << b2.a.value << endl;
	//cout << b2.value << "\t" << b2.a.value << endl;
	return 0;
}