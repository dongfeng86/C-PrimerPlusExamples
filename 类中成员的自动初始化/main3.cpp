#include <iostream>
using namespace std;
class A
{
private:
	int n1;
	int n2;

public:
	A() :n2(0), n1(n2 + 2) {}

	void Print() {
		cout << "n1:" << n1 << ", n2: " << n2 << endl;
	}
};

int main3()
{

	A a;
	a.Print();

	double ar[] = { 5.6,7,8 };
	ar[8.9] = 4;

	return 1;
}