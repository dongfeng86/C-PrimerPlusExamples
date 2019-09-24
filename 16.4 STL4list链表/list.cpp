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
	cout << "现在，我们来看看vector插入数组的方法：\n";
	vector<int> arNew;
	arNew.insert(arNew.end(), ar, ar + 3);
	for (auto x : arNew)
		OutInt(x);
	cout << endl;

	list<int> lstOne(5, 2);                               //第1个链表，由5个2组成的链表
	int arStuff[5] = { 1,2,4,8,6 };
	list<int> lstTwo;
	lstTwo.insert(lstTwo.begin(), arStuff, arStuff + 5);  //第2个链表，通过insert方法插入一个数组

	int arMore[6] = { 6,4,2,4,6,5 };
	list<int> lstThree(lstTwo);
	lstThree.insert(lstThree.end(), arMore, arMore + 6);  //第3个链表，通过insert方法插入一个数组

	cout << "List one:\n";
	for_each(lstOne.begin(), lstOne.end(), OutInt);
	cout << endl;
	cout << "list two:\n";
	for_each(lstTwo.begin(), lstTwo.end(), OutInt);
	cout << endl;
	cout << "list three:\n";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	cout << endl;
	lstThree.remove(2);                                  //在链表中删除所有值为2的元素
	cout << endl << "list three after minus 2:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	lstThree.splice(lstThree.begin(), lstOne);           //从源序列中删除元素并添加到目标序列中
	cout << endl << "List three after splice:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	cout << endl << "list one after list three splice:";
	for_each(lstOne.begin(), lstOne.end(), OutInt);
	lstThree.unique();                                   //从链表中将相邻的相同元素合并为一个
	cout << endl << "list three after unique:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	lstThree.sort();                                     //对链表中的元素进行排序
	lstThree.unique();
	cout << endl << "List three after sort & unique:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	lstTwo.sort();
	/*Removes the elements from the argument list, inserts them into the target list, and orders the new, 
	combined set of elements in ascending order or in some other specified order*/
	lstThree.merge(lstTwo);                             //在链表中合并一个新的链表，并对合并后的而链表进行排序
	cout << endl << "sorted two merged into three:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	cout << endl;

	//自己重新又试了一下merge
	list<int> lstNew1;
	lstNew1.insert(lstNew1.end(), ar, ar + 3);
	list<int> lstNew2;
	lstNew2.insert(lstNew2.end(), arMore, arMore + 4);
	lstNew1.sort();                                    
	lstNew2.sort();
	lstNew1.merge(lstNew2);                             //merge函数在使用前，必须保证两个链表都是有序的，否则程序出错
	cout << "\n看一下未合并前merge的效果：\n";
	for (auto x : lstNew1)
		OutInt(x);
	lstNew1.unique();
	cout << "\n看一下未合并后merge的效果：\n";
	for (auto x : lstNew1)
		OutInt(x);
	cout << endl;

	return 0;
}
