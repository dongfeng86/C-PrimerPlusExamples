#include "dma.h"
#include<iostream>

int main()
{
	using std::cout;
	using std::endl;

	baseDMA shirt("Portabelly",8);
	lacksDMA balloon("red","bli",4);
	hasDMA map("mercator","buffalo",5);

	cout<<"displaying baseDMA object:\n";
	cout<<shirt<<endl;
	cout<<"displaying lacksDMA object:\n";
	cout<<balloon<<endl;
	cout<<"displaying hasDMA object:\n";
	cout<<map<<endl;
	lacksDMA ballon2(balloon);
	cout<<"result of lacksDMA copy:\n";
	cout<<ballon2<<endl;
	hasDMA map2;
	map2=map;
	cout<<"result of hasDMA assignment:\n";

	cout<<map2<<endl;
	return 0;
}