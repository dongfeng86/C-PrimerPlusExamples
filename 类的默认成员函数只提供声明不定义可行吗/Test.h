#pragma once

struct Test
{
	int m;
	int n;

	Test(int x, int y);
	//Test(const Test &);					//�����˲�ʵ�֣����������������ˣ��ͻᱨ��
	void heheheh();
};

Test::Test(int x, int y)
{
	m = x;
	n = y;
}