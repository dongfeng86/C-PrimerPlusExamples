
#include<stdio.h>
#include<iostream>
using namespace std;

#define A(x) T_##x
#define B(x) #@x
#define C(x) #x

#define f(a,b) a##b
#define g(a) #a
#define h(a) g(a)
#define ff(x,y) x+y

#define foo abc
#define foo2(x) x##123
#define foo123 "hehe"

#define Str1 "hello"
#define Cat2Str(x,y) x#y

void main()
{
	printf("%c\n", B(1));       // B(1)------��'1'
	printf("%s\n", C(1));       // C(1)------��"1"

	printf("%s\n", h(A(1)));    
	//�����T_1��
	//��չ������Ϊ����h(a)�ĺ����ǰ��û��#����##�������չ�������A(1)��
	//h(A(1))��h(T_1)��g(T_1)��"T_1"

	printf("%s\n", h(f(1, 2))); 
	//���:12.
	//��չ������Ϊ�����h(a)�ĺ�����ǰ��û��#����##�������չ���������
	//h(f(1, 2))��h(12)��g(12)��"12"

	printf("%s\n", g(f(1, 2))); 
	//���:f(1,2)
	//��չ������Ϊ�����g(a)�Ĳ���ǰ��#����##����˴�������ڲ�չ����
	//g(f(1, 2))��#f(1,2)��"f(1,2)"

	printf("%d\n", f(f, f(3, 4)));	
	//�����7��
	//��չ��˳��Ϊ��������ǰ����##����ˣ�ֱ�Ӵ����չ���� f(f, f(3, 4))��ff(3,4)��3+4

	printf("%s\n", g(1)g(2));		//�����12
	printf("%s\n", f(g(1), g(2)));	//�����12
	//���������Ӻ����⣬��ԭ��Ϊ����������ʶ��g(1)g(2),��ʵ�ϣ�������ʶ������һ��ĺ꣬Ȼ��ֱ�չ����
	//��չ������Ϊ����Ϊf(a,b)�ĺ����ǰ����#����##��ֱ�Ӵ����չ����
	//f(g(1), g(2))��g(1)##g(2)��g(1)g(2)����12��

	printf("%s\n", Cat2Str(Str1, ",nihao"));	//�����hello",nihao"
	printf("%s\n", Cat2Str(Str1, Str1));		//�����helloStr1
	//�������Ҳ�ȽϾ��䣬����չ����ǰ��#ʱ����������������ַ���
	//Cat2Str(Str1, Str1)��չ������Ϊ��
	//��ΪCat2Str(x,y)��y����ǰ��#��ֱ�ӽ�����Ĳ���תΪ�ַ���(Ҳ���Ǹú�����ȴ����չ��)
	//Cat2Str(Str1, Str1)��"hello""Str1"��"helloStr1"

	printf("%s\n", foo2(foo));
	//���,�ϸ��������Ӱɡ� foo2(foo)��չ���ɲ���abc123Ŷ��
	//��չ������Ϊ����Ϊfoo2(x)�ĺ����ǰ����#����##����ˣ�ֱ�Ӵ����չ����
	//foo2(foo)��foo##123��foo123��"hehe"
}