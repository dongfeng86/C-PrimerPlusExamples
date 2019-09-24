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

//����û��ʹ�ö�̬�ڴ���䣬����Ҫд����������������ʽ���ƹ��캯���Լ���ʽ��ֵ��������
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
	//���������������ʮ����Ȥ������������ִ���Լ��Ĵ��룬Ȼ���Զ����û��������������
	~hasDMA();     
	hasDMA & operator=(const hasDMA & rs);
	friend std::ostream & operator <<(std::ostream & os,const hasDMA & rs);
};
//
#endif
