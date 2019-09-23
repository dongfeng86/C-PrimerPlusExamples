/*
本文档主要是使用了流状态位。
流状态位有3种
badbit：to record a loss of integrity of the stream buffer.（无法诊断的错误）
eofbit, to record end-of-file while extracting from a stream.（文件结尾）
failbit, to record a failure to extract a valid field from a stream.（未读取到预期的字符）。

fail()方法：如果badbit或者failbit被设置，则fail()方法返回true。
*/

/*
一般模拟eof的输入:
在windows平台，是在一个新行的开头输入ctrl + z
在unix环境下，是在一个新行的开始出输入ctrl + D
*/
#include<iostream>
#include<exception>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter numbers:";
	int sum = 0;
	int input=0;
	while (cin >> input)
	{
		sum += input;
	}
	cout << "Last value entered=" << input << std::endl;
	cout << "Sum=" << sum << endl;

	/*这里面存在非常关键的一点，fail()在faibit,badbit或eofbit被设置时，会返回true.
	所以，这里要排除到达文件结尾这种情况*/
	if (cin.fail() && !cin.eof())
	{
		//设置流状态位有一个非常重要的后果，流将对后面的输入或者输出关闭，直到位被清除。
		//clear就是清楚这个状态位
		cin.clear();                 
		while (cin.get()!='\n')                 //清除这一行非法字符后面的字符
			continue;                           //get(char &)或者get(void)提供不跳过空白的字符输入功能
	}
	else if(cin.eof())
	{
		cout << "I can't go on!\n";
		exit(1);
	}
	cout << "Now enter a new number:\n";
	cin >> input;
	cout << "what you input is :" << input << endl;
}