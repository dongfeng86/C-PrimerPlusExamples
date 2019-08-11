#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stack.h"

const int Num = 10;
int main()
{
	std::srand(std::time(0));       //���������
	std::cout << "please enter stack size:\n";
	int iStackSize;
	std::cin >> iStackSize;
	Stack<const char *> st(iStackSize);

	/*�����и���������⣬�ַ��������ڱ�������ʵ����const char *���ͣ�ָ��ָ�������Ϊ����	���Լ�����ͼ��ָ������Ϊ
	�ǳ������ͣ����ڸı�ĳ���ַ�����ĳ���ַ�ֵ�����ʧ�ܡ�	���ǣ��ַ���ȷʵ���Ը�ֵ��ָ���const ���͵�ָ��*/
	/*const*/ char * szIn[Num] = {
		"1:hank gilgmes",
		"2:KiKi Ishtar",
		"3:Betty Rocker",
		"4:Ian Flagranti",
		"5:wolgfang",
		"6:portia",
		"7:yoy",
		"8:Xaverie",
		"9:Juan Moore",
		"10:Misha Mache"
	};

	//������������ַ�������Ϊconst char *���ͣ�û�а취�޸ġ�
	//szIn[0][2] = 'g';
	//std::cout << szIn[0] << std::endl;

	const char * szOut[Num];
	int iProcessed = 0;
	int iNextin = 0;
	while (iProcessed < Num)
	{
		if (st.IsEmpty())
			st.push(szIn[iNextin++]);
		else if (st.IsFull())
			st.pop(szOut[iProcessed++]);
		else if (std::rand() % 2 && iNextin < Num)
			st.push(szIn[iNextin++]);
		else
			st.pop(szOut[iProcessed++]);
	}

	for (int i = 0; i < Num; i++)
	{
		std::cout << szOut[i] << std::endl;
	}

	std::cout << "Bye\n";
	return 0;
}