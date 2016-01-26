/*
 * MapOps.h
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: user
 */

#ifndef STL_MAPOPS_H_
#define STL_MAPOPS_H_

#include "STLHeader.h"

template <typename T>
class SetOps
{
typedef typename set<T>::iterator SetIter;
typedef typename set<T>::reverse_iterator RSetIter;

private:
	set<T> st;

public:
	//Constructor
	SetOps();
	SetOps(SetOps<T> & s);
	SetOps(SetIter first, SetIter last);

	//Destructor
	~SetOps();

	//Operator
	SetOps<T> & operator=(SetOps& m) { st = m.GetSt(); return *this; }

	//Iterators
	SetIter Begin() { return st.begin(); }
	SetIter End() { return st.end(); }
	RSetIter Rbegin() { return st.rbegin(); }
	RSetIter Rend() { return st.rend(); }

	//Capacity
	bool Empty() { return st.empty(); }
	size_t Size() { return st.size(); }
	size_t MaxSize() { return st.max_size(); }


	//Element access
	T & operator[](const T & k) { return st[k]; }

	//Modifiers
	pair<SetIter, bool> Insert(T& p) { return st.insert(p); }
	SetIter Insert(SetIter position, const T & p) { return st.insert(position, p); }
	void Insert(SetIter first, SetIter last) { st.insert(first, last); }
	void Erase(SetIter position) { st.erase(position); }
	size_t Erase(const T& k) { return st.erase(k); }
	void Erase(SetIter first, SetIter last) { st.erase(first, last); }
	void Swap(SetOps& x) { st.swap(x.GetSt); }
	void Clear() { st.clear(); }

	//Observers
	set<T>::key_compare KeyCompare() const { return st.key_comp(); }
	set<T>::value_compare ValueCompare() const { return st.value_comp(); }

	//Operations
	SetIter Find(const T& k) { return st.find(k); }
	size_t Count(const T& k) { return st.count(k); }
	SetIter LowerBound(const T& k) { return st.lower_bound(k); }
	SetIter UpperBound(const T& k) { return st.upper_bound(k); }
	pair<SetIter, SetIter> EqualRange(const T& k) { return st.equal_range(k); }

	//Getter
	set<T> & GetSt() { return st; }

	//Summary
	void GetSummary();
	//Detail
	void GetDetail(const string &);

	// Allocator

};

#endif /* STL_MAPOPS_H_ */
