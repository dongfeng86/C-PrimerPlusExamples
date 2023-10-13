// RegularExpression.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <regex>
#include <assert.h>

int main()
{
	std::regex reg("<.*>.*</.*>");
	bool ret = std::regex_match("<html>value</html>", reg);
	assert(ret);

	ret = std::regex_match("<xml>value<xml>", reg);
	assert(!ret);

	std::regex reg1("<(.*)>.*</\\1>");
	ret = std::regex_match("<xml>value</xml>", reg1);
	assert(ret);

	ret = std::regex_match("<header>value</header>", std::regex("<(.*)>value</\\1>"));
	assert(ret);

	// 使用basic文法
	std::regex reg2("<\\(.*\\)>.*</\\1>", std::regex_constants::basic);
	ret = std::regex_match("<title>value</title>", reg2);
	assert(ret);
}
