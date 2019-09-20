#include<cfloat>
#include<iostream>
#include <cmath>

int main()
{
	//using namespace std;
	//cout.setf(ios_base::fixed, ios_base::floatfield);
	//float tub = 10 / 3.0;
	//double mint = 10 / 3.0;
	//const float millin = 1.0e6;

	//float mmmm = 123456789.123456;
	//cout << "现在输入另外一个值：\n";
	//cout << mmmm;
	//cout << endl;

	//float sum1 = 1234567 ;
	//float sum2 = 55.123456;
	//float sum = 1234567890;
	//cout << "来看看sum的最终结果：" << sum << endl;

	//cout << "tub=" << tub;
	//cout << ", amillion tubs=" << millin*tub;
	//cout << ",\nand ten million tubs=";
	//cout << 1000 * millin*tub << endl;

	//cout << "mint=" << mint << " and a million mints=";
	//cout << 10000*millin*mint << endl;
	//return 0;

	using std::cout;
	using std::cin;
	cout << "12345678901234567890\n";
	char ch = 'K';
	int t = 273;
	cout << ch << ":\n";
	cout << t << ":\n";
	cout << -t << ":\n";

	double f1 = 1.200;
	cout << f1 << ":\n";
	cout << (f1 + 1.0 / 9.0) << ":\n";

	double f2 = 1.67E2;
	cout << f2 << ":\n";
	f2 += 1.0 / 9.0;
	cout << f2 << ":\n";
	cout << (f2*1.0E4) << ":\n";

	double f3 = 2.3e-4;
	cout << f3 << ":\n";
	cout << f3 / 10 << ":\n";

	//不同进制的输出
	cout << "现在，我们来看看不同进制整数输出的效果。\n";
	cout << "enter an integer:\n";
	int n;
	cin >> n;
	while (cin.get() != '\n')
		continue;
	//首先是十进制
	cout << "n\tn*n\n";
	cout << n << '\t' << n*n << "(decimal)\n";
	//其次是十六进制
	cout <<std:: hex;
	cout << n << '\t' << n*n << "(hexadecimal)\n";
	//然后是八进制
	cout << std::oct << n << '\t' << n*n << "(octal)\n";
	//再切换为十进制
	cout << std::dec << n << '\t' << n*n << "(decimal)\n";

	//接下来，我们看看字段宽度怎么调整
	int w = cout.width(30);                      //注意，width方法仅仅影响下一个输出项目
	cout.fill('*');
	cout << "default field width=" << w << ":\n";
	cout.width(5);
	cout << "N" << ':';
	cout.width(8);
	cout << "N*N" << ":\n";

	for (long i = 1; i <= 100; i *= 10)
	{
		cout.width(5);
		cout << i << ':';
		cout.width(8);
		cout << i*i << ":\n";
	}

	//浮点型的精度设置
	float pricel = 20.40;
	float price2 = 1.9+ 8.0 / 9.0;

	//默认情况下，浮点型被显示为6位（含小数部分），末尾的0不显示
	cout << "\"Furry Friends\" is $" << pricel << "!\n";
	cout << "\"fiery fiends\" is $" << price2 << "!\n";

	//注意在默认模式下，精度是指显示的总位数；精度设置完以后，一直有效
	cout.precision(2);
	cout << "\"Furry Friends\" is $" << pricel << "!\n";
	cout << "\"fiery fiends\" is $" << price2 << "!\n";

	//显示末尾小数点
	cout << "这次，我们设置一个小数点精度:\n";
	cout.precision(4);
	cout.setf(std::ios_base::showpoint);
	cout << "\"Furry Friends\" is $" << pricel << "!\n";
	cout << "\"fiery fiends\" is $" << price2 << "!\n";

	//利用setf进行格式设置
	cout.setf(std::ios_base::left, std::ios_base::adjustfield);
	cout.setf(std::ios_base::showpos);
	cout.setf(std::ios_base::showpoint);
	cout.precision(3);
	cout.fill(' ');

	std::ios_base::fmtflags old = cout.setf(std::ios_base::scientific, std::ios_base::floatfield);
	cout << "Left Justification:\n";
	long lCount;
	for (lCount = 1; lCount <= 41; lCount += 10)
	{
		cout.width(4);
		cout << lCount << "|";
		cout.width(12);
		cout << sqrt(double(lCount)) << "|\n";
	}

	//change to internal justification
	cout.setf(std::ios_base::internal, std::ios_base::adjustfield);
	cout.setf(old, std::ios_base::floatfield);

	cout << "internal Justification:\n";
	for (lCount = 1; lCount <= 41; lCount += 10)
	{
		cout.width(4);
		cout << lCount << "|";
		cout.width(12);
		cout << sqrt(double(lCount)) << "|\n";
	}

	//use right justification ,fixed notation
	cout.setf(std::ios_base::right, std::ios_base::adjustfield);
	cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	cout << "Right Justification:\n";
	for (lCount = 1; lCount <= 41; lCount += 10)
	{
		cout.width(4);
		cout << lCount << "|";
		cout.width(12);
		cout << sqrt(double(lCount)) << "|\n";
	}

	return 0;
}
