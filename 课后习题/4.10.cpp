/*
�����Ŀʹ��array��洢���ݡ�array����STL�е�ģ���࣬���ڳ�ʼ����ʱ�����Ҫָ�����ͺ�������
*/
#include<iostream>
#include<array>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	std::array<double, 3> arScore;
	cout << "��������ĳɼ���" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> arScore[i];
	}
	double dSum=0;
	for (int i = 0; i < 3; i++)
	{
		dSum += arScore[i];
	}
	
	cout << "��һ�������ˣ�" << arScore.size() << endl;
	cout << "ƽ���ɼ�Ϊ��" << dSum / arScore.size() << endl;

	return 0;
}