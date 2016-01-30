/*
 * ValArrayOps.h
 *
 *  Created on: 2016Äê1ÔÂ30ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef VALARRAYOPSTEST_H_
#define VALARRAYOPSTEST_H_

#include "../ValArrayOps.h"
//#include <cstdlib>
//#include <cstdio>
#include <typeinfo>
#include <cassert>

template <typename T>
class ValArrayOpsTest
{
	static unsigned int caseCount;
	static unsigned int casePassed;
public:
	//Constructor
	ValArrayOpsTest() {}

	//Constructor Test
	void ContructorTest();

};

template<typename T>
unsigned int ValArrayOpsTest<T>::caseCount = 0;
template<typename T>
unsigned int ValArrayOpsTest<T>::casePassed = 0;

template<typename T>
inline void ValArrayOpsTest<T>::ContructorTest() {
	caseCount ++ ;
	//cout << __func__ << endl;

	//cout << "TestCase(" << caseCount << "\t): " << __FUNCTION__ << " \t"  ;
	ValArrayOps<T> vi;
	cout << typeid(vi).name() << "\t";
	assert( typeid(vi) == typeid(ValArrayOps<T>));
	//assert( &vi != NULL);

	vi.GetDetail("Hello");
	casePassed ++;
	cout << "Passed" << endl;
}

#endif /* VALARRAYOPSTEST_H_ */
