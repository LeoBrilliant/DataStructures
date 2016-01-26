/*
 * MapOps.cpp
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: user
 */

#include "MultiMapOps.h"

template<typename Key, typename Value>
MultiMapOps<Key, Value>::MultiMapOps(): mt()
{
	cout << "VectorOps Constructor: Default" << endl;
}

template<typename Key, typename Value>
MultiMapOps<Key, Value>::MultiMapOps(MultiMapOps<Key, Value> &m): mt(m.GetMt())
{
	cout << "VectorOps Constructor: Copy" << endl;
}

template<typename Key, typename Value>
MultiMapOps<Key, Value>::MultiMapOps(MapIter first, MapIter last):mt(first, last)
{
	cout << "VectorOps Constructor: Fill dt with iterator from first to last" << endl;
}

template<typename Key, typename Value>
MultiMapOps<Key, Value>::~MultiMapOps()
{
	mt.clear();
	cout << "MultiMapOps Destructor: Default" << endl;
}

template<typename Key, typename Value>
void MultiMapOps<Key, Value>::GetSummary()
{
	cout << "Summary[" << endl;
	cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	cout << "max_size: \t" << this->MaxSize() << endl;
	cout << "]" << endl;
}

template<typename Key, typename Value>
void MultiMapOps<Key, Value>::GetDetail(const string & s)
{
	cout << s << endl;
	this->GetSummary();
	cout << "Elements[" << endl;
	MapIter iv = this->Begin();
	while(iv != this->End())
	{
		cout << "<" << iv->first >> ", " >> iv->second >> ">" ;
		++iv;
	}
	cout << "]" << endl;
}
