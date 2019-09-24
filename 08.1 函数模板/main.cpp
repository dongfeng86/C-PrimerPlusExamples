/*���ļ���ģ�庯����ʹ�÷������ܣ��ر�����ǿ������ʾ���廯/*/
#include <iostream>

//����ģ�庯��
template<class T>
void Swap(T &a, T &b);

struct Job
{
	char name[40];
	double salary;
	int floor;
};
void Show(Job & j);

//explicit specialization����ʽ���廯���ػ�����ע������template <>��ͷ�ģ�����Swap�����<Job>�ǿ�ѡ��
template <> void Swap<Job>(Job & j1, Job & j2);

//ģ�庯��ʵ������ע��Swap�����<int>�ǿ�ѡ�ġ�ע��ʵ����������main()�������н��С�
template void Swap<int>(int &, int &);
int main()
{
	//template void Swap<int>(int &, int &);        //ע�⣬�����ڴ˽���ģ�庯��ʵ�������������ں����ڲ�������������                   
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i,j= " << i << "," << j << ".\n";
	cout << "using complier-generated int swapper:\n";

	Swap(i, j);                                    //�õ���ͨ��ģ�壬ͨ��������������һ��ģ�庯��ʵ����Ҳ����ʽʵ����
	cout << "now i,j=" << i << "," << j << ".\n";

	Job sue = { "Susan",730.6,7 };
	Job sidney = { "Sidney",760,9 };
	cout << "before job swapping:\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);                             //�õ��Ǿ��廯��ģ��
	cout << "after job swapping:\n";
	Show(sue);
	Show(sidney);
	return 0;
}

template<class T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void Swap<Job>(Job & j1, Job & j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(Job & j)
{
	using namespace std;
	cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}