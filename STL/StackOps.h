/*
 * StackOps.h
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef STL_STACKOPS_H_
#define STL_STACKOPS_H_

#include "STLHeader.h"

template<typename T, typename Container = deque<T> >
class StackOps
{
private:
	stack<T, Container> st;

public:
	//Constructor
	StackOps():st() { cout << "VectorOps Constructor: Default" << endl; }
	StackOps(StackOps<T, Container>& s):st(s.GetSt())
	{
		cout << "VectorOps Constructor: Copy" << endl;
	}

	//Destructor
	~StackOps()
	{
		while(!this->Empty())
		{
			this->Pop();
		}
		cout << "DequeOps Destructor: Default" << endl;
	}

	//Capacity
	bool Empty() const { return st.empty(); }
	size_t Size() const { return st.size(); }

	//Element access
	T& Top() { return st.top(); }

	//Modifier
	void Push(const T& val) { st.push(val); }
	void Pop() { st.pop(); }

	//Getter
	stack<T, Container>& GetSt() { return st; }

	//Summary
	void GetSummary();
	//Detail
	void GetDetail(const string &);
};

#endif /* STL_STACKOPS_H_ */
