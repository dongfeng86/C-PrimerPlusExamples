#include<iostream>

struct Inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	using namespace std;
	Inflatable guest[3]=
	{
		{"badi",80,9.2},
		{"hah",29,3.2},
		{"ming",39,4.2}
	};                                      //这是一个初始化语句，因此后面加分号

	for (int i = 0; i < 3; i++)
	{
		cout << "顾客的姓名是：" << guest[i].name << ";顾客要求的数量是：" << guest[i].volume << ";总的价格为:" << guest[i].price << endl;
	}
	cout << "以上是所有顾客信息." << endl;

	cout << "\n现在，让我们试一下结构体的赋值。" << endl;
	guest[2] = guest[1];
	for (int i = 0; i < 3; i++)
	{
		cout << "顾客的姓名是：" << guest[i].name << ";顾客要求的数量是：" << guest[i].volume << ";总的价格为:" << guest[i].price << endl;
	}
	cout << "以上是更新后顾客信息." << endl;
}