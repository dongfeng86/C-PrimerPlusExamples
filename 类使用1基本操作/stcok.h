//stock.h--augmented version
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>

//头文件，这就是C/S模式中的服务器文件。
class Stock
{
private:
	std::string company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares*share_val; }
public:
	Stock();                //默认构造函数
	Stock(const std::string & co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;        //奇怪的函数声明，保证函数不修改调用对象，因为调用对象是常量
	const Stock & topval(const Stock & s) const;
};

#endif 
