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
		vector<SReview>::iterator pIter;                        //迭代器相当于一个广义指针，可以解除引用，递增等等
		for (pIter = arBooks.begin(); pIter != arBooks.end(); pIter++)
		{
			ShowReview(*pIter);
		}
		vector<SReview> arOldList(arBooks);                     //复制已经创建的vector数组
		if (iNum > 3)
		{
			//删除两个元素
			arBooks.erase(arBooks.begin() + 1, arBooks.begin() + 3);
			cout << "After erasure:\n";
			for (pIter = arBooks.begin(); pIter != arBooks.end(); pIter++)
				ShowReview(*pIter);
			//插入一个元素
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
	std::getline(std::cin, rr.sTitle);    //getline会读取一行，即便是空行，它会读取回车
	if ("q" == rr.sTitle)
		return false;
	std::cout << "enter book rating:\n";
	std::cin >> rr.iRating;               //cin跳过空格，读取字符串，并将最后一个不匹配的字符留在输入队列中
	if (!std::cin)
		return false;                     //如果输入了非整数，那么错误，函数返回
	while (std::cin.get() != '\n')        //cin.get()取出一个字符，回车也不例外。这一行是把cin留下的回车符从输入流中取出
		continue;
	return true;
}

void ShowReview(const SReview & rr)
{
	std::cout << rr.iRating << "\t" << rr.sTitle << std::endl;
}