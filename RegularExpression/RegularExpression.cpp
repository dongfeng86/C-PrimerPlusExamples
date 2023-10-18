// RegularExpression.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <regex>
#include <assert.h>

int main()
{
	//一 简单的匹配
	std::regex regCaseSensitive("<h.*>.*</.*>");
	bool ret = std::regex_match("<Html>value</html>", regCaseSensitive);
	assert(!ret);

	ret = std::regex_match("<xml>value<xml>", regCaseSensitive);
	assert(!ret);

	std::regex regCaseInsensitive("<h.*>.*</.*>", std::regex_constants::icase);
	ret = std::regex_match("<Html>value</html>", regCaseInsensitive);
	assert(ret);

	std::regex reg1("<(.*)>.*</\\1>");
	ret = std::regex_match("<xml>value</xml>", reg1);
	assert(ret);

	ret = std::regex_match("<header>value</header>", std::regex("<(.*)>value</\\1>"));
	assert(ret);

	// 使用basic文法
	std::regex reg2("<\\(.*\\)>.*</\\1>", std::regex_constants::basic);
	ret = std::regex_match("<title>value</title>", reg2);
	assert(ret);

	//二 获取匹配结果
	std::cmatch m;
	ret = std::regex_match("<xml>value</xml>", m, std::regex("<(.*)>(.*)</(\\1)>"));
	if (ret)
	{
		std::cout << m.str() << std::endl;
		std::cout << m.length() << std::endl;
		std::cout << m.position() << std::endl;
	}

	std::cout << "----------------" << std::endl;

	// 遍历匹配内容
	//第一种遍历方式
	for (auto i = 0; i < m.size(); ++i)
		std::cout << m[i].str() << " " << m.str(i) << std::endl;
	std::cout << "----------------" << std::endl;
	//第二种遍历方式
	for (auto pos = m.begin(); pos != m.end(); ++pos)
		std::cout << *pos << std::endl;

	std::cout << "----------------" << std::endl;

	// 三 使用搜索
	// 获取一个搜索结果
	std::regex regSearch("<(.*)>(.*)</(\\1)>");
	std::cmatch mSearch;
	bool ret2 = std::regex_search("123<xml>value</xml>456<test>something</test>", mSearch, regSearch);
	if (ret2)
	{
		for (auto& elem : mSearch)
			std::cout << elem << std::endl;
	}
	std::cout << "prefix:" << mSearch.prefix() << std::endl;
	std::cout << "suffix:" << mSearch.suffix() << std::endl;

	// 获取所有搜索结果
	std::cout << "----------------" << std::endl;
	std::regex regSearch2("<(.*)>(.*)</(\\1)>");
	std::string content("123<xml>value</xml>456<widget>center</widget>hahaha<vertical>window</vertical>the end");
	std::smatch mSearch2;
	auto pos = content.cbegin();
	auto end = content.cend();
	for (; std::regex_search(pos, end, mSearch2, regSearch2); pos = mSearch2.suffix().first)
	{
		std::cout << "----------------" << std::endl;
		std::cout << mSearch2.str() << std::endl;
		std::cout << mSearch2.str(1) << std::endl;
		std::cout << mSearch2.str(2) << std::endl;
		std::cout << mSearch2.str(3) << std::endl;
	}

	std::cout << "----------------" << std::endl;

	// 四、切割
	std::string mail("123@qq.vip.com,456@gmail.com,789@163.com,abcd@my.com");
	std::regex regToken(",");
	std::sregex_token_iterator itPos(mail.begin(), mail.end(), regToken, -1);
	decltype(itPos) itEnd;
	for (; itPos != itEnd; ++itPos)
	{
		std::cout << itPos->str() << std::endl;
	}

	// 五、替换
	char data[] = "he...ll..o, worl..d!";
	std::regex regReplace("\\.");
	// output: hello, world!
	std::cout << std::regex_replace(data, regReplace, "");

	// 六、匹配邮箱
	std::string str = "123@qq.vip.com, \
	       456@gmail.com, \
           789@163.com.cn.mail, \
           abcd@my.com, \
           Abc0_@aAa1.123.456.789 \
           haha@163.com.cn.com.cn";
	std::regex regMail("[\\w.%+-]+@[\\w.-]+(\\.[a-zA-Z]+){1,3}");
	std::sregex_iterator posMail(str.cbegin(), str.cend(), regMail);
	decltype(posMail) endMail;
	for (; posMail != endMail; ++posMail)
	{
		std::cout << posMail->str() << std::endl;
	}

	//如何捕捉正则表达式所抛出异常
	try
	{
		// 正则表达式错误导致异常,需要捕获,否则会程序会崩溃
		std::regex re("[a-b][a");
	}
	catch (const std::regex_error& e)
	{
		std::cout << "regex error caught:" << e.what() << std::endl;
		if (e.code() == std::regex_constants::error_brack)
		{
			std::cout << "The code was error!\n";
		}
	}
}

