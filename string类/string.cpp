/*
该文件主要使用了string类的构造函数，重载的运算符以及length()方法
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

int main()
{
	using namespace std;

	//以下主要使用了string的各个构造函数，以及+,=,[]运算符
	string sOne("Lottery Winner!");     //将string 对象初始化为常规C-风格字符串
	cout << sOne << endl;
	string sTwo(20, '$');               //将string对象初始化为20个'$'组成的字符串
	cout << sTwo << endl;

	string sThree(sTwo);                //复购构造函数，将string 对象初始化为另一个string对象
	cout << sThree << endl; 

	sOne += " Oops";                    //string重载了+= 运算符
	cout << sOne << endl;        

	sTwo = "Sorry!That was ";           //string 重载了 = 运算符

	sThree[0] = 'P';                    //string 重载了 下标运算符
	cout << sThree << endl;

	string sFour;
	sFour = sTwo + sThree;              //string 重载了+ 号和= 号运算符
	cout << sFour << endl;

	char szAlls[] = "All is well that ends well";

	string sFive(szAlls, 20);
	cout << sFive << endl;

	string sSix(szAlls + 6, szAlls + 10);         //第一个参数用于寻址要插入的源范围中的第一个元素，第二个参数用于寻址要插入的源范围中超出最后一个元素的元素的位置。
	cout << sSix << ", ";
	
	string sSeven(&sFive[6], &sFive[10]);
	cout << sSeven << endl;

	string sEight(sFour, 7, 16);                  //从第7个字符开始，一直向后复制16个字符
	cout << sEight << " in motion!" << endl;


	//以下主要是计算string字符串的字符个数
	cout << "\n现在，我们来看下如何计算string字符串的字符个数\n";
	char charr[20];
	string str;
	//string对象和C-风格对象如何查询字符的数量;
	//函数strlen()主要用来计算C风格字符串的字符个数，不包含末尾的0；而string方法length()用来计算string字符串的字符个数；
	cout << "length of string in charr before input:\n"
		<< strlen(charr) << endl;                           //这里输出是31，因为strlen()会一直检索字符数直到遇到空字符
	cout << "length of string in str befor input: "
		<< str.length() << endl;
	cout << "enter a line of text:\n";
	cin.getline(charr, 20);
	cout << "you entered: " << charr << endl;
	cout << "enter anoter line of text:\n";
	getline(cin, str);
	cout << "you entered: " << str << endl;
	cout << "length of string in charr after input:"
		<< strlen(charr) << endl;
	cout << "length of string in str after input:"
		<< str.length() << endl;

	cout << "现在，实验以下用cin>>string对象输入单词\n";
	cin >> str;                                             //这种方法主要是向string字符串中输入一个单词
	cout << "你输入的是：" << str << endl;


	cout << "\n\n\n现在，我们看看从文件中读取每一句话到相应的string对象中，然后在屏幕上显示:\n";
	ifstream fin;
	string sRoute = "C:\\Users\\WD021\\Desktop\\某个文件.txt";
	fin.open(sRoute);
	if (false == fin.is_open())
	{
		cerr << "can't open file. Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item);
	while (fin)
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item);
	}
	cout << "Done\n";
	fin.close();
	return 0;
}