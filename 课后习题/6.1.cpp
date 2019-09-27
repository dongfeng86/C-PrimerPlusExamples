/*
获取一段输入字符串，将大写字母转换为小写，将小写字符转换为大写
*/

#include<iostream>
#include<string>
#include<cctype>
#include <algorithm>

int main()
{
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;

	string strInput;
	cout << "请输入一串字符串，直到@为止；输入quit退出。\n";
	while (std::getline(cin, strInput, cin.widen('@')) && "quit"!=strInput)
	{
		////对一个string类型字符串进行大小写转换
		//std::transform(strInput.begin(), strInput.end(), strInput.begin(), ::tolower);
		//cout << "你输入的是：\n";
		//cout << strInput;
		while (cin.get() != '\n')
			continue;
		string::iterator it;
		for (it = strInput.begin(); it != strInput.end(); it++)
		{
			//if (*it >= 'A' && *it <= 'Z')
			//	*it += 32;
			//else if (*it >= 'a' && *it <= 'z')
			//	*it -= 32;
			//以下方法是在cctype中实现的函数，用来识别大小写以及转换大小写。
			if (islower(*it))
				*it = toupper(*it);
			else if (isupper(*it))
				*it = tolower(*it);
		}
		cout << "将字符串中大写字母转变为小写，将小写字母转变为大写的结果：\n";
		cout << strInput << endl;
		cout << "请输入一串字符串，直到@为止；输入quit退出。\n";
	}

	return 0;
}