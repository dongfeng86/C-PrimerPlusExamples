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

	//�������������ֻ��3����1.����һ��ofstream����2.������ض��ļ�����������3.��cout�����ļ����롣
	ofstream fout(filename);
	fout << "For your eyes only!\n";
	cout << "enter your secret number:";
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();                           //�ر��ļ�

	//������������ֻ��3����1.����һ��ifstream����2.������ض��ļ�����������3.��cin�������롣0
	ifstream fin(filename);
	cout << "here are the contents of " << filename << ":\n";
	char ch;
	while (fin.get(ch))
		cout << ch;
	cout << "Done!\n";
	return 0;
}
