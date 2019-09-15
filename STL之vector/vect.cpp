#include<iostream>
#include<string>
#include<vector>

struct SReview
{
	std::string sTitle;
	int iRating;
};

bool FillReview(SReview &rr);

void ShowReview(const SReview & rr);

int main()
{
	using std::cout;
	using std::vector;
	vector<SReview> arBooks;
	SReview cTemp;
	while (FillReview(cTemp))
	{
		arBooks.push_back(cTemp);
	}
	int iNum = arBooks.size();
	if (iNum > 0)
	{
		cout << "Thank you ,you entered the following:\n"
			<< "Rating\tBook\n";
		for (int i = 0; i < iNum; i++)
			ShowReview(arBooks[i]);
		cout << "Reprising:\n"
			<< "Rating\tBook\n";
		vector<SReview>::iterator pIter;                        //�������൱��һ������ָ�룬���Խ�����ã������ȵ�
		for (pIter = arBooks.begin(); pIter != arBooks.end(); pIter++)
		{
			ShowReview(*pIter);
		}
		vector<SReview> arOldList(arBooks);                     //�����Ѿ�������vector����
		if (iNum > 3)
		{
			//ɾ������Ԫ��
			arBooks.erase(arBooks.begin() + 1, arBooks.begin() + 3);
			cout << "After erasure:\n";
			for (pIter = arBooks.begin(); pIter != arBooks.end(); pIter++)
				ShowReview(*pIter);
			//����һ��Ԫ��
			arBooks.insert(arBooks.begin(), arOldList.begin() + 1, arOldList.begin() + 2);
			cout << "After insertion:\n";
			for (pIter = arBooks.begin(); pIter != arBooks.end(); pIter++)
				ShowReview(*pIter);
		}
		arBooks.swap(arOldList);
		cout << "Swapping Oldlist with books:\n";
		for (pIter = arBooks.begin(); pIter != arBooks.end(); pIter++)
			ShowReview(*pIter);
	}
	else
		cout << "nothing entered,nothing gained.\n";
	return 0;
}

bool FillReview(SReview &rr)
{
	std::cout << "enter book title (q to quit):";
	std::getline(std::cin, rr.sTitle);    //getline���ȡһ�У������ǿ��У������ȡ�س�
	if ("q" == rr.sTitle)
		return false;
	std::cout << "enter book rating:\n";
	std::cin >> rr.iRating;               //cin�����ո񣬶�ȡ�ַ������������һ����ƥ����ַ��������������
	if (!std::cin)
		return false;                     //��������˷���������ô���󣬺�������
	while (std::cin.get() != '\n')        //cin.get()ȡ��һ���ַ����س�Ҳ�����⡣��һ���ǰ�cin���µĻس�������������ȡ��
		continue;
	return true;
}

void ShowReview(const SReview & rr)
{
	std::cout << rr.iRating << "\t" << rr.sTitle << std::endl;
}