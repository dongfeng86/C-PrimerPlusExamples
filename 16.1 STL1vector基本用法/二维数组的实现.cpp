#include<iostream>
#include<vector>
#define count  3 
using namespace std;

//Ŀ�������ɶ�άvector�����в��� 
int main1()
{
	vector<vector<int>> vec1(count); //��ά����� vector ����
									 //��ʼ��һ��3x3�ľ�����ֵΪ 333
	for (int i = 0; i < vec1.size(); ++i) {
		for (int j = 0; j < count; ++j) {
			vec1[i].push_back(333);
		}
	}
	//����һ��,��ֵΪ444  
	vector<int> temp;
	vec1.push_back(temp);
	int pos = vec1.size() - 1;
	vec1[pos].push_back(444);
	vec1[pos].push_back(444);
	vec1[pos].push_back(444);

	//����һ��
	pos = vec1.size();
	for (int i = 0; i < pos; ++i)
		vec1[i].push_back(555);
	//��ӡ����ά���顱
	for (int i = 0; i < vec1.size(); ++i) {
		for (int j = 0; j < vec1[0].size(); ++j) {
			cout << vec1[i][j] << "  ";
		}
		cout << endl;
	}

	return 0;
}