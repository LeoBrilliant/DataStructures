
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
		cout << "����һ��������0�˳���" ;
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
