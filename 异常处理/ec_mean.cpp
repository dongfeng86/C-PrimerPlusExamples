#include "ec_mean.h"

#include <iostream>
#include<cmath>

double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	

	double x, y, z;
	cout << "enter your numbers:";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << "harmonic mean of  " << x << " and " << y << " is " << z << endl;
			cout << "geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
			cout << "enter next set of numbers<q to quit>:";
		}
		catch (bad_hmean & bg)
		{
			bg.mesg();
			cout << "try again.\n";
			continue;
		}
		catch (bad_gmean & bg)
		{
			cout << bg.mesg();
			cout << "value used:" << bg.v1 << ", "
				<< bg.v2 << endl;
			cout << "sorry,you don't get to play any more.\n";
			break;
		}
	}
	cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a,b);
	return 2.0*a*b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a*b);
}

