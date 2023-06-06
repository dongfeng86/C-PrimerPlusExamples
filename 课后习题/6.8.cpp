/*
读取文件
*/

#include<iostream>
#include<fstream>

int main()
{
	//打开一个文档
	std::ifstream fin("C:\\Users\\WD021\\Desktop\\new.txt");
	if (!fin)
	{
		std::cout << "打开文件出错。\n";
	}

	unsigned int nCount=0;
	char ch;
	//如果下面这句用fin.get(ch)的话，是另外一番情景。如果遇到文件为，fin设置状态位，并且，不会设置ch的值，这很重要。
	while ((ch=fin.get()) != EOF/*fin.get(ch)*/)          
	{
		nCount++;
	}
	std::cout << "该文件一共包含 " << nCount << " 个字符.\n";
	fin.close();      //输出流对象过期（如程序终止）时，到文件的连接将自动关闭。另外，也可以使用close()方法显示关闭。

	std::ofstream fout("C:\\Users\\WD021\\Desktop\\新增的文档.txt");
	fout << "nihao，昝东峰！"
		<< "\n继续干！";
	fout.close();

	return 0;
}