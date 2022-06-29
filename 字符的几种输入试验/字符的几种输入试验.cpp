// 字符的几种输入试验.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <tchar.h>

int main()
{

	//整形字面值（常量）是显式书写的常量。C++能够以三种不同的计数方式来书写整数：基数为10、基数为8、基数为16.
	//C++使用前1或者2位来判断数字常量的基数。如果第一位为1~9，则基数为10；如果第一位是0，第2位是1~7，则基数为8；
	//如果前两位为0x或者0X，则基数为16.
	int int1, int2, int3;
	int1 = 0x41;	//十六进制字面值
	int2 = 0101;	//八进制字面值
	int3 = 65;		//十进制字面值

	//字符常量的五种表示方式
	char ch1, ch2, ch3, ch4;
	wchar_t ch5;
	//方式1：
	ch1 = 'A';	
	//方式2
	ch2 = 65;	
	//方式3：用八进制转义序列，格式为 \ooo，包含一个反斜杠和最多3位八进制数字。注意：这个八进制前面的0可以省略
	//Octal escape sequences, specified in the form \ooo, consist of a backslash and one, two, or three octal characters. 
	ch3 = '\101';
	//方式4：用16进制转义序列，格式为 \xhhh，包含一个反斜杠和若干十六进制数字。不像八进制序列，十六进制的长度没有限制。
	//Hexadecimal escape sequences, specified in the form \xhhh, consist of the characters \x followed by a sequence of hexadecimal digits. 
	//Unlike octal escape constants, there is no limit on the number of hexadecimal digits in an escape sequence. 
	ch4 = '\x41';
	//方式5：使用通用字符名
	//C++有一种表示UNICODE字符的机制，使用通用字符名。通用字符名的用法类似于转义序列。通用字符名可以用\u或者\U开头。
	//\u后面是8个十六进制位，\U后面则是16个十六进制位。这些位表示的是字符的ISO 10464码点。
	ch5 = _T('\u33A1');	//注意，等号右边的字符常量必须是宽字符常量，否则编译器会赋一个错误值
}
