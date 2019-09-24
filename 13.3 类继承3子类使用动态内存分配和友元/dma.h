#ifndef DMA_H_
#define DMA_H_
#include <iostream>

//Base Class Using DMA
class baseDMA
{
private:
	char * label;
	int rating;
public:
	baseDMA(const char * l="null",int r=0);
	baseDMA(const baseDMA & rs);
	virtual ~baseDMA();
	baseDMA & operator=(const baseDMA & rs);
	friend std::ostream & operator<<(std::ostream & os,const baseDMA & rs);
};

//子类没有使用动态内存分配，不需要写析构函数，采用隐式复制构造函数以及隐式赋值函数即可
class lacksDMA:public baseDMA
{
private:
	enum {COL_LEN=40};
	char color[COL_LEN];
public:
	lacksDMA(const char *C ="blank",const char * l="null",int r=0);
	lacksDMA(const char * c,const baseDMA & rs);
	friend std::ostream & operator <<(std::ostream & os,const lacksDMA & rs);
};

class hasDMA:public baseDMA
{
private:
	char * style;
public:
	hasDMA(const char * s="none",const char * l="null",int r=0);
	hasDMA(const char * s,const baseDMA & rs);
	hasDMA(const hasDMA & hs);
	//派生类的析构函数十分有趣，它总是首先执行自己的代码，然后自动调用基类的析构函数。
	~hasDMA();     
	hasDMA & operator=(const hasDMA & rs);
	friend std::ostream & operator <<(std::ostream & os,const hasDMA & rs);
};
//
#endif
