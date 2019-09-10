/*
本文件的作用是使用RTTI（运行阶段类型识别），主要有dynamic_cast，typeid运算符以及type_info结构体等。
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
using namespace std;

class Grand
{
private:
	int hold;
public:
	Grand(int h=0):hold(h){}
	virtual void Speak() const { cout << "I am a grand class!\n"; }
	virtual int Value() const { return hold; }
};

class Superb :public Grand
{
public:
	Superb(int h=0):Grand(h){}
	void Speak() const { cout << "I am a superb class!\n"; }
	virtual void Say() const {
		cout << "I hold the superb value of " << Value() << "!\n";
	}
};

class Magnificent :public Superb
{
private:
	char ch;
	Magnificent(){}
public:
	Magnificent(int h/*=0*/,char cv='A'):Superb(h),ch(cv){ }
	void Speak() const { cout << "I am a magnificent class!\n"; }
	void Say() const { cout << "I hold the character " << ch << " and the integer " << Value() << "!\n"; }
};

Grand * GetOne();
int main()
{
	//Magnificent temp;
	srand(time(0));
	Grand * pg;
	Superb * ps;
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		//The result of typeid is a const  type_info&. The value is a reference to a type_info 
		//object that represents either the type-id or the type of the expression, depending on 
		//which form of typeid is used. 
		//typeid返回一个type_info类，这个类包含name()成员，通常返回类的名称“class+类名称"
		cout << "now processing type " << typeid(*pg).name() << ".\n";
		pg->Speak();
		if (ps = dynamic_cast<Superb *> (pg))             //转换失败了，返回null
			ps->Say();
		if (typeid(Magnificent) == typeid(*pg))            //type_info重载了==和!=运算符
			cout << "Yes,you are really magnificen.\n";
	}
	return 0;
}

Grand * GetOne()
{
	Grand *p=nullptr;
	switch (rand()%3)
	{
	case 0:
		p = new Grand(rand() % 100);
		break;
	case 1:
		p = new Superb(rand() % 100);
		break;
	case 2:
		p = new Magnificent(rand() % 100, 'A' + rand() % 26);
		break;
	default:
		break;
	}
	return p;
}