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
	label=new char[strlen(rs.label)+1];              //���Ǹ�������˼�����⣬����Ķ����У���������Ǳ������Ļ�������ֱ�ӷ��ʲ�����˽�г�Ա�������ڼ̳����У����ܷ��ʻ����˽�г�Ա
	strcpy_s(label,strlen(rs.label)+1,rs.label);
	rating=rs.rating;
}


baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if(this==&rs)                                     //��ֵ��������һ��Ҫ����Ƿ����Լ����Լ���ֵ
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

//������û�ж�̬�����ڴ棬����Ҫ�����ƹ��캯���͸�ֵ����
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
	os<<(baseDMA)rs;                                   //���û�����Ԫ�������䷽��
	os<<"color:"<<rs.color<<std::endl;
	return os;
}


//����������ж�̬�ڴ���䣬�����Ҫ�и��ƹ��캯���͸�ֵ���캯��
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

//�˸�ֵ���캯������Ҫ�У���Ϊ�ж�̬�ڴ����
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
	return * this;                         //ʵ������
}

std::ostream & operator <<(std::ostream & os,const hasDMA & rs)
{
	os<<(const baseDMA &) rs;              //����ط�����ʹ��(const baseDMA &)��Ҳ����ʹ��(baseDMA)����ʲô�����أ�
	os<<"style:"<<rs.style<<std::endl;
	return os;
}


