#include<iostream>
#include<string>
using namespace std;
struct free_throws
{
	string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
	free_throws one = { "lifeng",13,14 };
	free_throws two = { "haifeng",7,9 };
	free_throws three = { "yinhe",10,16 };
	free_throws team = { "thro",0,0 };

	free_throws dup;
	
	set_pc(one);
	display(one);
	accumulate(team,two);

	/*
	ע��accumulate�����ĺ���ͷ�����ص����������ͣ�����ζ�ŷ��ص���������ݸ�accumulate()��team����
	��������������ʱ����򵥵İ취�Ƿ���һ����Ϊ�������ݸ����������á�
	���accumulate����һ���ṹ�������ǽṹ�����ã����������ṹ���Ƶ�һ����ʱλ�ã��ٽ����������ֵ��dup��Ч��̫�͡�
	*/
	dup = accumulate(team, three);
	cout << "displaying team:\n";
	display(team);
	cout << "displaying dup after assignment:\n";
	display(dup);

}

void display(const free_throws & ft)
{
	cout << "name:" << ft.name << endl;
	cout << " made: " << ft.made << endl;
	cout << "attempts:" << ft.attempts << endl;
	cout << "percent:" << ft.percent << endl;
}

void set_pc(free_throws & ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f*float(ft.made) / float(ft.attempts);
	else
		ft.percent = 0;
}

/*���ò������ڲ������ͺ������&���������͵ķ������ڷ������ͺ������&*/
/*��C#�У����ò���ǰ׺Ϊref���������ǰ׺Ϊout*/
free_throws & accumulate(free_throws & target, const free_throws & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}



