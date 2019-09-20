#include<vector>
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

void OutInt(int n) { std::cout << n << " "; }

int main()
{
	using namespace std;

	int ar[3] = { 1,3,4 };
	cout << "���ڣ�����������vector��������ķ�����\n";
	vector<int> arNew;
	arNew.insert(arNew.end(), ar, ar + 3);
	for (auto x : arNew)
		OutInt(x);
	cout << endl;

	list<int> lstOne(5, 2);                               //��1��������5��2��ɵ�����
	int arStuff[5] = { 1,2,4,8,6 };
	list<int> lstTwo;
	lstTwo.insert(lstTwo.begin(), arStuff, arStuff + 5);  //��2������ͨ��insert��������һ������

	int arMore[6] = { 6,4,2,4,6,5 };
	list<int> lstThree(lstTwo);
	lstThree.insert(lstThree.end(), arMore, arMore + 6);  //��3������ͨ��insert��������һ������

	cout << "List one:\n";
	for_each(lstOne.begin(), lstOne.end(), OutInt);
	cout << endl;
	cout << "list two:\n";
	for_each(lstTwo.begin(), lstTwo.end(), OutInt);
	cout << endl;
	cout << "list three:\n";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	cout << endl;
	lstThree.remove(2);                                  //��������ɾ������ֵΪ2��Ԫ��
	cout << endl << "list three after minus 2:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	lstThree.splice(lstThree.begin(), lstOne);           //��Դ������ɾ��Ԫ�ز���ӵ�Ŀ��������
	cout << endl << "List three after splice:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	cout << endl << "list one after list three splice:";
	for_each(lstOne.begin(), lstOne.end(), OutInt);
	lstThree.unique();                                   //�������н����ڵ���ͬԪ�غϲ�Ϊһ��
	cout << endl << "list three after unique:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	lstThree.sort();                                     //�������е�Ԫ�ؽ�������
	lstThree.unique();
	cout << endl << "List three after sort & unique:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	lstTwo.sort();
	/*Removes the elements from the argument list, inserts them into the target list, and orders the new, 
	combined set of elements in ascending order or in some other specified order*/
	lstThree.merge(lstTwo);                             //�������кϲ�һ���µ��������Ժϲ���Ķ������������
	cout << endl << "sorted two merged into three:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	cout << endl;

	//�Լ�����������һ��merge
	list<int> lstNew1;
	lstNew1.insert(lstNew1.end(), ar, ar + 3);
	list<int> lstNew2;
	lstNew2.insert(lstNew2.end(), arMore, arMore + 4);
	lstNew1.sort();                                    
	lstNew2.sort();
	lstNew1.merge(lstNew2);                             //merge������ʹ��ǰ�����뱣֤��������������ģ�����������
	cout << "\n��һ��δ�ϲ�ǰmerge��Ч����\n";
	for (auto x : lstNew1)
		OutInt(x);
	lstNew1.unique();
	cout << "\n��һ��δ�ϲ���merge��Ч����\n";
	for (auto x : lstNew1)
		OutInt(x);
	cout << endl;

	return 0;
}
