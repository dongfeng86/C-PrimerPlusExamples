
#include<iostream>
#include<iterator>
#include<vector>
#include<string>
#include <algorithm>

void OutPut(const std::string & s) { std::cout << s << " "; }

int main()
{
	using namespace std;
	
	//C++֧�ֽ���β�ĸ����������飬�����Ҫ��
	string arS1[4] = { "fine","fish","fashion","fate" };
	string arS2[2] = { "busy","bats" };
	string arS3[2] = { "silly","singers" };
	vector<string> arWords(4);

	//������ͨ���鵽vector���鵱��
	cout << "now let us see the elements in vector:\n";
	copy(arS1, arS1 + 4, arWords.begin());                     //��C++�У��������һ��Ԫ�غ���ĵ�ַ�ǿ��õġ�Ҳ����˵��C++����β�ĸ�����������ͨ���顣
	for_each(arWords.begin(), arWords.end(), OutPut);
	cout << endl;
	//����һ������İ취,�������������
	cout << "now ,the vector array will be shown on screen by ostream_iterator.\n";
	ostream_iterator<string,char> out_iter(cout, " ");
	/*ע�⣬copy�������������������������㹻��Ŀռ䣬�ܹ�������Щֵ��
	��copy�����Զ����ݷ���ֵ����Ŀ�������ĳ��ȡ�����취�ǲ��ò��������*/
	copy(arWords.begin(), arWords.end(), out_iter);
	cout << endl;

	//�����������ʹ��
	cout << "if we reverse the vector,as shown in below:\n";
	for_each(arWords.rbegin(), arWords.rend(), OutPut);
	cout << endl;
	//����һ�ַ����������ʹ�÷���
	cout << "Explicit use of reverse iterator.\n";
	vector<string>::reverse_iterator ri;                       //��ʾ��ʹ�÷��������
	for (ri = arWords.rbegin(); ri != arWords.rend(); ri++)
	{
		OutPut(*ri);
	}
	cout << endl;
	//ʹ��C++11�л��ڷ�Χ��forѭ��
	cout << "����ʹ�û��ڷ�Χ��forѭ��\n";
	for (auto x : arWords)
		OutPut(x);
	cout << endl;

	//����β�����������
	cout << "ͨ������β���������������arWordsβ������arS2��ǰ����Ԫ��\n";
	copy(arS2, arS2 + 2, back_insert_iterator<vector<string>>(arWords));
	for_each(arWords.begin(), arWords.end(), OutPut);
	cout << endl;

	//�����Ĳ��������
	cout << "ͨ�������������������arWords�в���arS3��ǰ����Ԫ��\n";
	//copy(arS3, arS3 + 2, arWords.end());         //��һ���Ǵ�ģ��������Ϊ�ڴ�Υ�������
	copy(arS3, arS3 + 2, insert_iterator<vector<string>>(arWords, arWords.begin()));
	for_each(arWords.begin(), arWords.end(), OutPut);
	cout << endl;

	//����Ĵ����Ǵ�ģ���Ϊvector<string>û��push_front����
	////������ͷ�����������
	//cout << "ͨ������ͷ���������������arwords�в���arS3��ǰ����Ԫ��\n";
	//copy(arS2, arS2 + 1, front_insert_iterator<vector<string>>(arWords));
	//for_each(arWords.begin(), arWords.end(), OutPut);
	//cout << endl;

	return 0;
}