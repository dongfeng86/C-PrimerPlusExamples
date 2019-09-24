#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

struct SReview
{
	std::string sTitle;
	int iRating;
};

bool operator <(const SReview & r1, const SReview & r2);
bool WorseThan(const SReview & r1, const SReview & r2);
bool FillReview(SReview & rr);
void ShowReview(const SReview & rr);

int main()
{
	using namespace std;
	vector<SReview> arBooks;
	SReview cTemp;
	while (FillReview(cTemp))
		arBooks.push_back(cTemp);
	if (arBooks.size() > 0)
	{
		cout << "Thank you .you entered the following "
			<< arBooks.size() << " ratings:\n"
			<< "Rating\tBook\n";
		for_each(arBooks.begin(), arBooks.end(), ShowReview);

		sort(arBooks.begin(), arBooks.end());
		cout << "sorted by titles:\nRating\tBook\n";
		for_each(arBooks.begin(), arBooks.end(), ShowReview);

		sort(arBooks.begin(), arBooks.end(), WorseThan);
		cout << "sorted by rating:\nRating\tBook\n";
		for_each(arBooks.begin(), arBooks.end(), ShowReview);

		random_shuffle(arBooks.begin(), arBooks.end());
		cout << "After shuffling:\nRating\tBook\n";
		for_each(arBooks.begin(), arBooks.end(), ShowReview);
	}
	else
	{
		cout << "Bye.\n";
		return 0;
	}

}

bool operator<(const SReview & r1, const SReview & r2)
{
	if (r1.sTitle < r2.sTitle)
		return true;
	else if (r1.sTitle == r2.sTitle && r1.iRating < r2.iRating)
		return true;
	else
		return false;
}

bool WorseThan(const SReview & r1, const SReview & r2)
{
	if (r1.iRating < r2.iRating)
		return true;
	else
		return false;
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
	while (std::cin.get() != '\n')        //cin.get()取出下一个字符，回车也不例外。这一行是把cin留下的回车符从输入流中取出
		continue;
	return true;
}

void ShowReview(const SReview & rr)
{
	std::cout << rr.iRating << "\t" << rr.sTitle << std::endl;
}