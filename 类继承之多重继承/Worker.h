//本文档主要是多重继承基类的头文件
#ifndef WORKER_H_
#define WORKER_H_

#include <string>

class Worker
{
private:
	std::string m_fullname;
	long m_lId;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker():m_fullname("no one"),m_lId(0){ }
	Worker(const std::string & s,long n)
		:m_fullname(s),m_lId(n){ }

	/*=0 指出这是纯虚函数，在类中可以定义也可以不定义;但是，在基类中将
	析构函数设为虚的，是一个惯例；另外，即便基类析构函数是纯虚的，也必须定义*/
	virtual ~Worker() = 0;                
	virtual void Set() = 0;               //纯虚函数，注意，如果说子类没有覆写纯虚函数，子类也会成为抽象类
	virtual void Show() const = 0;        //纯虚函数
};

class Waiter :virtual public Worker       //注意，这里基类是虚基类
{
private:
	int m_iPanache;
protected:
	void Data() const;                    //基类中为虚方法，在派生类中自动为虚方法
	void Get();
public:
	Waiter():Worker(),m_iPanache(0){ }
	Waiter(const std::string & s,long n,int p=0)
		:Worker(s,n),m_iPanache(p){ }
	Waiter(const Worker & wk,int p=0)
		:Worker(wk),m_iPanache(p){ }
	void Set();
	void Show() const;
};

class Singer :virtual public Worker
{
protected:
	enum{other,alto,contralto,soprano,bass,baritone,tenor};
	enum {Vtypes=7};
	void Data() const;
	void Get();
private:
	static char * m_pv[Vtypes];
	int m_iVoice;
public:
	Singer():Worker(),m_iVoice(other){ }
	Singer(const std::string & s,long n,int v=other)
		:Worker(s,n),m_iVoice(v){ }
	Singer(const Worker & wk,int v=other)
		:Worker(wk),m_iVoice(v){ }
	void Set();
	void Show() const;
};

//下面类是多重继承
//注意，两个基类必须是public类型的，如果不加修饰符，就会变成private类型
class SingingWaiter :public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() {}

	/*注意，这是多重继承一个经典的用法。当基类为虚时，禁止信息通过中间类自动传递给基类。例如下面构造函数的定义，
	Waiter(s,n,p)和Singer(s,n,v)不会调用基类Worker；如果没有Worker(s,n)，编译器将调用基类的默认构造函数；如果写出
	了Worker(s,n)，则编译器调用Worker的带参构造函数*/
	SingingWaiter(const std::string & s,long n,int p=0,int v=other)
		:Worker(s,n),Waiter(s,n,p),Singer(s,n,v){ }
	SingingWaiter(const Worker & wk,int p=0,int v=other)
		:Worker(wk),Waiter(wk,p),Singer(wk,v){ }          //即便不调用，也需要把Waiter和SSingingWaiter参数写全
	SingingWaiter(const Waiter & wt,int v=other)
		:Worker(wt),Waiter(wt),Singer(wt,v){ }            //这是一个经典用法，用子类构造父类
	SingingWaiter(const Singer & wt,int p=0)
		:Worker(wt),Waiter(wt,p),Singer(wt) { }           //这个太妙了，用子类构造父类，并且用子类构造同父异子类对象
	void Set();
	void Show() const;
};

#endif