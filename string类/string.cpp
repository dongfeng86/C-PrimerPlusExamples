/*
���ļ���Ҫʹ����string��Ĺ��캯�������ص�������Լ�length()����
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

int main()
{
	using namespace std;

	//������Ҫʹ����string�ĸ������캯�����Լ�+,=,[]�����
	string sOne("Lottery Winner!");     //��string �����ʼ��Ϊ����C-����ַ���
	cout << sOne << endl;
	string sTwo(20, '$');               //��string�����ʼ��Ϊ20��'$'��ɵ��ַ���
	cout << sTwo << endl;

	string sThree(sTwo);                //�������캯������string �����ʼ��Ϊ��һ��string����
	cout << sThree << endl; 

	sOne += " Oops";                    //string������+= �����
	cout << sOne << endl;        

	sTwo = "Sorry!That was ";           //string ������ = �����

	sThree[0] = 'P';                    //string ������ �±������
	cout << sThree << endl;

	string sFour;
	sFour = sTwo + sThree;              //string ������+ �ź�= �������
	cout << sFour << endl;

	char szAlls[] = "All is well that ends well";

	string sFive(szAlls, 20);
	cout << sFive << endl;

	string sSix(szAlls + 6, szAlls + 10);         //��һ����������ѰַҪ�����Դ��Χ�еĵ�һ��Ԫ�أ��ڶ�����������ѰַҪ�����Դ��Χ�г������һ��Ԫ�ص�Ԫ�ص�λ�á�
	cout << sSix << ", ";
	
	string sSeven(&sFive[6], &sFive[10]);
	cout << sSeven << endl;

	string sEight(sFour, 7, 16);                  //�ӵ�7���ַ���ʼ��һֱ�����16���ַ�
	cout << sEight << " in motion!" << endl;


	//������Ҫ�Ǽ���string�ַ������ַ�����
	cout << "\n���ڣ�������������μ���string�ַ������ַ�����\n";
	char charr[20];
	string str;
	//string�����C-��������β�ѯ�ַ�������;
	//����strlen()��Ҫ��������C����ַ������ַ�������������ĩβ��0����string����length()��������string�ַ������ַ�������
	cout << "length of string in charr before input:\n"
		<< strlen(charr) << endl;                           //���������31����Ϊstrlen()��һֱ�����ַ���ֱ���������ַ�
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

	cout << "���ڣ�ʵ��������cin>>string�������뵥��\n";
	cin >> str;                                             //���ַ�����Ҫ����string�ַ���������һ������
	cout << "��������ǣ�" << str << endl;


	cout << "\n\n\n���ڣ����ǿ������ļ��ж�ȡÿһ�仰����Ӧ��string�����У�Ȼ������Ļ����ʾ:\n";
	ifstream fin;
	string sRoute = "C:\\Users\\WD021\\Desktop\\ĳ���ļ�.txt";
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