#include "Worker.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void Worker::Data() const
{
	cout << "name: " << m_fullname << endl;
	cout << "employee ID: " << m_lId << endl;
}

void Worker::Get()
{
	getline(cin, m_fullname);
	cout << "enter worker's ID:";
	cin >> m_lId;
	while (cin.get()!='\n')
		continue;
}

Worker::~Worker()
{
	std::cout << "enter the Worker destruction";
}

void Waiter::Data() const
{
	cout << "panache rating: " << m_iPanache << endl;
}

void Waiter::Get()
{
	cout << "enter waiter's panache rating:";
	cin >> m_iPanache;
	while (cin.get() != '\n')
		continue;
}

Waiter::~Waiter()
{
	std::cout << "\nenter the Waitor destruction";
}

void Waiter::Set()
{
	cout << "enter waiter's name: ";
	Worker::Get();
	Get();                         //调用自己的get
}

void Waiter::Show() const
{
	cout << "category:waiter\n";
	Worker::Data();
	Data();
}

void Singer::Data() const
{
	cout << "vocal range: " << m_pv[m_iVoice] << endl;
}

void Singer::Get()
{
	cout << "enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << m_pv[i] << "   ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	cin >> m_iVoice;
	while (cin.get()!='\n')
		continue;
}

char * Singer::m_pv[Singer::Vtypes] = { "other","alot","contalto","soprano","bass","baritone","tenor"};

Singer::~Singer()
{
	std::cout << "\nenter the Singer destruction";
}

void Singer::Set()
{
	cout << "enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "category:singer\n";
	Worker::Data();
	Data();
}

void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

SingingWaiter::~SingingWaiter()
{
	std::cout << "\nenter the SingingWaiter destrucion! ";
}

void SingingWaiter::Set()
{
	cout << "enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "category : singing waiter\n";
	Worker::Data();
	Data();
}
