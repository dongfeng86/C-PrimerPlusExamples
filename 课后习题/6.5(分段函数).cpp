/*
�������Ƿֶκ�����д�����ǳ�����
*/
// |-------------|---------------------|-----------------------|--------------------
// 0   0.0    (5000)      10%        (15000)     15%        (35000)      20%        

#include<iostream>
#define MIN 0.0001

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	const double dFirst = 5000;
	const double dSecond = 15000;
	const double dThird = 35000;

	const double dFirstRate = 0.0;
	const double dSecondRate = 0.10;
	const double dThirdRate = 0.15;
	const double dFourthRate = 0.20;

	cout << "������������룺\n";
	double dEarning;
	while (cin >> dEarning && (dEarning > 0 && fabs(dEarning) > 0))
	{
		double ar[4] = { 5000,10000,20000 };

		if (dEarning <= dFirst)
		{
			ar[1] = ar[2] = ar[3] = 0;
		}
		else if (dEarning <= dSecond)
		{
			ar[1] = dEarning - dFirst;
			ar[2] = 0;
		}
		else if (dEarning <= dThird)
		{
			ar[2] = dEarning - dSecond;
		}
		else
			ar[3] = dEarning - dThird;

		//˰��
		double dFax = 0;
		dFax = ar[0] * dFirstRate + ar[1] * dSecondRate + ar[2] * dThirdRate + ar[3] * dFourthRate;
		cout << "�������Ϊ��" << dEarning << ";���˰��Ϊ��" << dFax << endl;
	}
	return 0;
}