
#include<iostream>
#include<iterator>
#include<vector>
#include<string>
#include <algorithm>

void OutPut(const std::string & s) { std::cout << s << " "; }

int main()
{
	using namespace std;
	
	//C++支持将超尾的概念用于数组，这很重要。
	string arS1[4] = { "fine","fish","fashion","fate" };
	string arS2[2] = { "busy","bats" };
	string arS3[2] = { "silly","singers" };
	vector<string> arWords(4);

	//复制普通数组到vector数组当中
	cout << "now let us see the elements in vector:\n";
	copy(arS1, arS1 + 4, arWords.begin());                     //在C++中，数组最后一个元素后面的地址是可用的。也就是说，C++将超尾的概念用于了普通数组。
	for_each(arWords.begin(), arWords.end(), OutPut);
	cout << endl;
	//另外一种输出的办法,利用输出迭代器
	cout << "now ,the vector array will be shown on screen by ostream_iterator.\n";
	ostream_iterator<string,char> out_iter(cout, " ");
	/*注意，copy函数假设假设第三个参数具有足够多的空间，能够容纳这些值，
	即copy不能自动根据发送值调整目标容器的长度。解决办法是采用插入迭代器*/
	copy(arWords.begin(), arWords.end(), out_iter);
	cout << endl;

	//反向迭代器的使用
	cout << "if we reverse the vector,as shown in below:\n";
	for_each(arWords.rbegin(), arWords.rend(), OutPut);
	cout << endl;
	//另外一种反向迭代器的使用方法
	cout << "Explicit use of reverse iterator.\n";
	vector<string>::reverse_iterator ri;                       //显示的使用反向迭代器
	for (ri = arWords.rbegin(); ri != arWords.rend(); ri++)
	{
		OutPut(*ri);
	}
	cout << endl;
	//使用C++11中基于范围的for循环
	cout << "现在使用基于范围的for循环\n";
	for (auto x : arWords)
		OutPut(x);
	cout << endl;

	//匿名尾部插入迭代器
	cout << "通过构建尾部插入迭代器，向arWords尾部插入arS2的前两个元素\n";
	copy(arS2, arS2 + 2, back_insert_iterator<vector<string>>(arWords));
	for_each(arWords.begin(), arWords.end(), OutPut);
	cout << endl;

	//匿名的插入迭代器
	cout << "通过构建插入迭代器，向arWords中插入arS3的前两个元素\n";
	//copy(arS3, arS3 + 2, arWords.end());         //这一句是错的，程序会因为内存违规而崩溃
	copy(arS3, arS3 + 2, insert_iterator<vector<string>>(arWords, arWords.begin()));
	for_each(arWords.begin(), arWords.end(), OutPut);
	cout << endl;

	//下面的代码是错的，因为vector<string>没有push_front方法
	////匿名的头部插入迭代器
	//cout << "通过构建头部插入迭代器，向arwords中插入arS3的前两个元素\n";
	//copy(arS2, arS2 + 1, front_insert_iterator<vector<string>>(arWords));
	//for_each(arWords.begin(), arWords.end(), OutPut);
	//cout << endl;

	return 0;
}