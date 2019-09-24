//setops.cpp--���ļ���Ҫ�о�set������ʹ�÷���
/*
��������set�ļ���ֵ����ͬ�ģ�����Ψһ�ġ�multiset������set���������ļ�����Ψһ��
*/
#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>

int main()
{
	using namespace std;
	const int N = 6;
	string s1[N] = { "buffoon","thinkers","for","heavy","can","for" };
	string s2[N] = { "metal","any","food","elegant","deliver","for" };

	set<string> A(s1, s1 + N);                         //set�����Ĺ��췽������Ȼ����ʹ���������������г�ʼ��
	set<string> B(s2, s2 + N);                         //ע�⣬������Ϻ�Ԫ�ؾ�����˳��������С�

	ostream_iterator<string, char> out(cout, " ");     //����ͨ�õ����������
	cout << "Set A:";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "Set B:";
	copy(B.begin(), B.end(), out);
	cout << endl;
	cout << "Union of A and B:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);              //�����������ϵĲ���
	cout << endl;

	cout << "intersection of A and B:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);        //�����������ϵĽ���
	cout << endl;

	cout << "Difference of A and B:\n";                                   //�����������ϵĲ
	set_difference(A.begin(),A.end(),B.begin(),B.end(),out);
	cout << endl;

	set<string> C;
	cout << "Set C:\n";

	//ע�⣬����������������ϵĲ����Ժ󣬽���������˼���C��������set�����У����������ǳ������޷���ֵ��
	//���⣬set_union���������������е����ݣ���Ҫ���������㹻�Ŀռ���������Ϣ��C�ǿյģ����������Ҫ��
	//��ˣ���Ҫʹ�ò�������������в���
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy");
	C.insert(s3);                                            //���ϵĲ������
	cout << "Set C after insertion:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "showing a range:\n";
	//lower_bound �����ص�һ����С�ڼ������ĳ�Ա��upper_bound�����ص�1�����ڼ������ĳ�Ա
	//lower_bound �����ص�һ����С�ڼ������ĳ�Ա��upper_bound�����ص�1�����ڼ������ĳ�Ա
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);   
	cout << endl;
	return 0;
}