#include <iostream>

//�Զ������ת��
class A {
public:
	virtual void GetInt(){}	//�������麯������׼ȷ��˵���麯����������ʹ��dynamic_cast
};
class B : public A {};
class C {};

int main() 
{
	double dValue = 12.12;
	float fValue = 3.14; // warning C4305: ����ʼ����: �ӡ�double������float���ض�
	int nDValue = static_cast<int>(dValue); // 12
	int nFValue = static_cast<int>(fValue); // 3

	A *pA = new A;
	B *pB = static_cast<B*>(pA); // ���벻�ᱨ��, B��̳���A��
	pB = new B;
	pA = static_cast<A*>(pB); // ���벻�ᱨ��, B��̳���A��
	//C *pC = static_cast<C*>(pA); // ���뱨��, C����A��û���κι�ϵ��error C2440: ��static_cast��: �޷��ӡ�A *��ת��Ϊ��C *��


	A a;
	const A* pConstA = &a;
	A* pNoConstA = const_cast<A*>(pConstA);	//�Ϸ�
	//B* pNoConstB = const_cast<A*>(pConstA);	//�Ƿ�

	B* pB2 = new B;
	A* pA2 = dynamic_cast<A*>(pB2);	//up-cast ,�Ϸ�
	B* pB3 = dynamic_cast<B*>(pA2);	//�Ϸ���dynamic_cast���а�ȫ����Ժ���ΪpA2ʵ��ָ��B����

	A* pA3 = new A;
	//pB3 = dynamic_cast<A*>(pA3);	//�������error C2440��dynamic_cast���а�ȫ����Ժ���Ϊ��ת������ȫ����ֹת��

	delete pA3;
	delete pB2;
}