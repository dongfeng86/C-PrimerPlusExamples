#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

void OutInt(int n) { std::cout << n << " "; }

int main()
{
	using namespace std;
	list<int> lstOne(5, 2);               //由5个2组成的链表
	int arStuff[5] = { 1,2,4,8,6 };
	list<int> lstTwo;
	lstTwo.insert(lstTwo.begin(), arStuff, arStuff + 5);
	int arMore[6] = { 6,4,2,4,6,5 };
	list<int> lstThree(lstTwo);
	lstThree.insert(lstThree.end(), arMore, arMore + 6);

	cout << "List one:\n";
	for_each(lstOne.begin(), lstOne.end(), OutInt);
	cout << endl;
	cout << "list two:\n";
	for_each(lstTwo.begin(), lstTwo.end(), OutInt);
	cout << endl;
	cout << "list three:\n";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	cout << endl;
	lstThree.remove(2);
	cout << endl << "list three after minus 2:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	lstThree.splice(lstThree.begin(), lstOne);           //从源序列中删除元素并添加到目标序列中
	cout << endl << "List three after splice:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	cout << endl << "list one after list three splice:";
	for_each(lstOne.begin(), lstOne.end(), OutInt);
	lstThree.unique();
	cout << endl << "list three after unique:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	lstThree.sort();
	lstThree.unique();
	cout << endl << "List three after sort & unique:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);

	lstTwo.sort();
	/*Removes the elements from the argument list, inserts them into the target list, and orders the new, 
	combined set of elements in ascending order or in some other specified order*/
	lstThree.merge(lstTwo);
	cout << endl << "sorted two merged into three:";
	for_each(lstThree.begin(), lstThree.end(), OutInt);
	cout << endl;

	return 0;
}
