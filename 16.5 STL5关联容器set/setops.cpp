//setops.cpp--该文件主要研究set容器的使用方法
/*
关联容器set的键与值是相同的，键是唯一的。multiset类似于set，但是他的键不是唯一的
*/
#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>

int main()
{
	using namespace std;
	const int N = 6;
	string s1[N] = { "buffoon","thinkers","for","heavy","can","for" };
	string s2[N] = { "metal","any","food","elegant","deliver","for" };

	set<string> A(s1, s1 + N);                         //set容器的构造方法，仍然可以使用两个迭代器进行初始化
	set<string> B(s2, s2 + N);                         //注意，构造完毕后，元素均按照顺序进行排列。

	ostream_iterator<string, char> out(cout, " ");     //构造通用的输出迭代器
	cout << "Set A:";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "Set B:";
	copy(B.begin(), B.end(), out);
	cout << endl;
	cout << "Union of A and B:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);              //计算两个集合的并集
	cout << endl;

	cout << "intersection of A and B:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);        //计算两个集合的交集
	cout << endl;

	cout << "Difference of A and B:\n";                                   //计算两个集合的差集
	set_difference(A.begin(),A.end(),B.begin(),B.end(),out);
	cout << endl;

	set<string> C;
	cout << "Set C:\n";

	//注意，这里求出了两个集合的并集以后，将结果赋给了集合C；但是在set容器中，将键看作是常量，无法赋值；
	//另外，set_union将覆盖容器中已有的数据，并要求容器有足够的空间容纳新信息，C是空的，不能满足此要求。
	//因此，需要使用插入迭代器来进行插入
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy");
	C.insert(s3);                                            //集合的插入操作
	cout << "Set C after insertion:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "showing a range:\n";
	//lower_bound 将返回第一个不小于键参数的成员；upper_bound将返回第1个大于键参数的成员
	//lower_bound 将返回第一个不小于键参数的成员；upper_bound将返回第1个大于键参数的成员
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);   
	cout << endl;
	return 0;
}