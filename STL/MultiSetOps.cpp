/*
 * MultiSetOps.cpp
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: user
 */

#include "MultiSetOps.h"

template<typename T>
MultiSetOps<T>::MultiSetOps(): st()
{
	cout << "VectorOps Constructor: Default" << endl;
}

template<typename T>
MultiSetOps<T>::MultiSetOps(MultiSetOps<T> &m): st(m.GetSt())
{
	cout << "VectorOps Constructor: Copy" << endl;
}

template<typename T>
MultiSetOps<T>::MultiSetOps(SetIter first, SetIter last):st(first, last)
{
	cout << "VectorOps Constructor: Fill dt with iterator from first to last" << endl;
}

template<typename T>
MultiSetOps<T>::~MultiSetOps()
{
	st.clear();
	cout << "MultiSetOps Destructor: Default" << endl;
}

template<typename T>
void MultiSetOps<T>::GetSummary()
{
	cout << "Summary[" << endl;
	cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	cout << "max_size: \t" << this->MaxSize() << endl;
	cout << "]" << endl;
}

template<typename T>
void MultiSetOps<T>::GetDetail(const string & s)
{
	cout << s << endl;
	this->GetSummary();
	cout << "Elements[" << endl;
	SetIter iv = this->Begin();
	while(iv != this->End())
	{
		cout << "<" << *iv >> ">" ;
		++iv;
	}
	cout << "]" << endl;
}
