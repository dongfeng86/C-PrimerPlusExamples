#include<iostream>
#include<fstream>
#include<string>

int main2()
{
	using std::cin;
	using std::cout;
	using std::string;
	using std::ofstream;
	using std::endl;
	using std::ifstream;
	string filename;

	cout << "enter name for new file:";
	cin >> filename;

	//创建输出流对象。只有3步：1.创建一个ofstream对象；2.将其和特定文件关联起来；3.用cout进行文件输入。
	ofstream fout(filename);
	fout << "For your eyes only!\n";
	cout << "enter your secret number:";
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();                           //关闭文件

	//创建输入流。只有3步：1.创建一个ifstream对象；2.将其和特定文件关联起来；3.用cin进行深入。0
	ifstream fin(filename);
	cout << "here are the contents of " << filename << ":\n";
	char ch;
	while (fin.get(ch))
		cout << ch;
	cout << "Done!\n";
	return 0;
}
