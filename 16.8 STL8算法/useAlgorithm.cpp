//该文档综合使用了多种容器
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iterator>
#include<algorithm>
#include<cctype>

using namespace std;

char toLower(char ch) { return tolower(ch); }
string & ToLower(string & st);
void display(const string & s);

int main()
{
	vector<string> arWords;
	cout << "enter words(enter quit to quit):\n";
	string input;
	while (cin >> input && input != "quit")
	{
		arWords.push_back(input);
	}
	cout << "you entered the following words:\n";
	for_each(arWords.begin(), arWords.end(), display);
	cout << endl;

	set<string> setWord;
	transform(arWords.begin(), arWords.end(),
		insert_iterator<set<string>>(setWord, setWord.begin()), ToLower);
	cout << "\nAlphabetic list of words:\n";
	for_each(setWord.begin(), setWord.end(), display);
	cout << endl;

	//place word and frequency in map。map::[] can insert an element into a map with a specified key value.
	map<string, int> mapWord;
	set<string>::iterator si;
	for (si = setWord.begin(); si != setWord.end(); si++)
		mapWord[*si] = count(arWords.begin(), arWords.end(), *si);

	//display map contents.注意，map::[]不仅可以插入一个元素，还可以显示键值对应的数值
	cout << "\nWord frequency:\n";
	for (si = setWord.begin(); si != setWord.end(); si++)
		cout << *si << ": " << mapWord[*si] << endl;

	return 0;
}

string & ToLower(string & st)
{
	transform(st.begin(), st.end(), st.begin(), tolower);
	return st;
}

void display(const string & s)
{
	cout << s << " ";
}