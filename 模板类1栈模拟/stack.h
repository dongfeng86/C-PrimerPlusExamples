//stack.h ,��ͷ�ļ�����ģ����ķ�����ģ��ջ��ʹ�á�
//ģ�岻����ͳ�Ա�����Ķ��壬ģ����C++������ָ����ܽ�ģ���Ա�������ڶ�����ʵ���ļ��С�
//��򵥵ķ�ʽ�ǽ�����ģ����Ϣ����һ��ͷ�ļ����У�����Ҫʹ��ģ����ļ��а�����ͷ�ļ���

#ifndef STACK_H_
#define STACK_H_

/*���涨����һ��ģ���࣬ע�⣬������template <class type>��ͷ��
�ؼ���class ������ typename���
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
	explicit Stack(int ss = SIZE);             //����ʹ��explict������ʽ�任
	Stack(const Stack & st);
	~Stack() { delete[] m_pItems; }
	bool IsEmpty() { return m_iTop == 0; }
	bool IsFull() { return m_iTop == m_iStackSize; }
	bool push(const Type & item);             //��ջ������һ������
	bool pop(Type & item);                    //��ջ�е���һ������
	Stack & operator=(const Stack & st);      //������ģ���������в��ü�д��Stack������Stack<Type>
};


template<class Type>
Stack<Type>::Stack(int ss) :m_iStackSize(ss), m_iTop(0)
{
	m_pItems = new Type[m_iStackSize];           //���ö�̬�ڴ����ȷ��ջ�е�Ԫ��ռ�ݿռ��С
}

/*����ö�̬�ڴ���䣬��˶����˸��ƹ��캯��; ���ﻹ�и�����˼�����飬��ģ����������ģ�庯������
�ڣ�����ʹ����д�汾��Stack����������棬��ָ���������ͻ���ʹ����������������ʱ������ʹ������
��Stack<Type>*/
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

