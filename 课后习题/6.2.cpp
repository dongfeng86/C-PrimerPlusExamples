#include<iostream>
#include<vector>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "������һ�����飬��������ĸ�������롣\n";
	std::vector<double> arIn;
	double dTemp;
	while (cin >> dTemp)
	{
		arIn.push_back(dTemp);
	}

	if (!arIn.empty())
	{
		cout << "�����������Ϊ��";
		double dSum=0;
		std::vector<double>::iterator it;
		for (it = arIn.begin(); it != arIn.end(); it++)
		{
			cout << *it << " ";
			dSum += *it;
		}
		double dAver = dSum / arIn.size();
		cout << "\n�ܺ�Ϊ��" << dSum << ";ƽ��ֵΪ:" <<dAver << endl;
		int iLarger=0;
		for (it = arIn.begin(); it != arIn.end(); it++)
		{
			if (*it > dAver)
				iLarger++;
		}
		cout << "һ���� " << iLarger<< " �����ִ���ƽ��ֵ��\n";
	}
	return 0;
}