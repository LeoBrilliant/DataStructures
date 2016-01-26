/*
 * DequeOperations.cpp
 *
 *  Created on: 2016Äê1ÔÂ25ÈÕ
 *      Author: LeoBrilliant
 */


#include "DequeOperations.h"

template<typename T>
DequeOps<T>::DequeOps(): dt()
{
	cout << "VectorOps Constructor: Default" << endl;
}

template<typename T>
DequeOps<T>::DequeOps(DequeOps<T>& t): dt(t.GetDt())
{
	cout << "VectorOps Constructor: Copy" << endl;
}

template<typename T>
DequeOps<T>::DequeOps(size_t n, const T& t): dt(n, t)
{
	cout << "VectorOps Constructor: Allocate N elements, initialized with default or value-given" << endl;
}

template<typename T>
DequeOps<T>::DequeOps(typename deque<T>::const_iterator first, typename deque<T>::const_iterator last): dt(first, last)
{
	cout << "VectorOps Constructor: Fill dt with iterator from first to last" << endl;
}

template<typename T>
DequeOps<T> & DequeOps<T>::operator=(DequeOps<T> & t)
{
	this->dt = t.GetDt();
	return *this;
}

template<typename T>
T & DequeOps<T>::operator[](size_t i)
{
	return this->dt[i];
}

template<typename T>
void DequeOps<T>::GetSummary()
{
	cout << "Summary[" << endl;
	cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	cout << "max_size: \t" << this->MaxSize() << endl;
	cout << "]" << endl;
}

template<typename T>
void DequeOps<T>::GetDetail(const string & s)
{
	cout << s << endl;
	this->GetSummary();
	cout << "Elements[" << endl;
	dtiter iv = dt.begin();
	while(iv != dt.end())
	{
		cout << *iv++ << "<->" ;
	}
	cout << "]" << endl;
}

static void DequeOpsConstructorTest()
{
	DequeOps<char> dc;
	dc.GetDetail("Test: Default Constructor");

	//DequeOps<int> di(10);
	//di.GetDetail("Test: 10 int default value");

	DequeOps<int> di2(10, 2);
	di2.GetDetail("Test: 10 int 2");

	DequeOps<int> di3(di2);
	di3[0] = 3;
	di3.GetDetail("Test: Copy Consturctor");

	DequeOps<int> di4(di2.Begin(), di2.End());
	di4[0] = 4;
	di4.GetDetail("Test: Constructed by iterator from first to last ");
}

void DequeOpsTest()
{
	DequeOpsConstructorTest();
}

