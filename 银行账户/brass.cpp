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
//������Ĺ��캯���������๹�캯������ʹ�û��๹�캯������������û��๹�캯��������ʹ��Ĭ�ϵĻ��๹�캯��
//C++ʹ�ó�Ա��ʼ���б��﷨����������
BrassPlus::BrassPlus(const std::string & s, long an, double bal, double m1, double r)
	:Brass(s,an,bal)
{
	maxLoan = m1;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double m1, double r)
	:Brass(ba)              //brass��Ȼû����ʾ���帴�ƹ��캯�������ǣ������Ĭ�Ϲ���һ�����ƹ��캯����ִ��ǳ����
{
	maxLoan = m1;
	owesBank = 0.0;
	rate = r;
}
//���¶���������麯��
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

//���¶����������е��麯��
void BrassPlus::WithDraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();                //������̳��˻����Balance����
	if (amt <= bal)
		Brass::WithDraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "bank advance:$" << advance << endl;
		cout << "Finace charge:$" << advance*rate << endl;
		//��������������һ���ǳ��������ƣ��Ȱ�Ԥ����ӵ��˻�����У�Ȼ����û����ȡ�����ʹ����Ϊ0
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