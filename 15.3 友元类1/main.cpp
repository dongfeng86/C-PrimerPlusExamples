#include <iostream>
#include "TvRemote.h"

int main()
{
	using std::cout;
	Tv cS42;
	cout << "initial settings for 42\" TV:\n";
	cS42.settings();
	cS42.onoff();
	cS42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";
	cS42.settings();
	cS42.chanup();
	cout << "\nadjustd settings for 42\" TV:\n";
	cS42.settings();

	Remote grey;
	grey.set_chan(cS42, 10);
	grey.volup(cS42);
	grey.volup(cS42);
	cout << "\n42\" settings after using remote:\n";
	cS42.settings();

	Tv cS58(Tv::kOn);
	cS58.set_mode();
	grey.set_chan(cS58, 28);
	cout << "\n58\" settings:\n";
	cS58.settings();
	return 0;
}