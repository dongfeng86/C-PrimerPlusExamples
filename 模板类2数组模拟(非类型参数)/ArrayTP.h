/*该头文件主要定义数组模板，其中数组模板同时采用了类型参数和非类型参数*/
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

/*在该模板中，数组元素的类型为T，数组元素的数量为n*/
template<class T,int n>
class ArrayTP
{
private:
	T * m_pItems;
public:
	ArrayTP();
	~ArrayTP();

	ArrayTP(const ArrayTP & ar);               //复制构造函数
	ArrayTP & operator=(const ArrayTP & ar);   //重载赋值运算符
	T & operator[](int i);                         //允许写入第i个元素
	const T & operator[](int i) const;             //仅仅允许读取第i个元素

	////创建一个显示元素的友元函数
	//friend std::ostream & operator<<(std::ostream os, ArrayTP<T,n> & ar);
};

template<class T, int n>
inline ArrayTP<T, n>::ArrayTP()
{
	m_pItems = new T[n];      
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
inline ArrayTP<T,n> & ArrayTP<T, n>::operator=(const ArrayTP & ar)
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
		/*cerr对应标准错误流，用于显示错误消息。默认情况下被关联到标准输出流，
		但它不被缓冲，也就说错误消息可以直接发送到显示器，而无需等到缓冲区或
		者新的换行符时，才被显示。一般情况下不被重定向。*/
		std::cerr << "error in array limits:" << i << " is out of range\n";
		/*The exit function, declared in the standard include file STDLIB.H,terminates 
		a C++ program.The value supplied as an argument to exit is 	returned to the 
		operating system as the program's return code or exit code. By convention, 
		a return code of zero means that the program completed successfully.*/
		std::exit(EXIT_FAILURE);       
	}
	return m_pItems[i];
}

template<class T, int n>
inline const T & ArrayTP<T, n>::operator[](int i) const
{
	if(i<0 || i>n-1)
	{ 
		std::cerr << "error in array limits:" << i << " is out of range\n";
		std::exit(EXIT_FAILURE);
	}
	return m_pItems[i];
}


#endif // !ARRAYTP_H_