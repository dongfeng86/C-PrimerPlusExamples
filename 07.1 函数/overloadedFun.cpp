#include<iostream>

using namespace std;
void output(int x); // ��������
void output(float x); // ��������
void output(int x)
{
	cout << " output int " << x << endl;
}
void output(float x)
{
	cout << " output float " << x << endl;
}
void main(void)
{
	int x = 1;
	float y = 1.0;
	output(x); // output int 1
	output(y); // output float 1
	output(1); // output int 1
	//output(0.5); // error! ambiguous call, ��Ϊ�Զ�����ת��
	output(int(0.5)); // output int 0
	output(float(0.5)); // output float 0.5
}