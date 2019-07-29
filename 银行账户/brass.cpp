//brass.cpp
#include<iostream>
#include"brass.h"
using std::cout;
using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(const std::string & s, long an, double bal)
{
	fullName = s;
	accNum = an;
	balance=bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "negative deposit not allowed; "
		<< "deposit is cancelled.\n";
	else
		balance += amt;
}

void Brass::WithDraw(double amt)
{
	//set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	if (amt < 0)
		cout << "withdraw aomout must be positive;"
		<< "withdrawal canceled.\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "withdrawal amount of $" << amt
		<< " exceeds your balance.\n"
		<< "withdrawal canceled.\n";
	restore(initialState, prec);
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	format initialstate = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullName << endl;
	cout << "accout number: " << accNum << endl;
	cout << "balance:$" << balance << endl;
	restore(initialstate, prec);
}


//BrassPlus Methods
//派生类的构造函数，派生类构造函数必须使用基类构造函数，如果不调用基类构造函数，程序将使用默认的基类构造函数
//C++使用成员初始化列表语法完成这个工作
BrassPlus::BrassPlus(const std::string & s, long an, double bal, double m1, double r)
	:Brass(s,an,bal)
{
	maxLoan = m1;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double m1, double r)
	:Brass(ba)              //brass虽然没有显示定义复制构造函数，但是，程序会默认构造一个复制构造函数，执行浅复制
{
	maxLoan = m1;
	owesBank = 0.0;
	rate = r;
}
//重新定义了这个虚函数
void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();
	cout << "maximum loan:$" << maxLoan << endl;
	cout << "owed to bank:$" << owesBank << endl;
	cout.precision(3);
	cout << "loan rate: " << 100 * rate << "%\n";
	restore(initialState, prec);
}

//重新定义派生类中的虚函数
void BrassPlus::WithDraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();                //派生类继承了基类的Balance函数
	if (amt <= bal)
		Brass::WithDraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "bank advance:$" << advance << endl;
		cout << "Finace charge:$" << advance*rate << endl;
		//下面两个函数是一个非常精妙的设计，先把预付款加到账户余额中，然后调用基类的取款函数，使余额变为0
		Deposit(advance);                  
		Brass::WithDraw(amt);
	}
	else
		cout << "credit limit exceeded.transaction cancelled.\n";
	restore(initialState, prec);
}

format setFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}