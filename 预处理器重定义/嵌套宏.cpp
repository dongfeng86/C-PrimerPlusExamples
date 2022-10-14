
#include<stdio.h>
#include<iostream>
using namespace std;

#define A(x) T_##x
#define B(x) #@x
#define C(x) #x

#define f(a,b) a##b
#define g(a) #a
#define h(a) g(a)
#define ff(x,y) x+y

#define foo abc
#define foo2(x) x##123
#define foo123 "hehe"

#define Str1 "hello"
#define Cat2Str(x,y) x#y

void main()
{
	printf("%c\n", B(1));       // B(1)------〉'1'
	printf("%s\n", C(1));       // C(1)------〉"1"

	printf("%s\n", h(A(1)));    
	//输出：T_1。
	//宏展开过程为：因h(a)的宏参数前后没有#或者##，因此先展开宏参数A(1)。
	//h(A(1))→h(T_1)→g(T_1)→"T_1"

	printf("%s\n", h(f(1, 2))); 
	//输出:12.
	//宏展开过程为：因宏h(a)的含参数前后没有#或者##，因此先展开宏参数。
	//h(f(1, 2))→h(12)→g(12)→"12"

	printf("%s\n", g(f(1, 2))); 
	//输出:f(1,2)
	//宏展开过程为：因宏g(a)的参数前有#或者##，因此从外层向内层展开。
	//g(f(1, 2))→#f(1,2)→"f(1,2)"

	printf("%d\n", f(f, f(3, 4)));	
	//输出：7。
	//宏展开顺序为：因宏参数前后有##，因此，直接从外层展开， f(f, f(3, 4))→ff(3,4)→3+4

	printf("%s\n", g(1)g(2));		//输出：12
	printf("%s\n", f(g(1), g(2)));	//输出：12
	//这两个例子很特殊，我原以为编译器不会识别g(1)g(2),事实上，编译后会识别连在一起的宏，然后分别展开。
	//宏展开过程为：因为f(a,b)的宏参数前后有#或者##，直接从外层展开。
	//f(g(1), g(2))→g(1)##g(2)→g(1)g(2)→“12”

	printf("%s\n", Cat2Str(Str1, ",nihao"));	//输出：hello",nihao"
	printf("%s\n", Cat2Str(Str1, Str1));		//输出：helloStr1
	//这个例子也比较经典，当宏展参数前有#时，这个参数被当作字符串
	//Cat2Str(Str1, Str1)宏展开过程为：
	//因为Cat2Str(x,y)的y参数前有#，直接将后面的参数转为字符串(也就是该宏参数先从外层展开)
	//Cat2Str(Str1, Str1)→"hello""Str1"→"helloStr1"

	printf("%s\n", foo2(foo));
	//最后,上个经典例子吧。 foo2(foo)的展开可不是abc123哦。
	//宏展开过程为：因为foo2(x)的宏参数前后有#或者##，因此，直接从外层展开。
	//foo2(foo)→foo##123→foo123→"hehe"
}