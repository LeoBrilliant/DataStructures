/*
 * StackOps.cpp
 *
 *  Created on: 2016Äê1ÔÂ26ÈÕ
 *      Author: LeoBrilliant
 */

#include "StackOps.h"


template<typename T, typename Container>
inline void StackOps<T, Container>::GetSummary() {
	cout << "Summary[" << endl;
	cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	cout << "]" << endl;
}

template<typename T, typename Container>
inline void StackOps<T, Container>::GetDetail(const string& s) {
	cout << s << endl;
	this->GetSummary();
	cout << "Elements[" << endl;
	stack<T, Container> tmp;
	while(!this->Empty())
	{
		tmp.push(this->Top());
		this->Pop();
	}
	while(!tmp.empty())
	{
		cout << tmp.top() << "->" ;
		this->Push(tmp.top());
		tmp.pop();
	}
	cout << "]" << endl;
}


