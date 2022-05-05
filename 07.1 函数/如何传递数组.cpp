#include<iostream>
#include <assert.h>
using namespace std;

const int MAX = 5;

//int Fill_Array(double arr[], int limit);
//void Show_Array(const double arr[], int n);
//void Revalue(double r, double arr[], int n);

double betsy(int);
double pam(int);
void estimate(int lines, double(*pf)(int));

//声明模板函数,注意，模板声明要和实现放在同一文件夹下
template<typename T>
void Swap(T &a, T &b);

int main()
{
	//assert(0);
#ifdef __cplusplus
	std::cout << "该文件定义了__cplusplus!\n";

#endif // __cplusplus

	//调用模板函数
	int i = 10;
	int j = 11;
	Swap(i, j);
	cout << "i=" << i << ";j=" << j << endl;
	return 0;


	//调用函数指针
	cout << "betsy估计的时间为：";
	estimate(5, betsy);
	cout << "pam估计的时间为：";
	estimate(5, pam);
	return 0;

//	double properties[MAX];
//
//	int size = Fill_Array(properties, MAX);
//	Show_Array(properties, size);
//	if (size > 0)
//	{
//		cout << "enter revaluation factor:";
//		double factor;
//		while (!(cin>>factor))
//		{
//			cin.clear();
//			while (cin.get()!='\n')
//			{		
//				continue;
//			}
//			cout << "bad input,please enter a new num.";
//		}
//		Revalue(factor, properties, size);
//		Show_Array(properties, size);
//	}
//	cout << "Done.\n";
//	cin.get();
//	return 0;
//}
//
//int Fill_Array(double arr[], int limit)
//{
//	double temp;
//	int i;
//	for (i = 0; i < limit; i++)
//	{
//		cout << "please input some num." << endl;
//		cin >> temp;
//		if (!cin)
//		{
//			cin.clear();
//			while (cin.get() != '\n')
//			{
//				continue;
//			}
//			cout << "bad input,enter another.";
//			break;
//		}
//		else if (temp < 0)
//			break;
//		arr[i] = temp;
//	}
//	return i;
}
//
//void Show_Array(const double arr[], int n)
//{
//	cout << "数列为：";
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//}
//
//void Revalue(double r, double arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] *= r;
//	}
//}

template<typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
