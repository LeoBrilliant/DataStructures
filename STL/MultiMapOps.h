/*
 * MultiMapOps.h
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: user
 */

#ifndef STL_MultiMapOps_H_
#define STL_MultiMapOps_H_

#include "STLHeader.h"

template <typename Key, typename Value>
class MultiMapOps
{
typedef typename multimap<Key, Value>::iterator MapIter;
typedef typename multimap<Key, Value>::reverse_iterator RMapIter;

private:
	multimap<Key, Value> mt;

public:
	//Constructor
	MultiMapOps();
	MultiMapOps(MultiMapOps<Key, Value> & m);
	MultiMapOps(MapIter first, MapIter last);

	//Destructor
	~MultiMapOps();

	//Operator
	MultiMapOps<Key, Value> & operator=(MultiMapOps& m) { mt = m.GetMt(); return *this; }

	//Iterators
	MapIter Begin() { return mt.begin(); }
	MapIter End() { return mt.end(); }
	RMapIter Rbegin() { return mt.rbegin(); }
	RMapIter Rend() { return mt.rend(); }

	//Capacity
	bool Empty() { return mt.empty(); }
	size_t Size() { return mt.size(); }
	size_t MaxSize() { return mt.max_size(); }


	//Element access
	Value & operator[](const Key & k) { return mt[k]; }

	//Modifiers
	MapIter Insert(pair<Key, Value>& p) { return mt.insert(p); }
	MapIter Insert(MapIter position, const pair<Key, Value> & p) { return mt.insert(position, p); }
	void Insert(MapIter first, MapIter last) { mt.insert(first, last); }
	void Erase(MapIter position) { mt.erase(position); }
	size_t Erase(const Key& k) { return mt.erase(k); }
	void Erase(MapIter first, MapIter last) { mt.erase(first, last); }
	void Swap(MultiMapOps& x) { mt.swap(x.GetMt); }
	void Clear() { mt.clear(); }

	//Observers
	typename multimap<Key, Value>::key_compare KeyCompare() const { return mt.key_comp(); }
	typename multimap<Key, Value>::value_compare ValueCompare() const { return mt.value_comp(); }

	//Operations
	MapIter Find(const Key& k) { return mt.find(k); }
	size_t Count(const Key& k) { return mt.count(k); }
	MapIter LowerBound(const Key& k) { return mt.lower_bound(k); }
	MapIter UpperBound(const Key& k) { return mt.upper_bound(k); }
	pair<MapIter, MapIter> EqualRange(const Key& k) { return mt.equal_range(k); }

	//Getter
	multimap<Key, Value> & GetMt() { return mt; }

	//Summary
	void GetSummary();
	//Detail
	void GetDetail(const string &);

	// Allocator

};

#endif /* STL_MultiMapOps_H_ */
