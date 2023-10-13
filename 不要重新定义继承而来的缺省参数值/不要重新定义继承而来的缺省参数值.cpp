// 不要重新定义继承而来的缺省参数值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class Shape {
public:
	enum EShapeColor { kRed, kGreen, kBlue };
	virtual void draw(EShapeColor color = kRed) const = 0;
};

class Rectangle :public Shape {
public:
	virtual void draw(EShapeColor color = kGreen) const;
};

void Rectangle::draw(EShapeColor color /*= kGreen*/) const
{
	cout << "call Rectangle::draw, color=" << color << endl;
}

class Circle :public Shape {
public:
	virtual void draw(EShapeColor color) const;
};

void Circle::draw(EShapeColor color) const
{
	cout << "call Circle::draw, color=" << color << endl;
}

int main()
{
	Shape* ps;
	Shape* pc = new Circle;
	Shape* pr = new Rectangle;

	pc->draw();
	pr->draw();

	cout << "next is interesting" << endl;
	Rectangle* pr2 = new Rectangle;
	pr2->draw();

	Circle* pc2 = new Circle;
	//pc2->draw(); //此句编译时报错，因此pc2的静态类型是Circle，而Circle::draw没有缺省参数
}
