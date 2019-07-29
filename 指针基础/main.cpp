//这部分要重新整理
#include <iostream>

int main()
{
	using namespace std;
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