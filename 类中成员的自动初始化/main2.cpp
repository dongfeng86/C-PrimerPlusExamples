/*
���û�г�ʼ�����������ִ��Ĭ�ϳ�ʼ����
1.ջ�еı������������еı������Ͷ��еı�������̬�ڴ棩���в�ȷ����ֵ��
2.ȫ�ֱ����;�̬�����������ֲ���̬���������ʼ��Ϊ0
3.�������еĳ�Ա������
	a. ���ȣ���������ã�Ĭ�ϣ����캯�����г�ʼ����
	b. ���������ȫ���������Ϊ��̬�ֲ�����ʱ����������ó�Ա��������ʼ��Ϊ0.
	c. ��������ھֲ���������ʱ����������ó�Ա����������ʼ��Ϊ0��
	d. ���������ͳ�Ա�����������Ĭ�Ϲ��캯�����г�ʼ����
*/


#include <iostream>

class A {
public:
	int value;
};

class B {
public:
	int value;
	A a;
	B(){}
};

B b1;

int main() 
{
	using namespace std;
	B b2;
	static B b3;
	cout << b1.value << "\t" << b1.a.value << endl;
	cout << b2.value << "\t" << b2.a.value << endl;
	cout << b3.value << "\t" << b3.a.value << endl;
	//cout << b2.value << "\t" << b2.a.value << endl;
	return 0;
}