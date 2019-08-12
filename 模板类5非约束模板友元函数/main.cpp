/*��Լ��ģ����Ԫ����*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template<class T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T & i):item(i){}

	/*����show2()������ManyFriend���廯����Ԫ���ܹ��������о��廯��item��Ա*/
	template<class C, typename D> friend void show2(C & c, D & d);
};

template<class C, typename D>
void show2(C & c, D & d)
{
	cout << c.item << ", " << d.item << endl;
}

int main()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);
	cout << "hfi1,hfi2:";
	show2(hfi1, hfi2);
	cout << "hfdb,hfi2:";
	show2(hfdb, hfi2);
	return 0;
}

