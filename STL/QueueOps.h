/*
 * QueueOps.h
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef STL_QUEUEOPS_H_
#define STL_QUEUEOPS_H_

#include "STLHeader.h"

template <typename T, typename Container = deque<T> >
class QueueOps
{
private:
	queue<T, Container> qt;

public:
	//Constructor
	QueueOps():qt() { cout << "VectorOps Constructor: Default" << endl;  }
	QueueOps(const Container & c): qt(c) { cout << "VectorOps Constructor: Copy Container" << endl; }
	QueueOps(QueueOps<T, Container> & q): qt(q.GetQt()) { cout << "VectorOps Constructor: Copy" << endl;}

	//Destructor
	~QueueOps() { while(! qt.empty()) qt.pop(); cout << "DequeOps Destructor: Default" << endl; }

	//Capacity
	bool Empty() const { return qt.empty(); }
	size_t Size() const { return qt.size(); }

	//Element access
	T& Front() { return qt.front(); }
	T& Back() { return qt.back(); }

	//Modifier
	void Push(const T& val) { qt.push(val); }
	void Pop() { qt.pop(); }

	//Getter
	queue<T, Container> & GetQt() { return qt; }

	//Summary
	void GetSummary();
	//Detail
	void GetDetail(const string &);
};

#endif /* STL_QUEUEOPS_H_ */
