#include<iostream>	
#include<string>
//#include<cstring>

int main()
{
	using namespace std;
	char charr[20];
	string str;

	//string对象和C-风格对象如何查询字符的数量
	cout << "length of string in charr before input:\n"
		<< strlen(charr) << endl;                           //这里输出是31，因为strlen()会一直检索字符数直到遇到空字符
	cout << "length of string in str befor input: "
		<< str.length() << endl;
	cout << "enter a line of text:\n";
	cin.getline(charr, 20);
	cout << "you entered: " << charr << endl;
	cout << "enter anoter line of text:\n";
	getline(cin, str);
	cout << "you entered: " << str << endl;
	cout << "length of string in charr after input:"
		<< strlen(charr) << endl;
	cout << "length of string in str after input:"
		<< str.length() << endl;

	//string对象的部分操作
	string s1;
	string s2;

	s1 = "nihao，";
	s2 = "昝东峰";

	string s = s1 + s2;
	cout << s << endl;
	cout << "本句话一共有" << s.length() << "个字符";

	return 0;
}