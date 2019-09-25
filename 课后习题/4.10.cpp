/*
这个题目使用array类存储数据。array类是STL中的模板类，它在初始化的时候就需要指定类型和数量。
*/
#include<iostream>
#include<array>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	std::array<double, 3> arScore;
	cout << "请输入你的成绩：" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> arScore[i];
	}
	double dSum=0;
	for (int i = 0; i < 3; i++)
	{
		dSum += arScore[i];
	}
	
	cout << "你一共输入了：" << arScore.size() << endl;
	cout << "平均成绩为：" << dSum / arScore.size() << endl;

	return 0;
}