/*
该工程主要说明的C++的异常机制。
如果程序运行阶段错误，例如，请求过多内存，除以0，程序可能会崩溃。程序员应当尽力防止出现
这种情况，但是C++的异常机制提供了另外一种选择。例如，对可能的错误情况调用abort()函数，
中止程序；或者采用try...catch模块。
try...catch模块通过throw语句返回异常类型（字符串或者是类类型），然后通过catch模块对错误
信息进行输出或者处理。
try...catch模块实际上类似于goto，当出现异常时，直接跳转到一个标签语句。这样的话，你的程序不是
崩溃，而是继续执行。
*/

#pragma once
#include<iostream>

class bad_hmean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a=0,double b=0):v1(a),v2(b){}
	void mesg();
};

inline void bad_hmean::mesg()
{
	std::cout << "hmean(" << v1 << ", " << v2 << "): " << " invalid arguments:a=-b\n";
}

class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(double a=0,double b=0):v1(a),v2(b){}
	const char * mesg();
};

inline const char * bad_gmean::mesg()
{
	return "gmean() arguments should be >=0\n";
}


