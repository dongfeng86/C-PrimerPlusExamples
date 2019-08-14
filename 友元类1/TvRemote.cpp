#include "TvRemote.h"
#include <iostream>

bool Tv::volup()
{
	if (iVolume < kMaxVal)
	{
		iVolume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (iVolume > kMinVal)
	{
		iVolume--;
		return true;
	}
	return false;
}

void Tv::chanup()
{
	if (iChannel < iMaxchannel)
		iChannel++;
	else
		iChannel = 1;
}

void Tv::chandown()
{
	if (iChannel > 1)
		iChannel--;
	else
		iChannel = iMaxchannel;
}

void Tv::settings() const
{
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "Tv is " << (iState == kOn ? "on" : "off") << endl;
	if (kOn == iState)
	{
		cout << "volume setting = " << iVolume << endl;
		cout << "channel setting = " << iChannel << endl;
		cout << "iMode= "
			<< (iMode == kAntenna ? "antenna" : "cable") << endl;
		cout << "input = "
			<< (iInput == kTv ? "Tv" : "DVD") << endl;
	}
}
