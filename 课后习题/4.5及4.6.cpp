/*
Ϊ�α�4.5��4.6��Ŀ��
ע�⣬�б��ʼ���ķ���
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

	//ע�⣬�ṹ����Զ����Աһ��һ����ֵ��Ҳ����������һ����ֵ
	//C++11 �У����ԡ��б��ʼ������ʽ�����ٵĳ�ʼ���������ͻ�STL������;���޵Ⱥž�����

	SSuger cSnack{ "not",5.9,500 };

	//������һ��ԭʼ�ķ�ʽ
	//cSnack.cTwo = "MOcha Munch";
	//cSnack.dWeight = 2.3;
	//cSnack.iCalorie = 350;

	//�б��ʼ����������STL�е�����
	//std::vector<int> arVec={1,2,3,4};
	//std::vector<int>::iterator it;
	//for (it = arVec.begin(); it != arVec.end(); it++)
	//	cout << *it << " ";
	//cout << endl;
	
	cout << "cSnack������Ϊ:" << cSnack.sName
		<< ";����Ϊ��" << cSnack.dWeight 
		<< ";����Ϊ��" << cSnack.iCalorie 
		<< endl;
	
	////������������һ���ṹ����
	//SSuger arSuger[] 
	//{ 
	//	{"nihao",2.5,350},
	//	{"nimeng",5.8,200} 
	//};
	//for (int i = 0; i < 2; i++)
	//{
	//	cout << "����Ϊ:" << arSuger[i].sName
	//		<< ";����Ϊ��" << arSuger[i].dWeight
	//		<< ";����Ϊ��" << arSuger[i].iCalorie
	//		<< endl;
	//}

	//��������������
	cout << "���������������취����һ���ṹ������:\n";
	std::vector<SSuger> arOther;
	SSuger cTemp;
	cout << "�������ǹ������ưɣ�";
	while (getline(cin, cTemp.sName) && cTemp.sName!="")
	{
		cout << "���ڣ�������������\n";
		if (!(cin >> cTemp.dWeight))
			break;
		while (cin.get() != '\n')
			continue;
		cout << "�������ǹ��������ɣ�";
		if(!(cin>>cTemp.iCalorie))
			break;
		while (cin.get() != '\n')
			continue;
		arOther.push_back(cTemp);
		cout << "���ٴ������ǹ������ưɣ�\n";
	}

	if (!arOther.empty())
	{
		std::vector<SSuger>::iterator it;
		for (it = arOther.begin(); it != arOther.end(); it++)
		{
			cout << "����Ϊ:" << it->sName
				<< ";����Ϊ��" <<it->dWeight
				<< ";����Ϊ��" << it->iCalorie
				<< endl;
		}
	}
	return 0;
}