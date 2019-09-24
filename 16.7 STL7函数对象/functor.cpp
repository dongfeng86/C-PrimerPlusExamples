#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
#include<vector>
#include<functional>

void Show(double);
const int LIM = 6;

template<class T>
class TooBig
{
private:
	T m_cutOff;
public:
	TooBig(const T & t):m_cutOff(t){ }
	bool operator() (const T & v) { return v > m_cutOff; }
};

void OutInt(int m) { std::cout << m << " "; }

int main()
{
	using std::list;
	using std::cout;
	using std::endl;
	using std::vector;

	//一，下面利用自定义的一元谓词对序列进行操作
	TooBig<int> cF100(100);
	int vals[10] = { 50,100,90,180,60,210,415,88,188,201 };
	list<int> lstYa(vals, vals + 10);
	list<int> lstEtcetera = { 50,100,90,180,60,210,415,88,188,201 };
	//list<int> lstEtcetera(vals, vals + 10);

	cout << "original list:\n";
	for_each(lstYa.begin(), lstYa.end(), OutInt);
	cout << endl;

	for_each(lstEtcetera.begin(), lstEtcetera.end(), OutInt);
	cout << endl;
	lstYa.remove_if(cF100);                      //Erases elements from a list for which a specified predicate is satisfied.

	lstEtcetera.remove_if(TooBig<int>(200));
	cout << "trimmed lists:\n";
	for_each(lstYa.begin(), lstYa.end(), OutInt);
	cout << endl;
	for_each(lstEtcetera.begin(), lstEtcetera.end(), OutInt);
	cout << endl;

	//利用预定义的函数符对数列进行操作
	double arr1[LIM] = { 28,29,30,35,38,59 };
	double arr2[LIM] = { 63,65,69,75,80,99 };
	vector<double> gr8(arr1, arr1 + LIM);
	vector<double> m8(arr2, arr2 + LIM);
	cout.setf(std::ios_base::fixed);
	cout.precision(1);
	cout << "gr8:\t";
	for_each(gr8.begin(), gr8.end(), Show);
	cout << endl;
	cout << "m8:\t";
	for_each(m8.begin(), m8.end(), Show);
	cout << endl;

	vector<double> sum(LIM);
	transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), std::plus<double>());
	cout << "sum:\t";
	for_each(sum.begin(), sum.end(), Show);
	cout << endl;

	vector<double> prod(LIM);
	transform(gr8.begin(), gr8.end(), prod.begin(), std::bind1st(std::multiplies<double>(), 2.5));
	cout << "prod:\t";
	for_each(prod.begin(), prod.end(), Show);
	cout << endl;
	return 0;
}

void Show(double v)
{
	std::cout.width(6);
	std::cout << v << ' ';
}
