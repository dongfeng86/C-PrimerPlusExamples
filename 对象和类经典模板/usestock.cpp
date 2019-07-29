#include <iostream>
#include "stcok.h"

const int STKS = 4;
int main()
{
	Stock stocks[STKS] = {
		Stock("nanjing",12,20.0),
		Stock("boffo",200,2),
		Stock("nomo",130,3.25),
		Stock("fleep enter",60,6.5)
	};

	std::cout << "stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();
	const Stock * top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);
	//now top points to the most valuable holding
	std::cout << "\nmost valuable holding:\n";
	top->show();
	return 0;
}