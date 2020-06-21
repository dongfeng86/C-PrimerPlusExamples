/*ģ�����Լ��ģ����Ԫ��������ʹ��ģ�����е���Ԫ�������е�ģ������ԣ����ʺ�ģ�����Ҫ��
ģ�����Լ��ģ����Ԫ�������䶨�岽���Ϊ3����
	1�����ඨ���ǰ������ÿ��ģ�庯����
	2���ں����н�ģ�庯������Ϊ��Ԫ������
	3��Ϊ��Ԫ�����ṩģ�嶨��
*/
#include <iostream>
using std::cout;
using std::endl;

//���ඨ���ǰ���������ÿ��ģ�庯��
template <class T> void counts();
template <class T> void report(T &);

//ģ����
template<class TT>
class HasFriend
{
private:
	TT item;
	static int ct;
public:
	HasFriend(const TT & i) :item(i) { ct++; }
	~HasFriend() { ct--; }

	//�������䲢����˵Ҫ����ģ�庯���ľ��廯������˵�þ��廯��ģ�庯������Ԫ�������������������廯�Ķ���ʵ��main��������ģ�庯��ʱ
	friend void counts<TT>();                       
	friend void report<HasFriend<TT>>(HasFriend<TT> &);
};

template<class TT>
int HasFriend<TT>::ct = 0;                          //ע�⣬����û�����������Ҳ���Է��ʾ�̬��Ա������

template<class T>
void counts()
{
	cout << "template size:" << sizeof(HasFriend<T>) << ";";
	cout << "template counts():" << HasFriend<T>::ct << endl;
}

template<class T>
void report(T & hf)
{
	cout << hf.item << endl;
}

int main()
{
	counts<int>();
	HasFriend<int> hfil(10);               //��ģ�壬������ʽ���ṩ����Ĳ������ͣ���ͳ���ĺ���ģ�岢����ͬ������ģ���ܹ�ͨ���������͵�����ȷ�ĺ���
	HasFriend<int> hfi2(20);
	HasFriend<double> hfdb(10.5);

	report<HasFriend<int>>(hfil);          //�ô���ȼ��� report(hfil);���ú���������ʾָ�����Ͳ���
	report(hfi2);
	report<HasFriend<double>>(hfdb);       //�ô���ȼ��� report(hfdb);���ú���������ʾָ����������
	cout << "counts<int>() output:\n";
	counts<int>();
	cout << "counts<double>() output:\n";
	counts<double>();

	return 0;
}
