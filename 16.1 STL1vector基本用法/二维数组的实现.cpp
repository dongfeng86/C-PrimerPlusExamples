#include<iostream>
#include<vector>
#define count  3 
using namespace std;

//目标就是完成二维vector的所有操作 
int main()
{
	vector<vector<int>> vec1(count); //二维数组的 vector 定义
									 //初始化一个3x3的矩阵，数值为 333
	for (int i = 0; i < vec1.size(); ++i) {
		for (int j = 0; j < count; ++j) {
			vec1[i].push_back(333);
		}
	}

	//增加一行,数值为444  
	vector<int> temp;
	vec1.push_back(temp);
	int pos = vec1.size() - 1;
	vec1[pos].push_back(444);
	vec1[pos].push_back(444);
	vec1[pos].push_back(444);

	vec1[1].clear();
	if (vec1[1].empty())
	{
		std::cout << "第2想空了，数组一共" << vec1.size() << "项\n";
	}

	//增加一列
	pos = vec1.size();
	for (int i = 0; i < pos; ++i)
		vec1[i].push_back(555);
	//打印“二维数组”
	for (int i = 0; i < vec1.size(); ++i) {
		for (int j = 0; j < vec1[0].size(); ++j) {
			cout << vec1[i][j] << "  ";
		}
		cout << endl;
	}

	return 0;
}