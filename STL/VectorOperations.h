/*
 * VectorOperations.h
 *
 *  Created on: 2016Äê1ÔÂ24ÈÕ
 *      Author: user
 */

#ifndef STL_VECTOROPERATIONS_H_
#define STL_VECTOROPERATIONS_H_


#include <vector>
#include <iostream>
#include <cstddef>

using namespace std;

template<typename T>
class VectorOps
{
private:
	vector<T> vt;
public:
	//Constructor
	VectorOps();
	VectorOps(VectorOps &);
	VectorOps(size_t);
	VectorOps(size_t, const T&);
	VectorOps(typename vector<T>::const_iterator&, typename vector<T>::const_iterator&);

	//Destructor
	~VectorOps();

	//Assign content
	VectorOps<T> & operator=(VectorOps<T> & vo)
	{
		vt = vo.GetVt();
		return *this;
	}

	//getter
	vector<T>& GetVt(){ return vt; }

	//Iterators
	typename vector<T>::const_iterator & Begin(){ return vt.begin();}
	typename vector<T>::const_iterator & End(){ return vt.end(); }
	typename vector<T>::const_reverse_iterator & Rbegin() { return vt.rbegin();}
	typename vector<T>::reverse_iterator & Rend() { return vt.rend(); }

	//Capacity
	size_t Size() { return vt.size(); }
	size_t MaxSize(){ return vt.max_size();}
	size_t Capacity(){ return vt.capacity();}
	bool Empty() { return vt.empty();}
	void Reserve(size_t n){ vt.reserve(n);}

	//Element access
	T & operator[](size_t i);
	T & At(size_t i){ return vt.at(i); }
	T & Front() { return vt.front();}
	T & Back() { return vt.back();}
	T * Data() { return vt.data();}

	//Modifiers
	void Resize(size_t n) { vt.resize(n); }
	void Assign(size_t n, const T &t) { vt.assign(n, t);}
	void Assign(typename vector<T>::const_iterator& first, typename vector<T>::const_iterator& last)
	{
		vt.assign(first, last);
	}
	void PushBack(const T& t){ vt.push_back(t); }
	void PopBack() { vt.pop_back(); }

	typename vector<T>::iterator Insert(typename vector<T>::iterator position, const T& t)
	{
		return vt.insert(position, t);
	}
	void Insert(typename vector<T>::iterator position,
			size_t n, const T& t)
	{
		vt.insert(position, n, t);
	}

	void Insert(typename vector<T>::iterator position,
			typename vector<T>::iterator first,
			typename vector<T>::iterator last)
	{
		vt.insert(position, first, last);
	}

	typename vector<T>::iterator Erase(typename vector<T>::iterator position)
	{
		return vt.erase(position);
	}

	typename vector<T>::iterator Erase(typename vector<T>::iterator first,
			typename vector<T>::iterator last)
	{
		return vt.erase(first, last);
	}

	void Swap(VectorOps<T>& v){ vt.swap(v.GetVt()); }

	//Summary
	void GetSummary();
	//Detail
	void GetDetail();
};

void VectorOpsTest();

#endif /* STL_VECTOROPERATIONS_H_ */
