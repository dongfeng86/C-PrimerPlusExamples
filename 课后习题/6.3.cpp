/*
²Ëµ¥Çý¶¯³ÌÐò
*/
#include<iostream>
#include<iomanip>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "please enter one of the following choice:\n"
		<<std::left<< std::setw(15) << "c)carnivor" << std::setw(15) << "p)pianist" << endl
		<< std::setw(15) << "t)tree" << std::setw(15) << "g)game" << endl
		<< std::setw(15) << "q)quit" << endl;

	char ch;
	while (cin.get(ch) && ch != 'q')
	{
		while (cin.get() != '\n')
			continue;
		switch (ch)
		{
		case 'c':
			cout << "csience is great\n";
			break;
		case 'p':
			cout << "plenty of people come in\n";
			break;
		case 't':
			cout << "teaching is skill\n";
			break;
		case 'g':
			cout << "great is a result of sweat\n";
			break;
		default:
			cout << "please input c,p,t,g or q\n";
		}
	}
	cout << "\nBye.\n";
	return 0;
}