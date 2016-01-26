/*
 * DequeOperations.h
 *
 *  Created on: 2016Äê1ÔÂ25ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef STL_DEQUEOPERATIONS_H_
#define STL_DEQUEOPERATIONS_H_

#include <deque>
#include <iostream>
#include <cstddef>

using namespace std;

template <typename T>
class DequeOps
{
typedef typename deque<T>::iterator dtiter;

private:
	deque<T> dt;

public:
	//Constructors
	DequeOps();
	DequeOps(DequeOps&);
	//DequeOps(size_t);
	DequeOps(size_t, const T&);
	DequeOps(typename deque<T>::const_iterator, typename deque<T>::const_iterator);
	//Destructors
	~DequeOps()
	{
		dt.clear();
		cout << "DequeOps Destructor: Default" << endl;
	}

	//Operator
	DequeOps & operator=(DequeOps&);
	T & operator[](size_t);

	//Iterators
	typename deque<T>::const_iterator Begin() { return dt.begin(); }
	typename deque<T>::const_iterator End()  { return dt.end();}
	typename deque<T>::const_reverse_iterator & Rbegin()const { return dt.rbegin();}
	typename deque<T>::const_reverse_iterator & Rend()const { return dt.rend();}

	//Capacity
	size_t Size() { return dt.size(); }
	size_t MaxSize() { return dt.max_size(); }
	bool Empty() { return dt.empty(); }
	void Resize(size_t n, T& t = T()) { dt.resize(n, t); }

	//Element access
	T& At(size_t i) { return dt.at(i); }
	const T& Front() const { return dt.front(); }
	const T& Back() const { return dt.back(); }

	//Modifiers
	inline void Assign(typename deque<T>::iterator & first, typename deque<T>::iterator & last)
	{
		dt.assign(first, last);
	}
	inline void Assign(size_t n, const T& t){ dt.assign(n, t); }
	inline void PushBack(const T & t){ dt.push_back(t); }
	inline void PushFront(const T & t) { dt.push_front(t); }
	inline void PopBack() { dt.pop_back(); }
	inline void PopFront() { dt.pop_front(); }
	dtiter & Insert(dtiter position, const T& t) { return dt.insert(position, t); }
	void Insert(dtiter position, size_t n, const T & t) { dt.insert(position, n, t); }
	void Insert(dtiter position, dtiter first, dtiter last) { dt.insert(position, first, last); }
	dtiter Erase(dtiter position) { return dt.erase(position); }
	dtiter Erase(dtiter first, dtiter last) { return dt.erase(first, last); }
	void Swap(DequeOps<T> & t) { dt.swap(t.GetDt()); }
	void Clear() { dt.clear(); }

	// Getter
	deque<T> & GetDt() { return this->dt; }

	//Summary
	void GetSummary();
	//Detail
	void GetDetail(const string &);

	//Allocator
};

void DequeOpsTest();

#endif /* STL_DEQUEOPERATIONS_H_ */
