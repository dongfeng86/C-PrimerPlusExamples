/*
复利计算
*/
#include<iostream>
#include<vector>
#include<cmath>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	//在程序中，所有的常量都应该用符号常量去替代，这样可以做到一次替换全部都改。这确实是正确的。常量前加上k。
	const double kSimpleInterest = 1.1;
	const double kCompoundInterest = 1.01;
	const double kBase = 100;
	
	std::vector<double> arDa;
	std::vector<double> arCl;

	int i = 1;
	double dTemp1, dTemp2;
	do 
	{
		dTemp1 = kBase*pow(kCompoundInterest, i);
		dTemp2 = kBase*kSimpleInterest;
		arDa.push_back(dTemp2);
		arCl.push_back(dTemp1);
		i++;
	} while (dTemp1<dTemp2);
	i--;

	cout << "now ,we find in about " << i << " years ,the second interest is mucher than first.\n";
	cout << "the first interest is :" << kBase*kSimpleInterest << endl;
	cout << "the second interest is :" << kBase*pow(kCompoundInterest, i) << endl;
	cout << "let us see the detail.\n";
	cout << "年份\t前者收益\t后者收益\n";
	for (int i = 0; i < arDa.size(); i++)
	{
		cout << i + 1 << '\t' << arDa[i] << "\t\t" << arCl[i] << endl;
	}

	return 0;	
}