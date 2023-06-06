//#include<cstring>
#include "String.h"
#include<string>

std::string str;

using std::cin;
using std::cout;

int String::num_strings = 0;             //ע�⣬û��statci�ؼ���

int String::HowMany()
{
	return num_strings;
}

String::String(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str,len, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[4];
	str[0] = '\0';
	num_strings++;
}

/*
��ʾ���帴�ƹ��캯������Ȼϵͳ�ᶨ��һ��Ĭ�ϵģ�Ĭ�ϸ��ƹ��캯������ִ��ǳ���ƣ��������
���ƷǾ�̬��Ա��ֵ���������ָ��Ļ�����������ָ���ֵ����������ָ��ָ�������
*/
String::String(const String & st)                 
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len+1, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;             //���str��NULL�Ļ���Ҳ����
}

/*
��ʾ���帳ֵ�����������ϵͳ������Ĭ�ϵĸ�ֵ����������ǣ��ܲ��ң���ֵ�������Ȼִ�е���
ǳ��ֵ����������Էǳ�Ա���ݽ��и�ֵ����̬��Ա������Ӱ��*/
String & String::operator=(const String & st)     
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;

	//����һ�ַ�ʽ��ʵ��,�����Ҫ�Ƚ���������
	char* psz = *((char**)&st);
	int iLenNew = sizeof(psz);

	str = new char[len + 1];
	strcpy_s(str, len+1,st.str);
	return *this;
	// TODO: �ڴ˴����� return ���
}

String & String::operator=(const char * s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];

	//����һ������ĺ����������ָ����������һ�������Ļ�������ʧ�ܣ�ֻ���������������������غ�����
	//�����һ�������Ǹ������ַ��û�����⣬����������������������ʽ
	//���⣬�м�Ļ�������Ŀ����ΪԪ����+1
	strcpy_s(str,len+1, s);                    
	return *this;
}

char & String::operator[](int i)
{
	return str[i];
}

const char & String::operator[](int i) const       //��ע�⣬��������������const�ͷ�const�������������ר�������������ַ���
{
	return str[i];
}


//ע�⣬����ȫ��������Ԫ�����ˣ�����Ҫ����������������
bool operator<(const String & st, const String & st2)
{
	return (std::strcmp(st.str, st2.str) < 0);
}

bool operator>(const String & st, const String & st2)
{
	return st2<st;
}

bool operator==(const String & st, const String & st2)
{
	return (std::strcmp(st.str,st2.str)==0);
}

ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

istream & operator >> (istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
	{
		continue;
	}
	return is;
}
