/*���ļ���ArrayTP.h��һ���Ľ��棬��ArrayTP�У�ģ�������Ԫ��ͨ��Լ��ģ����Ԫ������ʵ�ֵģ�
������ArrayTP(another method).h���У����õ���ģ����ķ�Լ��ģ����Ԫ����*/
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

	ArrayTP(const ArrayTP & ar);                   //���ƹ��캯��
	ArrayTP & operator=(const ArrayTP & ar);       //���ظ�ֵ�����
	T & operator[](int i);                         //����д���i��Ԫ��
	const T & operator[](int i) const;             //���������ȡ��i��Ԫ��

	template<class T,int n>                        //�����ģ����ķ�Լ��ģ����Ԫ����
	friend std::ostream & operator<<(std::ostream & os, ArrayTP<T, n> & ar);
};

template<class T, int n>
std::ostream & operator<<(std::ostream & os, ArrayTP<T, n> & ar)
{
	os << "�����е�Ԫ��Ϊ��" << std::endl;
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
	//delete[] m_pItems;  //�Լ���һ������ʱ����һ�䲻��д�ϵ�д��ȥ�ˣ����³������ǲ����Զ��˳�
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