/*
 * ValArrayOps.h
 *
 *  Created on: 2016Äê1ÔÂ30ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef STL_VALARRAYOPS_H_
#define STL_VALARRAYOPS_H_

#include "STLHeader.h"

template<typename T>
class ValArrayOps
{
private:
	valarray<T> vt;
public:
	//Constructor
	ValArrayOps() : vt() { }
	ValArrayOps(size_t n) : vt(n) { }
	ValArrayOps(const T& val, size_t n) : vt(val, n) { }
	ValArrayOps(const T* p, size_t n) : vt(p, n) { }
	ValArrayOps(ValArrayOps<T>& x) : vt(x.GetVt()) { }
	ValArrayOps(const slice_array<T>& sub) : vt(sub) { }
	ValArrayOps(const gslice_array<T>& sub) : vt(sub) { }
	ValArrayOps(const mask_array<T>& sub) : vt(sub) { }
	ValArrayOps(const indirect_array<T>& sub) : vt(sub) { }

	//Destructor
	~ValArrayOps() { }

	//Operator
	ValArrayOps<T>& operator=(valarray<T>& x){ vt = x;  return *this;}
	ValArrayOps<T>& operator=(const T& val) { vt = val; return *this; }
	ValArrayOps<T>& operator=(const slice_array<T>& sub){ vt = sub; return *this; }
	ValArrayOps<T>& operator=(const gslice_array<T>& sub){ vt = sub; return *this; }
	ValArrayOps<T>& operator=(const mask_array<T>& sub) { vt = sub; return *this; }
	ValArrayOps<T>& operator=(const indirect_array<T>& sub) { vt = sub; return *this; }

	T operator[](size_t n) const { return vt[n]; }
	T& operator[](size_t n) { return vt[n]; }
	valarray<T> operator[](slice slc) const { return vt[slc]; }
	slice_array<T> operator[](slice slc) { return vt[slc]; }
	valarray<T> operator[](const gslice& gslc) const { return vt[gslc]; }
	gslice_array<T> operator[](const gslice& gslc) { return vt[gslc]; }
	valarray<T> operator[](const valarray<bool>& msk) const { return vt[msk]; }
	mask_array<T> operator[](const valarray<bool>& msk) { return vt[msk]; }
	valarray<T> operator[](const valarray<size_t>& ind) const { return vt[ind]; }
	indirect_array<T> operator[](const valarray<size_t>& ind) { return vt[ind]; }

	//Member functions
	valarray<T> Apply(T (*func)(T)){ return vt.apply(func); }
	valarray<T> CShift(int n) const { return vt.shift(n); }
	T Max() const { return vt.max(); }
	T Min() const { return vt.min(); }
	void Resize(size_t sz) { vt.resize(sz); }
	void Resize(size_t sz, T c) { vt.resize(sz, c); }
	valarray<T> Shift(int n) const { return vt.shift(n); }
	size_t Size() const { return vt.size(); }
	T Sum() const { return vt.sum(); }
	void Swap(ValArrayOps<T>& x) noexcept { vt.swap(x.GetVt()); }

	//Getter
	valarray<T>& GetVt() { return vt; }

	//Summary
	void GetSummary()
	{
		cout << "Summary[" << endl;
		cout << "Size: \t" << this->Size() << endl;
		this->Size() ? ( cout << "Min: \t" << this->Min() << endl ,	cout << "Max: \t" << this->Max() << endl, cout << "Sum: \t" << this->Sum() << endl 	) :  (cout << endl) ;
		cout << "]" << endl;
	}

	void GetDetail(const string& s = "")
	{
		//cout << s << endl;
		this->GetSummary();
		cout << "Elements[" << endl;
		auto iterBegin = begin(this->vt);
		auto iterEnd = end(this->vt);

		while(iterBegin != iterEnd)
		{
			cout << *iterBegin++ << ", " ;
		}
		cout << "]" << endl;
	}
};


#endif /* STL_VALARRAYOPS_H_ */
