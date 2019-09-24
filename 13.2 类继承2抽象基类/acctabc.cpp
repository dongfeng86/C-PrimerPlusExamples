#include "acctabc.h"
#include<iostream>
using std::cout;
using std::cin;
using std::ios_base;
using std::endl;
using std::string;

AcctABC::Formatting AcctABC::SetFormat() const
{
	Formatting f;
	f.flag=cout.setf(ios_base::fixed,ios_base::floatfield);
	f.pr=cout.precision(2);
	return f;
}

void AcctABC::Restore(Formatting & f) const
{
	cout.setf(f.flag,ios_base::floatfield);
	cout.precision(f.pr);
}

AcctABC::AcctABC(const std::string & s/*="nullBody"*/,long an/*=-1*/,double bal/*=0*/)
{
	fullName=s;
	acctNum=an;
	balance=bal;
}

void AcctABC::Deposit(double amt)
{
	if(amt<0)
		cout<<"negative deposit not allowed;"
		<<"deposit is cancelled.\n";
	else
		balance+=amt;
}


void AcctABC::WithDraw(double amt)            //纯虚函数你可以提供定义，没问题
{
	balance-=amt;
}


void Brass::WithDraw(double amt)
{
	if(amt<0)
		cout<<"withdrawal amout must be positive;"
		<<"withdrawal canceled.\n";
	else if(amt<=Balance())
		AcctABC::WithDraw(amt);
	else
		cout<<"withdrawal amout of $"<<amt
		<<" exceeds your balance.\n"
		<<"withdrawal canceled.\n";
}

void Brass::ViewAcct() const
{
	Formatting f=SetFormat();
	cout<<"brass client:"<<FullName()<<endl;
	cout<<"account number:"<<AcctNum()<<endl;
	cout<<"balance:$"<<Balance()<<endl;
	Restore(f);
}



BrassPlus::BrassPlus(const std::string & s/*="nulldody"*/,long an/*=-1*/,double bal/*=0.0*/,double m1/*=500*/,double r/*=0.10*/)
	:AcctABC(s,an,bal)
{
	maxLoan=m1;
	oweBank=0.0;
	rate=r;
}

BrassPlus::BrassPlus(const Brass & ba,double m1/*=500*/,double r/*=0.1*/)
	:AcctABC(ba)                                                 //用了基类的默认复制构造函数
{
	maxLoan=m1;
	oweBank=0.0;
	rate=r;
}

void BrassPlus::ViewAcct() const
{
	Formatting f=SetFormat();
	cout<<"brassPlus client:"<<FullName()<<endl;
	cout<<"accout number:"<<AcctNum()<<endl;
	cout<<"balance:$"<<Balance()<<endl;
	cout<<"maximum loan:$"<<maxLoan<<endl;
	cout<<"owed to bank:$"<<oweBank<<endl;
	cout.precision(3);
	cout<<"Loan Rate:"<<100*rate<<"%\n";
	Restore(f);
}

void BrassPlus::WithDraw(double amt)
{
	Formatting f=SetFormat();
	double bal=Balance();
	if(amt<=bal)
		AcctABC::WithDraw(amt);
	else if(amt<=bal+maxLoan-oweBank)
	{
		double advance=amt-bal;
		oweBank+=advance*(1.0+rate);
		cout<<"bank advance:"<<advance<<endl;
		cout<<"finance charge:$"<<advance*rate<<endl;
		Deposit(advance);
		AcctABC::WithDraw(amt);
	}
	else
		cout<<"credit limit exceeded.transaction cancelled.\n";
	Restore(f);
}

