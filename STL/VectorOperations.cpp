/*
 * VectorOperations.cpp
 *
 *  Created on: 2016Äê1ÔÂ23ÈÕ
 *      Author: user
 */

#include "VectorOperations.h"

void VectorMethods()
{
	vector<int> vi;
//	vi.assign();
//	vi.assign();
//	vi.at();
//	vi.back();
//	vi.begin();
//	vi.capacity();
//	vi.clear();
//	vi.data();
//	vi.empty();
//	vi.end();
//	vi.erase();
//	vi.erase();
//	vi.front();
//	vi.insert();
//	vi.insert();
//	vi.insert();
//	vi.max_size();
//	vi.pop_back();
//	vi.push_back();
//	vi.rbegin();
//	vi.rend();
//	vi.reserve();
//	vi.resize();
//	vi.size();
//	vi.swap();
}

template<class T>
VectorOps<T>::VectorOps():vt()
{
	cout << "VectorOps Constructor: Default" << endl;
}

template<typename T>
VectorOps<T>::VectorOps(VectorOps<T> & v):vt(v.GetVt())
{
	cout << "VectorOps Constructor: Copy" << endl;
}

template<class T>
VectorOps<T>::VectorOps(size_t n):vt(n)
{
	cout << "VectorOps Constructor: Allocate N elements, not initialized" << endl;
}

template<typename T>
VectorOps<T>::VectorOps(size_t n, const T & t):vt(n, t)
{
	cout << "VectorOps Constructor: Allocate N elements, initialized as t" << endl;
}

template<typename T>
VectorOps<T>::VectorOps(typename vector<T>::const_iterator & first, typename vector<T>::const_iterator & last):vt(first, last)
{
	cout << "VectorOps Constructor: Fill vt with first to last" << endl;
}

template<class T>
VectorOps<T>::~VectorOps()
{
	vt.clear();
	cout << "VectorOps Destructor: Default" << endl;
}

template<class T>
T & VectorOps<T>::operator[](size_t i)
{
	if( i >= 0 && i < this->Size())
		return vt[i];

	return vt[i];
}

template<typename T>
void VectorOps<T>::GetSummary()
{
	cout << "Summary[" << endl;
	cout << "empty: \t" << (this->Empty()? "True":"False") << "\t" << endl;
	cout << "size: \t" << this->Size() << endl;
	cout << "max_size: \t" << this->MaxSize() << endl;
	cout << "capacity: \t" << this->Capacity() << endl;
	cout << "]" << endl;
}

template<typename T>
void VectorOps<T>::GetDetail()
{
	this->GetSummary();
	cout << "Elements[" << endl;
	typename vector<T>::iterator iv = vt.begin();
	while(iv != vt.end())
	{
		cout << *iv++ << "," ;
	}
	cout << "]" << endl;
}

void VectorOpsTest()
{
	VectorOps<int> vo1;
	vo1.GetDetail();

	VectorOps<char> vo2(10);
	vo2.GetDetail();

	VectorOps<double> vo3(20, 3.1415926);
	vo3.GetDetail();

	VectorOps<double> vo4(vo3);
	vo4[0] = 12345678;
	vo4.GetDetail();
	vo3.GetDetail();

	vector<double>::const_iterator vbegin = vo4.GetVt().begin();
	vector<double>::const_iterator vend = vo4.GetVt().end();
	VectorOps<double> vo5(vbegin, vend);
	vo5[0] = 50000;
	vo5.GetDetail();
	vo4.GetDetail();

	cout << "Reserve: Before" << endl;
	vo1.GetDetail();
	vo1.Reserve(12);
	cout << "Reserve: After" << endl;
	vo1.GetDetail();

	cout << "Resize: Shrink" << endl;
	vo3.Resize(5);
	vo3.GetDetail();

	cout << "Resize: Expand" << endl;
	vo4.Resize(25);
	vo4.GetDetail();

	cout << "Operator: =======" << endl;
	VectorOps<double> vo6(4) ;
	vo6 = vo3;
	vo6[0] = 6000;
	vo6.GetDetail();
	vo3.GetDetail();

	cout << "Swap: --------" << endl;
	vo6.Swap(vo3);
	vo6.GetDetail();
	vo3.GetDetail();
}
