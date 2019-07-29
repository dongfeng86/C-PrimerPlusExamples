//编译的时候不包含这个文件

#define _NOCOMPILE_
#ifndef _NOCOMPILE_

#include "stcok.h"
#include <iostream>

int main()
{
	using namespace std;
	cout << "using constructors to create new objects\n";
	Stock stock1("nihoa", 12, 29);
	stock1.show();
	
	Stock stock2 = stock1;
	stock2.show();

	return 0;
}

#endif 