#include<iostream>
#include<vector>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "请输入一个数组，按任意字母结束输入。\n";
	std::vector<double> arIn;
	double dTemp;
	while (cin >> dTemp)
	{
		arIn.push_back(dTemp);
	}

	if (!arIn.empty())
	{
		cout << "你输入的数组为：";
		double dSum=0;
		std::vector<double>::iterator it;
		for (it = arIn.begin(); it != arIn.end(); it++)
		{
			cout << *it << " ";
			dSum += *it;
		}
		double dAver = dSum / arIn.size();
		cout << "\n总和为：" << dSum << ";平均值为:" <<dAver << endl;
		int iLarger=0;
		for (it = arIn.begin(); it != arIn.end(); it++)
		{
			if (*it > dAver)
				iLarger++;
		}
		cout << "一共有 " << iLarger<< " 个数字大于平均值。\n";
	}
	return 0;
}