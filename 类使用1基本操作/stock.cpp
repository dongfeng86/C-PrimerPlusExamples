//stock.cppʵ���ļ�
#include <iostream>
#include "stcok.h"


//Ĭ�Ϲ��캯��
Stock::Stock()
{
	company = "no name";
	shares = 0;
	share_val = 0;
	total_val = 0.0;
}

//���캯��
Stock::Stock(const std::string & co, long n, double pr)
{
	company = co;
	
	if (n < 0)
	{
		std::cout << "number of shares can't be negative;"
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
}


//�������캯��
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "number of shares puchased can't be negative. "
			<< "transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "number of shares sold can't be negative. "
			<< "transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "you cant sell more than you have1 "
			<< "transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show() const              //ע�����const����֤���Բ��޸ĵ������Ķ���
{
	using std::cout;
	//using std::iso_base;

	cout << "company:" << company << " ;shares: " << shares << std::endl;
	cout << "  share Price:$" << share_val;
	cout << "  tatal worth:$" << total_val << std::endl;
}

const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}
