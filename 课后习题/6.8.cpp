/*
��ȡ�ļ�
*/

#include<iostream>
#include<fstream>

int main()
{
	//��һ���ĵ�
	std::ifstream fin("C:\\Users\\WD021\\Desktop\\new.txt");
	if (!fin)
	{
		std::cout << "���ļ�����\n";
	}

	unsigned int nCount=0;
	char ch;
	//������������fin.get(ch)�Ļ���������һ���龰����������ļ�Ϊ��fin����״̬λ�����ң���������ch��ֵ�������Ҫ��
	while ((ch=fin.get()) != EOF/*fin.get(ch)*/)          
	{
		nCount++;
	}
	std::cout << "���ļ�һ������ " << nCount << " ���ַ�.\n";
	fin.close();      //�����������ڣ��������ֹ��ʱ�����ļ������ӽ��Զ��رա����⣬Ҳ����ʹ��close()������ʾ�رա�

	std::ofstream fout("C:\\Users\\WD021\\Desktop\\�������ĵ�.txt");
	fout << "nihao���ö��壡"
		<< "\n�����ɣ�";
	fout.close();

	return 0;
}