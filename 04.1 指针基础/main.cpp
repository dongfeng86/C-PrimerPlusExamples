//�ⲿ��Ҫ��������
#include <iostream>

void fun(char ch[5])
{
	//��ע�⣬ch����һ�����飬������һ��ָ��ĳ���
	int i = sizeof(ch);	
	printf(("\n��ǰ��i=%d\n"), i);
}

int main()
{
	char ar[] = { 1,3,4,5,6 };
	char arNew[10];
	int i1 = sizeof(ar);
	int i2 = sizeof(arNew);
	fun(ar);
	using namespace std;
	//ָ�뵽��ռ��λ����X86�������ռ��32λ����X64�������ռ��64λ��
	cout << "���ڣ����ǿ���ָ�뵽��ռ��λ��" << endl;
	cout << "һ��int��ռ�ݣ�" << sizeof(int) << endl;
	cout << "һ��int *��ռ�ݣ�" << sizeof(int *) << endl;
	cout << "һ��double��ռ��:" << sizeof(double) << endl;
	cout << "һ��double * ��ռ�ݣ�" << sizeof(double *) << endl;

	//��ά��������������༶ָ��
	int zippo[4][2]=
	{
		{2,4},
		{6,8},
		{1,3},
		{5,7}
	};
	cout << "zippo= " << zippo << ";zippo+1=" << zippo + 1 << endl;
	cout << "zippo[0]= " << zippo[0] << ";zippo[0]+1=" << zippo[0] + 1 << endl;
	cout << "*zippo=" << *zippo << ";*zippo+1=" << *zippo + 1 << endl;
	cout << "*zippo[0]=" << *zippo[0] << ";*(zippo[0]+1)=" << *(zippo[0] + 1) << endl;
	cout << "zippo[0][0]=" << zippo[0][0] << ";*zippo[0]=" << *zippo[0] << ";**zippo=" << **zippo << endl;
	cout << "zippo[2][1]=" << zippo[2][1] << ";*(*(zippo+2)+1)=" << *(*(zippo + 2) + 1) << endl;

	//ָ���ά�����ָ��
	int(*pz)[2];
	pz = zippo;
	cout << "\n���ڣ�������һ��ָ�����\n";
	cout << "pz=" << pz << ";pz+1=" << pz + 1 << endl;
	cout << "pz[0]= " << pz[0] << ";pz[0]+1=" << pz[0] + 1 << endl;
	cout << "*pz=" << *pz << ";*pz+1=" << *pz + 1 << endl;
	cout << "*pz[0]=" << *pz[0] << ";*(pz[0]+1)=" << *(pz[0] + 1) << endl;
	cout << "pz[0][0]=" << pz[0][0] << ";*pz[0]=" << *pz[0] << ";**pz=" << **pz << endl;
	cout << "pz[2][1]=" << pz[2][1] << ";*(*(pz+2)+1)=" << *(*(pz + 2) + 1) << endl;

	
	return 0;
}