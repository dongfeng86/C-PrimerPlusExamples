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
	virtual void WithDraw(double amt);         //�������������鷽��
	double Balance() const;
	virtual void ViewAcct() const;
	//ע�⣬�������������������Ϊ�麯���Ǹ�����������
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
	virtual void ViewAcct() const;				//�����ڻ��౻����Ϊ������������Զ���Ϊ�鷽��������ʡȥvirtual�ؼ���
	virtual void WithDraw(double amt);          //���������override����д�������������麯��
	void ResetMax(double m) { maxLoan = m; }
	void ResetRats(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};
#endif // !BRASS_H_

