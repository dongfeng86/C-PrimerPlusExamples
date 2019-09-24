/*
���ĵ���Ҫ��ʹ������״̬λ��
��״̬λ��3��
badbit��to record a loss of integrity of the stream buffer.���޷���ϵĴ���
eofbit, to record end-of-file while extracting from a stream.���ļ���β��
failbit, to record a failure to extract a valid field from a stream.��δ��ȡ��Ԥ�ڵ��ַ�����

fail()���������badbit����failbit�����ã���fail()��������true��
*/

/*
һ��ģ��eof������:
��windowsƽ̨������һ�����еĿ�ͷ����ctrl + z
��unix�����£�����һ�����еĿ�ʼ������ctrl + D
*/
#include<iostream>
#include<exception>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter numbers:";
	int sum = 0;
	int input=0;
	while (cin >> input)
	{
		sum += input;
	}
	cout << "Last value entered=" << input << std::endl;
	cout << "Sum=" << sum << endl;

	/*��������ڷǳ��ؼ���һ�㣬fail()��faibit,badbit��eofbit������ʱ���᷵��true.
	���ԣ�����Ҫ�ų������ļ���β�������*/
	if (cin.fail() && !cin.eof())
	{
		//������״̬λ��һ���ǳ���Ҫ�ĺ���������Ժ���������������رգ�ֱ��λ�������
		//clear����������״̬λ
		cin.clear();                 
		while (cin.get()!='\n')                 //�����һ�зǷ��ַ�������ַ�
			continue;                           //get(char &)����get(void)�ṩ�������հ׵��ַ����빦��
	}
	else if(cin.eof())
	{
		cout << "I can't go on!\n";
		exit(1);
	}
	cout << "Now enter a new number:\n";
	cin >> input;
	cout << "what you input is :" << input << endl;
}