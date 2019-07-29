#include<iostream>
void InputNumAndChar();
using namespace std;
void ReaptedlyInput();

int main()
{
	ReaptedlyInput();
	InputNumAndChar();
	return 0;

	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	//第一种方式，利用cin.getline()进行处理
	cout << "Enter your name:\n";
	cin.getline(name, ArSize);                             //最多读取ArSize-1个字符，自动在结尾添加'\0';读取换行符并且将它丢弃
	cout << "enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";

	//第二种方式，利用cin.get()进行处理
	cout << "\n\nnow we will take another way!\n";
	cout << "enter your name:" << endl;
	cin.get(name, ArSize).get();                           //cin.get()可以读取下一个字符，即使是换行符
	cout << "enter your favorite dessert:\n";
	cin.get(dessert, ArSize).get();
	cout << "I have another delicious " << dessert << " for you, " << name << endl;

	return 0;
}


void InputNumAndChar()
{

	cout << "what year was your house built?\n";
	int year;
	cin >> year;                                                //cin会跳过空字符，读取字符将换行符留在输入队列中
	cin.get();                                                  //读取留下来的回车符
	cout << "what is its street address\n";
	char address[80];
	cin.getline(address, 80);                                   //cin.get遇到空行时将设置失效位，但是cin.getline()遇到空行时不设置失效位；
	cout << "year built: " << year << endl;
	cout << "address: " << address << endl;
	cout << "done!\n";

}

void ReaptedlyInput()
{
	//另一种方法
	//char c;
	//c = cin.get();
	//while (cin.fail()==false)
	//{
	//	cout << c << endl;
	//	while (cin.get() != '\n')
	//		continue;
	//	cout << "请输入下一个字符" << endl;
	//	c = cin.get();
	//}


	//cin会跳过空白字符
	//char c;
	//cout << "please input a char:\n";
	//cin >> c;
	//while (cin.fail()!=true)
	//{
	//	cout << "你输入的是：" << c << endl;
	//	cin >> c;
	//}

	char ch;
	int count=0;
	cout << "enter a string:" << endl;
	while (cin.get(ch))                                          //cin.get()和cin.get(ch)会读取空格，制表位，以及换行符
	{
		cout << ch;
		count++;
	}
	cout << "你一共输入了" << count << "字符" << endl;
}

