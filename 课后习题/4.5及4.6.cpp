/*
为课本4.5及4.6题目。
注意，列表初始化的方法
*/
#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <map>


struct SSuger
{
	std::string sName;
	double dWeight;
	int iCalorie;
};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	//注意，结构体可以对其成员一个一个赋值，也可以像数组一样赋值
	//C++11 中，可以”列表初始化“方式来快速的初始化内置类型或STL中容器;有无等号均可以

	SSuger cSnack{ "not",5.9,500 };

	//以下是一种原始的方式
	//cSnack.cTwo = "MOcha Munch";
	//cSnack.dWeight = 2.3;
	//cSnack.iCalorie = 350;

	//列表初始化可以用于STL中的容器
	//std::vector<int> arVec={1,2,3,4};
	//std::vector<int>::iterator it;
	//for (it = arVec.begin(); it != arVec.end(); it++)
	//	cout << *it << " ";
	//cout << endl;
	
	cout << "cSnack的名称为:" << cSnack.sName
		<< ";重量为：" << cSnack.dWeight 
		<< ";热量为：" << cSnack.iCalorie 
		<< endl;
	
	////接下来，创建一个结构数组
	//SSuger arSuger[] 
	//{ 
	//	{"nihao",2.5,350},
	//	{"nimeng",5.8,200} 
	//};
	//for (int i = 0; i < 2; i++)
	//{
	//	cout << "名称为:" << arSuger[i].sName
	//		<< ";重量为：" << arSuger[i].dWeight
	//		<< ";热量为：" << arSuger[i].iCalorie
	//		<< endl;
	//}

	//来看看其他方法
	cout << "我们来试试其他办法创建一个结构体数组:\n";
	std::vector<SSuger> arOther;
	SSuger cTemp;
	cout << "请输入糖果的名称吧：";
	while (getline(cin, cTemp.sName) && cTemp.sName!="")
	{
		cout << "现在，再输入重量：\n";
		if (!(cin >> cTemp.dWeight))
			break;
		while (cin.get() != '\n')
			continue;
		cout << "请输入糖果的能量吧：";
		if(!(cin>>cTemp.iCalorie))
			break;
		while (cin.get() != '\n')
			continue;
		arOther.push_back(cTemp);
		cout << "请再次输入糖果的名称吧：\n";
	}

	if (!arOther.empty())
	{
		std::vector<SSuger>::iterator it;
		for (it = arOther.begin(); it != arOther.end(); it++)
		{
			cout << "名称为:" << it->sName
				<< ";重量为：" <<it->dWeight
				<< ";热量为：" << it->iCalorie
				<< endl;
		}
	}
	return 0;
}