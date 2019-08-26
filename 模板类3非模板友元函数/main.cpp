#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template<class T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T & i) :item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void counts();
	friend void reports(HasFriend<T> &);
};

//ÿһ�����廯���������Լ��ľ�̬���ݣ�ע�����ﾹȻ��ʼ������һ��private�;�̬����
template<class T>
int HasFriend<T>::ct = 0;

//��ģ����Ԫ����
void counts()
{
	cout << "int count:" << HasFriend<int>::ct << ";";
	cout << "double count: " << HasFriend<double>::ct << endl;
}

void reports(HasFriend<int> & hf)
{
	cout << "hasFriend<int>:" << hf.item << endl;
}

void reports(HasFriend<double> & hf)
{
	cout << "hasFriend<double>:" << hf.item << endl;
}

int main()
{
	cout << "no objects declared:";
	counts();                         //��ľ�̬��Ա��������ģ�����û����������󣬾�̬��Ա��Ȼ���Է��ʣ��ڷ���ǰ��ʼ����ľ�̬��Ա����

	HasFriend<int> hfil(10);
	cout << "after hfil declared:";
	counts();
	HasFriend<int> hfi2(20);
	cout << "after hfi2 declared:";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "after hfdb declared:";
	counts();

	reports(hfil);
	reports(hfi2);
	reports(hfdb);

	return 0;
}