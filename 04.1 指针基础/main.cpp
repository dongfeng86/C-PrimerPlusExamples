//这部分要重新整理
#include <iostream>

void fun(char ch[5])
{
	//请注意，ch不是一个数组，仅仅是一个指针的长度
	int i = sizeof(ch);	
	printf(("\n当前的i=%d\n"), i);
}

int main()
{
	char ar[] = { 1,3,4,5,6 };
	char arNew[10];
	int i1 = sizeof(ar);
	int i2 = sizeof(arNew);
	fun(ar);
	using namespace std;
	//指针到底占几位，在X86的情况下占据32位，在X64的情况下占据64位。
	cout << "现在，我们看下指针到底占几位？" << endl;
	cout << "一个int型占据：" << sizeof(int) << endl;
	cout << "一个int *型占据：" << sizeof(int *) << endl;
	cout << "一个double型占据:" << sizeof(double) << endl;
	cout << "一个double * 型占据：" << sizeof(double *) << endl;

	//多维数组数组名代表多级指针
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

	//指向多维数组的指针
	int(*pz)[2];
	pz = zippo;
	cout << "\n现在，我们试一下指针变量\n";
	cout << "pz=" << pz << ";pz+1=" << pz + 1 << endl;
	cout << "pz[0]= " << pz[0] << ";pz[0]+1=" << pz[0] + 1 << endl;
	cout << "*pz=" << *pz << ";*pz+1=" << *pz + 1 << endl;
	cout << "*pz[0]=" << *pz[0] << ";*(pz[0]+1)=" << *(pz[0] + 1) << endl;
	cout << "pz[0][0]=" << pz[0][0] << ";*pz[0]=" << *pz[0] << ";**pz=" << **pz << endl;
	cout << "pz[2][1]=" << pz[2][1] << ";*(*(pz+2)+1)=" << *(*(pz + 2) + 1) << endl;

	
	return 0;
}