/*
这个题目要求用new分配内存，所以做成了这个样子。
实际上，这个题目使用vector动态数组是最为合适的。
*/
#include<iostream>
#include<string>

struct SPizza
{
	std::string sName;
	double dDiameter;
	double dWeight;
};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "请输入Pizza的数量：";
	SPizza* pPizza = new SPizza[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "请输入pizza饼的名称：\n";
		if (getline(cin, pPizza[i].sName) && pPizza[i].sName != "")
		{
			cout << "请输入Pizza并的直径：" << endl;
			cin >> pPizza[i].dDiameter;
			while (cin.get() != '\n')
				continue;
			cout << "请输入Pizza饼的重量：\n";
			cin >> pPizza[i].dWeight;
			while (cin.get() != '\n')
				continue;
		}
		else
			break;
	}

	cout << "现在，让我们看看你输入的信息吧：\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Pizza饼的名称：" << pPizza[i].sName << ";Pizza饼的重量："
			<< pPizza[i].dWeight << "Pizza饼的直径：" << pPizza[i].dDiameter << endl;
	}

	delete[] pPizza;                //这个不能忘记
	return 0;
}