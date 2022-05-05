#include<stdio.h>

int _stdcall AddTwo(int a, int b)
{
	return a + b;
}

class MyClass
{
private:
	int m;
public:
	void print()
	{
		printf("hello,world");
	}
};

int main()
{
	AddTwo(5, 6);
	MyClass my;
	my.print();
	return 0;
}