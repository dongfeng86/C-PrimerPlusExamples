//#include<cstring>
#include "String.h"
#include<string>

std::string str;

using std::cin;
using std::cout;

int String::num_strings = 0;             //注意，没有statci关键字

int String::HowMany()
{
	return num_strings;
}

String::String(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str,len, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[4];
	str[0] = '\0';
	num_strings++;
}

/*
显示定义复制构造函数，不然系统会定义一个默认的，默认复制构造函数仅仅执行浅复制（就是逐个
复制非静态成员的值），如果是指针的话，仅仅复制指针的值，而不复制指针指向的内容
*/
String::String(const String & st)                 
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len+1, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;             //如果str是NULL的话，也可以
}

/*
显示定义赋值运算符，否则系统会生成默认的赋值运算符，但是，很不幸，赋值运算符仍然执行的是
浅赋值，就是逐个对非成员数据进行赋值，静态成员不受其影响*/
String & String::operator=(const String & st)     
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;

	//另外一种方式来实现,这个需要比较深入的理解
	char* psz = *((char**)&st);
	int iLenNew = sizeof(psz);

	str = new char[len + 1];
	strcpy_s(str, len+1,st.str);
	return *this;
	// TODO: 在此处插入 return 语句
}

String & String::operator=(const char * s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];

	//这是一个奇妙的函数，如果用指针做函数第一个参数的话，编译失败，只能用三个参数的这种重载函数。
	//如果第一个参数是个数组地址，没有问题，可以用两个参数的重载形式
	//另外，中间的缓冲区数目必须为元素数+1
	strcpy_s(str,len+1, s);                    
	return *this;
}

char & String::operator[](int i)
{
	return str[i];
}

const char & String::operator[](int i) const       //请注意，函数特征标区分const和非const参数；这个函数专门用来处理常量字符串
{
	return str[i];
}


//注意，以下全部都是友元函数了，不需要加作用域解析运算符
bool operator<(const String & st, const String & st2)
{
	return (std::strcmp(st.str, st2.str) < 0);
}

bool operator>(const String & st, const String & st2)
{
	return st2<st;
}

bool operator==(const String & st, const String & st2)
{
	return (std::strcmp(st.str,st2.str)==0);
}

ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

istream & operator >> (istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
	{
		continue;
	}
	return is;
}
