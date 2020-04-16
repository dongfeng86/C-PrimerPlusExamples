//���ļ���Ҫ���۷�Լ����ģ����Ԫ����
#include<iostream>
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
	template<class C,class D> friend void show(C & c, D & d);
};

template<class C, class D>
void show(C & c, D & d)
{
	cout << c.item << ", " << d.item << endl;        //������Ϊ�����һ��ʹ�÷�������Ԫ��������˺����Ա������ͬ�ķ���Ȩ�ޣ�
                                                     //��Ϊ��Ԫ����û�г�Ա����Ĭ�ϵ�thisָ�룬����ʹ����ֱ�ӳ�Ա�����
}

int main()
{
	ManyFriend<int> hfil(10);
	ManyFriend<int> hfil2(20);
	ManyFriend<double> hfdb(10.5);
	cout << "hfi1,hfi2:";
	show(hfil, hfil2);
	cout << "hfdb,hfi2:";
	show(hfdb, hfil2);
	return 0;
}
