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

	//注意，这里重载了operator new函数，接受两个参数，在使用new运算符时，第一个参数编译器会自动传递进去
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
	//1.理解如何给new传递参数
	//这一句实际上被转换为 Blanks *a1 =  Blanks::operator new(sizeof(Blanks),0xa5);
	Blanks *a1 = new(0xa5) Blanks;

	//2.理解何时会屏蔽全局的new	
	//Blanks *a2 = new Blanks;//error，因为类的自定义new屏蔽了全局new，而自定义的new有两个参数，

	//3.如何解除类对全局运算符new的屏蔽
	//即使类中有自定义的new，我们仍然可以通过作用域解析运算符使用全局new
	Blanks* a3 = ::new Blanks;

	//4.new运算符如何初始化对象
	//new的参数是通过new后面括号中参数进行传递的，而Blanks的初始化是通过Blanks其后的括号传递进去的
	Blanks* a4 = new(0xa5) Blanks(1, 7.5);
}