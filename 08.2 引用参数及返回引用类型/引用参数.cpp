#include<iostream>
#include<string>
using namespace std;
struct free_throws
{
	string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
	free_throws one = { "lifeng",13,14 };
	free_throws two = { "haifeng",7,9 };
	free_throws three = { "yinhe",10,16 };
	free_throws team = { "thro",0,0 };

	free_throws dup;
	
	set_pc(one);
	display(one);
	accumulate(team,two);

	/*
	注意accumulate函数的函数头，返回的是引用类型；这意味着返回的是最初传递给accumulate()的team对象。
	当返回引用类型时，最简单的办法是返回一个作为参数传递给函数的引用。
	如果accumulate返回一个结构，而不是结构的引用，则会把整个结构复制到一个临时位置，再将这个拷贝赋值给dup；效率太低。
	*/
	dup = accumulate(team, three);
	cout << "displaying team:\n";
	display(team);
	cout << "displaying dup after assignment:\n";
	display(dup);

}

void display(const free_throws & ft)
{
	cout << "name:" << ft.name << endl;
	cout << " made: " << ft.made << endl;
	cout << "attempts:" << ft.attempts << endl;
	cout << "percent:" << ft.percent << endl;
}

void set_pc(free_throws & ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f*float(ft.made) / float(ft.attempts);
	else
		ft.percent = 0;
}

/*引用参数是在参数类型后面加上&，引用类型的返回是在返回类型后面加上&*/
/*在C#中，引用参数前缀为ref，输出参数前缀为out*/
free_throws & accumulate(free_throws & target, const free_throws & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}



