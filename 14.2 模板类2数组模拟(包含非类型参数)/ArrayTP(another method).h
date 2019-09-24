/*该文件是ArrayTP.h的一个改进版，在ArrayTP中，模板类的友元是通过约束模板友元函数来实现的，
但是在ArrayTP(another method).h当中，采用的是模板类的非约束模板友元函数*/
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

template<class T, int n>
class ArrayTP
{
private:
	T * m_pItems;
	int nNum;
public:
	ArrayTP();
	~ArrayTP();

	ArrayTP(const ArrayTP & ar);                   //复制构造函数
	ArrayTP & operator=(const ArrayTP & ar);       //重载赋值运算符
	T & operator[](int i);                         //允许写入第i个元素
	const T & operator[](int i) const;             //仅仅允许读取第i个元素

	template<class T,int n>                        //这个是模板类的非约束模板友元函数
	friend std::ostream & operator<<(std::ostream & os, ArrayTP<T, n> & ar);
};

template<class T, int n>
std::ostream & operator<<(std::ostream & os, ArrayTP<T, n> & ar)
{
	os << "数组中的元素为：" << std::endl;
	for (int i = 0; i < n; i++)
	{
		os << ar.m_pItems[i] << std::endl;
	}
	return os;
}

template<class T, int n>
inline ArrayTP<T, n>::ArrayTP()
{
	m_pItems = new T[n];
	nNum = n;
}

template<class T, int n>
inline ArrayTP<T, n>::~ArrayTP()
{
	delete[] m_pItems;
}

template<class T, int n>
inline ArrayTP<T, n>::ArrayTP(const ArrayTP & ar)
{
	m_pItems = new T[n];
	for (int i = 0; i < n; i++)
	{
		m_pItems[i] = ar[i];
	}
}

template<class T, int n>
inline ArrayTP<T, n> & ArrayTP<T, n>::operator=(const ArrayTP & ar)
{
	//delete[] m_pItems;  //自己第一次做的时候，这一句不该写上的写上去了，导致程序总是不能自动退出
	if (this == &ar)
		return *this;
	for (int i = 0; i < n; i++)
	{
		m_pItems[i] = ar[i];
	}
	return *this;
}

template<class T, int n>
inline T & ArrayTP<T, n>::operator[](int i)
{
	if (i<0 || i>n - 1)
	{
		std::cerr << "error in array limits:" << i << " is out of range\n";
		std::exit(EXIT_FAILURE);
	}
	return m_pItems[i];
}

template<class T, int n>
inline const T & ArrayTP<T, n>::operator[](int i) const
{
	if (i<0 || i>n - 1)
	{
		std::cerr << "error in array limits:" << i << " is out of range\n";
		std::exit(EXIT_FAILURE);
	}
	return m_pItems[i];
}
#endif // !ARRAYTP_H_