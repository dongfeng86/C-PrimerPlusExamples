#include"dma.h"
#include <cstring>

baseDMA::baseDMA(const char * l/*="null"*/,int r/*=0*/)
{
	label=new char[std::strlen(l)+1];
	strcpy_s(label,std::strlen(l)+1,l);
	rating=r;
}

baseDMA::baseDMA(const baseDMA & rs) 
{
	label=new char[strlen(rs.label)+1];              //这是个含有意思的问题，在类的定义中，如果参数是本类对象的话，可以直接访问参数的私有成员；但是在继承类中，不能访问基类的私有成员
	strcpy_s(label,strlen(rs.label)+1,rs.label);
	rating=rs.rating;
}


baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if(this==&rs)                                     //赋值函数，第一步要检测是否是自己给自己赋值
		return * this;
	delete[] label;
	label=new char[std::strlen(rs.label)+1];
	strcpy_s(label,std::strlen(rs.label)+1,rs.label);
	rating=rs.rating;
	return *this;  
}

std::ostream & operator<<(std::ostream & os,const baseDMA & rs)
{
	os<<"label:"<<rs.label<<std::endl;
	os<<"rating:"<<rs.rating<<std::endl;
	return os;
}

//该子类没有动态分配内存，不需要赋复制构造函数和赋值函数
lacksDMA::lacksDMA(const char *C /*="blank"*/,const char * l/*="null"*/,int r/*=0*/)
	:baseDMA(l,r)
{
	strncpy_s(color,40,C,39);
	color[39]='\0';
}

lacksDMA::lacksDMA(const char * c,const baseDMA & rs)
	:baseDMA(rs)
{
	strncpy_s(color,40,c,COL_LEN-1);
	color[COL_LEN-1]='\0';
}

std::ostream & operator <<(std::ostream & os,const lacksDMA & rs)
{
	os<<(baseDMA)rs;                                   //调用基类友元函数经典方法
	os<<"color:"<<rs.color<<std::endl;
	return os;
}


//下面的子类有动态内存分配，因此需要有复制构造函数和赋值构造函数
hasDMA::hasDMA(const char * s/*="none"*/,const char * l/*="null"*/,int r/*=0*/)
	:baseDMA(l,r)
{
	style=new char[std::strlen(s)+1];
	strcpy_s(style,std::strlen(s)+1,s);
}

hasDMA::hasDMA(const char * s,const baseDMA & rs)
	:baseDMA(rs)
{
	style=new char[std::strlen(s)+1];
	strcpy_s(style,std::strlen(s)+1,s);
}

//此赋值构造函数必须要有，因为有动态内存分配
hasDMA::hasDMA(const hasDMA & hs)
	:baseDMA(hs)
{
	style =new char[std::strlen(hs.style)+1];
	strcpy_s(style,std::strlen(hs.style)+1,hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA & rs)
{
	if(this==& rs)
		return * this;
	baseDMA::operator =(rs);
	delete [] style;
	style=new char[std::strlen(rs.style)+1];
	strcpy_s(style,std::strlen(rs.style)+1,rs.style);
	return * this;                         //实现连等
}

std::ostream & operator <<(std::ostream & os,const hasDMA & rs)
{
	os<<(const baseDMA &) rs;              //这个地方可以使用(const baseDMA &)，也可以使用(baseDMA)，有什么区别呢？
	os<<"style:"<<rs.style<<std::endl;
	return os;
}


