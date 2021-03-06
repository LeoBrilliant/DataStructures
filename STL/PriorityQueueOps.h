/*
 * PriorityQueue.h
 *
 *  Created on: 2016��1��26��
 *      Author: LeoBrilliant
 */

#ifndef STL_PRIORITYQUEUEOPS_H_
#define STL_PRIORITYQUEUEOPS_H_

#include "STLHeader.h"

template<typename T, class Container = vector<T>,
typename Compare = less<typename Container::value_type> >
class PriorityQueueOps
{
private:
	priority_queue<T, Container, Compare> pqt;

public:
	//Constructor
	PriorityQueueOps():pqt() { cout << "VectorOps Constructor: Default" << endl; }
	PriorityQueueOps(PriorityQueueOps<T, Container, Compare>& pq):pqt(pq.GetPqt())
	{
		cout << "VectorOps Constructor: Copy" << endl;
	}
	PriorityQueueOps(typename Container::iterator first, typename Container::iterator last):pqt(first, last)
	{
		cout << "VectorOps Constructor: Fill dt with iterator from first to last" << endl;
	}

	//Destructor
	~PriorityQueueOps()
	{
		while(!this->Empty())
		{
			this->Pop();
		}
		cout << "DequeOps Destructor: Default" << endl;
	}

	//Capacity
	bool Empty() const { return pqt.empty(); }
	size_t Size() const { return pqt.size(); }

	//Element access
	const T& Top() { return pqt.top(); }

	//Modifiers
	void Push(const T& t) { pqt.push(t); }
	void Pop() { pqt.top(); }

	//Getter
	const priority_queue<T, Container, Compare>& GetPqt() const {
		return pqt;
	}

	//Summary
	void GetSummary();
	//Detail
	void GetDetail(const string &);
};

#endif /* STL_PRIORITYQUEUEOPS_H_ */
