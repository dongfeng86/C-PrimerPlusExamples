//stack.h ,该头文件采用模板类的方法，模拟栈的使用。
//模板不是类和成员函数的定义，模板是C++编译器指令，不能将模板成员函数放在独立的实现文件中。
//最简单的方式是将所有模板信息放在一个头文件当中，并在要使用模板的文件中包含该头文件。

#ifndef STACK_H_
#define STACK_H_

/*下面定义了一个模板类，注意，它是以template <class type>打头；
关键字class 可以用 typename替代
*/
template <class Type>
class Stack
{
private:
	enum {SIZE=10};
	int m_iStackSize;
	Type * m_pItems;
	int m_iTop;
public:
	explicit Stack(int ss = SIZE);             //这里使用explict避免隐式变换
	Stack(const Stack & st);
	~Stack() { delete[] m_pItems; }
	bool IsEmpty() { return m_iTop == 0; }
	bool IsFull() { return m_iTop == m_iStackSize; }
	bool push(const Type & item);             //在栈中增加一个数据
	bool pop(Type & item);                    //在栈中弹出一个数据
	Stack & operator=(const Stack & st);      //可以在模板类声明中采用简写的Stack，代表Stack<Type>
};


template<class Type>
Stack<Type>::Stack(int ss) :m_iStackSize(ss), m_iTop(0)
{
	m_pItems = new Type[m_iStackSize];           //采用动态内存分配确定栈中的元素占据空间大小
}

/*因采用动态内存分配，因此定义了复制构造函数; 这里还有个有意思的事情，在模板声明或者模板函数定义
内，可以使用缩写版本的Stack，在类的外面，即指定返回类型或者使用作用域解析运算符时，必须使用完整
的Stack<Type>*/
template<class Type>
Stack<Type>::Stack(const Stack/*<Type>*/ & st)   
{
	m_iStackSize = st.m_iStackSize;
	m_iTop = st.m_iTop;
	m_pItems = new Type[st.m_iStackSize];
	for (int i = 0; i < m_iStackSize; i++)
	{
		m_pItems[i] = st.m_pItems[i];
	}
}

template<class Type>
bool Stack<Type>::push(const Type & item)
{
	if (m_iTop < m_iStackSize)
	{
		m_pItems[m_iTop++] = item;
		return true;
	}
	else
		return false;
}

template<class Type>
bool Stack<Type>::pop(Type & item)
{
	if (m_iTop > 0)
	{
		item = m_pItems[--m_iTop];
		return true;
	}
	else
		return false;
}

template<class Type>
Stack<Type> & Stack<Type>::operator=(const Stack/*<Type>*/ & st)
{
	if (this == &st)
		return *this;
	delete[] m_pItems;
	m_iStackSize = st.m_iStackSize;
	m_iTop = st.m_iTop;
	m_pItems = new Type[m_iStackSize];
	for (int i = 0; i < m_iStackSize; i++)
	{
		m_pItems[i] = st.m_pItems[i];
	}
	return *this;
}

#endif // !STACK_H_

