#pragma once
#ifndef BRASS_H_
#define BRASS_H_
#include<string>

//brass account class
class Brass
{
private:
	std::string fullName;
	long accNum;
	double balance;
public:
	Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double emt);
	virtual void WithDraw(double amt);         //基类中声明了虚方法
	double Balance() const;
	virtual void ViewAcct() const;
	//注意，将基类的析构函数声明为虚函数是个惯例做法。
	virtual ~Brass(){}
};

//brass plus account class
class BrassPlus :public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string & s = "NullBody", long an = -1,
		double bal = 0.0, double m1 = 500,
		double r = 0.11125);
	BrassPlus(const Brass & ba, double m1 = 500, double r = 0.11125);
	virtual void ViewAcct() const;				//方法在基类被声明为虚后，在派生类自动成为虚方法；可以省去virtual关键字
	virtual void WithDraw(double amt);          //派生类可以override（覆写）任意多个基类虚函数
	void ResetMax(double m) { maxLoan = m; }
	void ResetRats(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};
#endif // !BRASS_H_

