#include<sal.h>
#include<vcruntime.h>



void GoodOutOptCallee(_Out_opt_ int *pInt)
{
	if (pInt != NULL) {
		*pInt = 5;
	}
}

void BadOutOptCallee(_Out_opt_ int *pInt)
{
	*pInt = 5; // Dereferencing NULL pointer ¡®pInt¡¯
}

void OutOptCaller()
{
	int *pInt = NULL;
	GoodOutOptCallee(pInt);
	BadOutOptCallee(pInt);
}





int main()
{

}

