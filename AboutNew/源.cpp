#include <malloc.h>
#include <memory.h>

class Blanks
{
public:
	Blanks() {}
	Blanks(int i, double d) {
		int m = i;
		double dd = d * 2;
	}

	//ע�⣬����������operator new����������������������ʹ��new�����ʱ����һ���������������Զ����ݽ�ȥ
	void *operator new(size_t stAllocateBlock, char chInit);
};
void *Blanks::operator new(size_t stAllocateBlock, char chInit)
{
	void *pvTemp = malloc(stAllocateBlock);
	if (pvTemp != 0)
		memset(pvTemp, chInit, stAllocateBlock);
	return pvTemp;
}

int main()
{
	//1.�����θ�new���ݲ���
	//��һ��ʵ���ϱ�ת��Ϊ Blanks *a1 =  Blanks::operator new(sizeof(Blanks),0xa5);
	Blanks *a1 = new(0xa5) Blanks;

	//2.����ʱ������ȫ�ֵ�new	
	//Blanks *a2 = new Blanks;//error����Ϊ����Զ���new������ȫ��new�����Զ����new������������

	//3.��ν�����ȫ�������new������
	//��ʹ�������Զ����new��������Ȼ����ͨ����������������ʹ��ȫ��new
	Blanks* a3 = ::new Blanks;

	//4.new�������γ�ʼ������
	//new�Ĳ�����ͨ��new���������в������д��ݵģ���Blanks�ĳ�ʼ����ͨ��Blanks�������Ŵ��ݽ�ȥ��
	Blanks* a4 = new(0xa5) Blanks(1, 7.5);
}