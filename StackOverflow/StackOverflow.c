#include <stdio.h>

float GetFloat(int m);

int main() 
{
	char* psz = "abcd";
	int arg = 5;
	float f = GetFloat(arg); 
	printf("\nf=%f", f);

	char* psz2 = psz;
	while (*psz2)
	{
		*psz2 += 2;
	}

	return 0;
}

float GetFloat(int m)
{
	double d = 2.0*m;
	return d;
}