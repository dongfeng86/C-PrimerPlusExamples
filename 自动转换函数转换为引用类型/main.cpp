/*���ļ���Ҫ�о����Զ�ת������ת��Ϊ��������ʱ�����*/

#include<iostream>

//������
class cTest
{
public:
	int m_iCount;
	int m_iOther;
public:
	cTest();
	cTest(int iCount,int iOther);

	//����һ���ǳ����ʵ�Ӧ�ã�ת������ֱ�ӷ���һ����Ա���������ã����������޸������Ա������
	//���ң��������ý�ʡ�˷�����ʱ�������Ӹ��������ֵ���洢��һ����ʱλ�ã�Ȼ����ȥʹ�ã��Ŀ���
	operator int& ();		
};

cTest::cTest(int iCount, int iOther)
{
	m_iCount = iCount;
	m_iOther = 0;
}

cTest::cTest()
{
}

cTest::operator int& ()
{
	return m_iCount;
}


int main()
{
	using namespace std;
	cTest cTemp(5,5);
	cout << "���е�����Ϊm_iCout=" << cTemp.m_iCount << ";m_iOther:" << cTemp.m_iOther << endl;

	int m = cTemp;			//������operator int&()�ӿڣ�
	cout << "����mΪ��" << m << endl;

	(int)cTemp = 10;		//������operator int&()�ӿڣ�����˳���޸��˳�Ա������ֵ
	cout << "����m_iCountΪ:" << cTemp.m_iCount << endl;
}
