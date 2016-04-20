
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <numeric>

#include <list>

using namespace std;

int VectorTest()
{
	vector<int> vi;

	int a;
	while(true)
	{
		cout << "输入一个整数，0退出：" ;
		cin >> a;

		if(a == 0)
		{
			break;
		}

		vi.push_back(a);

		vector<int>::iterator iter;
		for(iter = vi.begin(); iter != vi.end(); ++iter)
		{
			cout << *iter << ' ' ;
		}
		cout << endl;
	}

	return 0;
}

typedef map<int, int*> m_iip;
typedef map<int, char*> m_icp;

class f_c
{
	int _i;
public:
	f_c(int i) : _i(i){}

	void operator()(m_iip::value_type ite)
	{
		cout << _i++ << "\t" << ite.first << " shi" << endl;
	}

	void operator()(m_icp::value_type ite)
	{
		cout << _i++ << "\t" << ite.first << " yang" << endl;
	}
};

void f(int i, int c)
{
}

void MapTest()
{
	m_iip iip;
	m_icp icp;

	int i = 0;
	iip.insert(make_pair(34, &i));
	iip.insert(make_pair(67, &i));
	iip.insert(make_pair(5, &i));
	iip.insert(make_pair(342, &i));

	char d = 0;
	icp.insert(make_pair(12, &d));
	icp.insert(make_pair(54, &d));
	icp.insert(make_pair(6, &d));
	icp.insert(make_pair(92, &d));

	for_each(iip.begin(), iip.end(), f_c(8));
	for_each(icp.begin(), icp.end(), f_c(65));

	f_c * fct = new f_c(2);

	m_icp::iterator iter = icp.begin(); 
	m_icp::value_type vt(1, &d);
	(*fct)(vt); //(icp, iter);
	(*fct)(*iter);
	//(*fct)(icp[1]);

	//f_c * test = & f_c(8);
}

typedef list<int> LISTINT;
typedef list<char> LISTCHAR;

void ListTest()
{
	LISTINT listOne;

	LISTINT::iterator i;

	listOne.push_front(2);
	listOne.push_front(1);

	listOne.push_back(3);
	listOne.push_back(4);

	cout << "listOne.begin() --- listOne.end():" << endl;

	for(i = listOne.begin(); i != listOne.end(); ++i)
	{
		cout << *i << " " ;
	}
	cout << endl;

	LISTINT::reverse_iterator ir;
	cout << "listOne.rbegin() --- listOne.rend():" << endl;

	for(ir = listOne.rbegin(); ir != listOne.rend(); ++ ir)
	{
		cout << *ir << " ";
	}
	cout << endl;

	int result = accumulate(listOne.begin(), listOne.end(), 0);
	cout << "Sum = " << result << endl;
	cout << "--------------------" << endl;
}

void SizeOfTest()
{
	bool b;
	char c;
	int i;
	float f;
	double d;
	void * vp;
	long l;
	short s;
	long int li;
	long long ll;
	long double ld;
	vector<int> vi;
	void (*fn)();

	cout << "------------------SizeOfTest------------------" << endl;
	cout << "bool: \t" << sizeof(b) << endl;
	cout << "char: \t" << sizeof(c) << endl;
	cout << "int: \t" << sizeof(i) << endl;
	cout << "float: \t" << sizeof(f) << endl;
	cout << "double: \t" << sizeof(d) << endl;
	cout << "void pointer: \t" << sizeof(vp) << endl;
	cout << "long: \t" << sizeof(l) << endl;
	cout << "short: \t" << sizeof(s) << endl;
	cout << "long int: \t" << sizeof(li) << endl;
	cout << "long long: \t" << sizeof(ll) << endl;
	cout << "long double: \t" << sizeof(ld) << endl;
	cout << "vector<int>: \t" << sizeof(vi) << endl;
	cout << "func pointer: \t" << sizeof(fn) << endl;

	cout << "**********************************************" << endl;
	vi.push_back(2);
	vi.push_back(2);
	vi.push_back(2);
	vi.push_back(2);
	vi.push_back(2);
	cout << "vector<int>: \t" << sizeof(vi) << endl;

	vector<double> vd;
	cout << "vector<double>: \t" << sizeof(vd) << endl;
	vd.push_back(1.0);
	vd.push_back(1.0);
	vd.push_back(1.0);
	vd.push_back(1.0);
	cout << "vector<double>: \t" << sizeof(vd) << endl;

	cout << "vector<double>::iterator: \t" << sizeof(vector<double>::iterator) << endl;

	string ss;
	cout << "string: \t" << sizeof(ss) << endl;

	string sh("Hello world!");
	cout << "string: \t" << sizeof(sh) << endl;

	cout << "------------------SizeOfTest------------------" << endl;
}
