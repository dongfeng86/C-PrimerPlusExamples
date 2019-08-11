#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stack.h"

const int Num = 10;
int main()
{
	std::srand(std::time(0));       //产生随机数
	std::cout << "please enter stack size:\n";
	int iStackSize;
	std::cin >> iStackSize;
	Stack<const char *> st(iStackSize);

	/*这里有个奇妙的问题，字符串常量在编译器中实际是const char *类型，指针指向的内容为常量	；自己曾试图让指针数组为
	非常量类型，以期改变某个字符串的某个字符值，结果失败。	但是，字符串确实可以赋值给指向非const 类型的指针*/
	/*const*/ char * szIn[Num] = {
		"1:hank gilgmes",
		"2:KiKi Ishtar",
		"3:Betty Rocker",
		"4:Ian Flagranti",
		"5:wolgfang",
		"6:portia",
		"7:yoy",
		"8:Xaverie",
		"9:Juan Moore",
		"10:Misha Mache"
	};

	//以下两句错误，字符串本身为const char *类型，没有办法修改。
	//szIn[0][2] = 'g';
	//std::cout << szIn[0] << std::endl;

	const char * szOut[Num];
	int iProcessed = 0;
	int iNextin = 0;
	while (iProcessed < Num)
	{
		if (st.IsEmpty())
			st.push(szIn[iNextin++]);
		else if (st.IsFull())
			st.pop(szOut[iProcessed++]);
		else if (std::rand() % 2 && iNextin < Num)
			st.push(szIn[iNextin++]);
		else
			st.pop(szOut[iProcessed++]);
	}

	for (int i = 0; i < Num; i++)
	{
		std::cout << szOut[i] << std::endl;
	}

	std::cout << "Bye\n";
	return 0;
}