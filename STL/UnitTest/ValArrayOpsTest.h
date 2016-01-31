/*
 * ValArrayOps.h
 *
 *  Created on: 2016年1月30日
 *      Author: LeoBrilliant
 */

#ifndef VALARRAYOPSTEST_H_
#define VALARRAYOPSTEST_H_

#include "../ValArrayOps.h"
//#include <cstdlib>
//#include <cstdio>
#include <typeinfo>
#include <cassert>
#include <cerrno>
#include <stdexcept>
#include<iomanip>

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

	//Operator= Test
	void OperatorEqualTest();

	//Exception Test
	void ExceptioinTest();

	//Signal Test
	void SignalTest();

	//Operator[] Test
	void OperatorSquareBracketsTest();

	//Apply Test
	void ApplyTest();

	//Shift Test
	void ShiftTest();

	//Resize Test
	void ResizeTest();

	//Test suite
	void TestSuite();

};

template<typename T>
unsigned int ValArrayOpsTest<T>::caseCount = 0;
template<typename T>
unsigned int ValArrayOpsTest<T>::casePassed = 0;

template<typename T>
inline void ValArrayOpsTest<T>::ContructorTest() {

	//cout << __func__ << endl;
	//cout << "TestCase(" << caseCount << "\t): " << __FUNCTION__ << " \t"  ;
	cout << __FUNCTION__ << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	ValArrayOps<T> va;
	//cout << typeid(va).name() << "\t";
	assert( typeid(va) == typeid(ValArrayOps<T>));
	//assert( &vi != NULL);
	assert(va.Size() == 0);
	//vi.GetDetail("Hello");
	casePassed ++;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	size_t n = 13;
	ValArrayOps<T> va2(n);
	assert(typeid(va2) == typeid(ValArrayOps<T>));
	assert(va2.Size() == n) ;
	//va2.GetDetail("N Element, Initialized with default value");
	casePassed ++;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;

	class equal_n : public unary_function<bool, T>
	{
		T t;
	public:
		equal_n(T val):t(val) {}
		bool operator()(int n)
		{
			return  n == t;
		}
	};

	n = 15;
	int val = 14;
	equal_n eq_n(val);

	assert(typeid(T) == typeid(int));
	ValArrayOps<T> va3(val, n);
	assert(typeid(va3) == typeid(ValArrayOps<T>));
	assert(va3.Size() == n) ;
	assert(all_of(begin(va3.GetVt()), end(va3.GetVt()),  eq_n));
	//va3.GetDetail("N Element, Initialized with given value");
	casePassed ++;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	T * tp = new T(n);
	fill(tp, tp+n, val);
	ValArrayOps<T> va4(tp, n);
	assert(typeid(va4) == typeid(ValArrayOps<T>));
	assert(va4.Size() == n) ;
	//auto vtp = begin(va4.GetVt());
	//assert(all_of(begin(va4.GetVt()), end(va4.GetVt()),  eq_n));
	//va4.GetDetail("N Element, initialized to the values of the elements in the array pointed by p");
	//delete tp;
	casePassed ++;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	//T * tp = new T(n);
	//fill(tp, tp+n, val);
	ValArrayOps<T> va5(va3);
	//如果从va4处拷贝构造，调试时va5比较元素时发生异常退出信号
	//而且很奇怪，va4元素实际保存的地址在tp处。。。。
	assert(typeid(va5) == typeid(ValArrayOps<T>));
	assert(va5.Size() == n) ;
	//	auto vtp = begin(va5.GetVt());
	//	auto vtpend = end(va5.GetVt());
	//	int d = distance(vtp, vtpend);
	assert(all_of(begin(va5.GetVt()), end(va5.GetVt()),  eq_n));
	//va5.GetDetail("copy / move constructor");
	casePassed ++;
	cout << "Passed" << endl;

	cout << "TestCase(" << ++ caseCount << ")" ;
	//T * tp = new T(n);
	//fill(tp, tp+n, val);
	slice sl = slice(0, 4, 5);
	try
	{
		//valarray<T> vatmp = (va3.GetVt())[sl];
		valarray<T> vatmp = va2[sl];
		ValArrayOps<T> va6((va2.GetVt())[sl]);
		assert(typeid(va6) == typeid(ValArrayOps<T>));
		assert(va6.Size() ==  sl.size()) ;
		//auto vtp = begin(va4.GetVt());
		assert(equal(begin(va6.GetVt()), end(va6.GetVt()),  begin(vatmp)));
		//va6.GetDetail("copy / move constructor");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	//T * tp = new T(n);
	//fill(tp, tp+n, val);
	size_t start = 1;
	size_t lengths[] = {4, 5};
	size_t strides[] = {7, 2};
	gslice gsl = gslice(start, valarray<size_t>(lengths, 2), valarray<size_t>(strides, 2));
	try
	{
		//valarray<T> vatmp = (va3.GetVt())[sl];
		valarray<T> vatmp = va3[gsl];
		ValArrayOps<T> va6((va3.GetVt())[gsl]);
		assert(typeid(va6) == typeid(ValArrayOps<T>));
		assert(va6.Size() ==  vatmp.size()) ;
		//auto vtp = begin(va4.GetVt());
		assert(equal(begin(va6.GetVt()), end(va6.GetVt()),  begin(vatmp)));
		//va6.GetDetail("copy / move constructor");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<int> vi(sz);
		valarray<bool> mask(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
			mask[i] = ((i%2) == 1);
		}
		valarray<T> vatmp = vi[mask];
		ValArrayOps<T> va6(vi[mask]);
		assert(typeid(va6) == typeid(ValArrayOps<T>));
		assert(va6.Size() ==  vatmp.size()) ;
		//auto vtp = begin(va4.GetVt());
		assert(equal(begin(va6.GetVt()), end(va6.GetVt()),  begin(vatmp)));
		//va6.GetDetail("mask_array");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<int> vi(sz);
		valarray<size_t> ind(sz);
		for(size_t i = 1; i <= sz ; ++i)
		{
			vi[i - 1] = i;
			ind[i-1] = (i - 1);
		}
		ind[3] = ind[5] = 4;
		valarray<T> vatmp = vi[ind];
		ValArrayOps<T> va6(vi[ind]);
		assert(typeid(va6) == typeid(ValArrayOps<T>));
		assert(va6.Size() ==  vatmp.size()) ;
		//auto vtp = begin(va4.GetVt());
		assert(equal(begin(va6.GetVt()), end(va6.GetVt()),  begin(vatmp)));
		va6.GetDetail("indirect_array");

		valarray<size_t> ind2(3);
		ind2[0] = 3; ind2[1] = 6; ind2[2] = 9;
		va6[ind2] *= va6[ind2];
		//va6.GetDetail("indirect_array operation");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}
}

template<typename T>
inline void ValArrayOpsTest<T>::OperatorEqualTest() {
	cout << __FUNCTION__ << endl;
	cout << "TestCase(" << ++ caseCount << ")" ;
	assert(typeid(T) == typeid(int));
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 1; i <= sz ; ++i)
		{
			vi[i - 1] = i;
		}

		ValArrayOps<T> vao;
		vao = vi;
		assert(vao.Size() == vi.size());
		assert(equal(begin(vao.GetVt()), end(vao.GetVt()),  begin(vi)));
		//vao.GetDetail("Operator=: default Constructor, valarray<T>");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	assert(typeid(T) == typeid(int));
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 1; i <= sz ; ++i)
		{
			vi[i - 1] = i;
		}

		ValArrayOps<T> vao(1, 10);
		//vao.GetDetail("fill Constructor");
		vao = vi;
		assert(vao.Size() == vi.size());
		assert(equal(begin(vao.GetVt()), end(vao.GetVt()),  begin(vi)));
		//vao.GetDetail("Operator=: fill Constructor, valarray<T>");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 1; i <= sz ; ++i)
		{
			vi[i - 1] = i;
		}

		ValArrayOps<T> vao(1, 10);
		//vao.GetDetail("fill Constructor");
		static T val = 111;
		vao = val;

		struct{           // function object type:
			bool operator() (T& v) { return  v == val;}
		} equal_val ;
		//assert(vao.Size() == vi.size());
		assert(all_of(begin(vao.GetVt()), end(vao.GetVt()),  equal_val));
		//vao.GetDetail("Operator=: fill Constructor, T");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		slice sl = slice(0, sz + 1, 1);
		valarray<T> vi(sz);
		for(size_t i = 1; i <= sz ; ++i)
		{
			vi[i - 1] = i;
		}
		valarray<T> vatmp = vi[sl];
		ValArrayOps<T> vao(1, 10);
		//vao.GetDetail("fill Constructor");
		assert(typeid(vao) == typeid(ValArrayOps<T>));
		//将vi[sl]的元素依次复制到vao中，而vao也是从头开始接收复制过来的元素
		//复制时要求两边大小一致，否则会有遗漏。
		//valarray不会自动扩展？
		vao = vi[sl];
		for(size_t i = 0; i < vatmp.size(); ++i)
		{
			//cout << vatmp[i] << "," ;
		}
		//cout << endl;
		//assert(vao.Size() ==  vatmp.size()) ;
		assert(equal(begin(vao.GetVt()), end(vao.GetVt()),  begin(vatmp)));
		//vao.GetDetail("Operator=: fill Constructor, slice");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		size_t start = 0;
		//Assigns to each element the value of the corresponding element in sub (sizes shall match)
		size_t lengths[] = {2, 5};
		size_t strides[] = {5, 1};
		gslice sl = gslice(start, valarray<size_t>(lengths, 2), valarray<size_t>(strides, 2));

		valarray<T> vi(sz);
		for(size_t i = 1; i <= sz ; ++i)
		{
			vi[i - 1] = i;
		}
		valarray<T> vatmp = vi[sl];
		ValArrayOps<T> vao(1, 10);
		//vao.GetDetail("fill Constructor");
		assert(typeid(vao) == typeid(ValArrayOps<T>));
		for(size_t i = 0; i < vatmp.size(); ++i)
		{
			//cout << vatmp[i] << "," ;
		}
		//cout << endl;

		//sizes shall match
		//C++参考中专门加了这一句
		vao = vi[sl];

		assert(vao.Size() ==  vatmp.size()) ;
		assert(equal(begin(vao.GetVt()), end(vao.GetVt()),  begin(vatmp)));
		//vao.GetDetail("Operator=: fill Constructor, gslice");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 20;

		valarray<T> vi(sz);
		for(size_t i = 1; i <= sz ; ++i)
		{
			vi[i - 1] = i;
		}

		valarray<bool> mask(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			mask[i] = ((i%2) == 1);
		}

		valarray<T> vatmp = vi[mask];
		ValArrayOps<T> vao(1, 10);
		//vao.GetDetail("fill Constructor");
		assert(typeid(vao) == typeid(ValArrayOps<T>));
		for(size_t i = 0; i < vatmp.size(); ++i)
		{
			//cout << vatmp[i] << "," ;
		}
		//cout << endl;

		//sizes shall match
		//C++参考中专门加了这一句
		vao = vi[mask];

		assert(vao.Size() ==  vatmp.size()) ;
		assert(equal(begin(vao.GetVt()), end(vao.GetVt()),  begin(vatmp)));
		//vao.GetDetail("Operator=: fill Constructor, mask_array");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 20;

		valarray<T> vi(sz);
		for(size_t i = 1; i <= sz ; ++i)
		{
			vi[i - 1] = i;
		}

		valarray<size_t> ind(sz/2);
		for(size_t i = 0; i < sz/2 ; ++i)
		{
			ind[i] = i * 2 + 1;
		}

		valarray<T> vatmp = vi[ind];
		ValArrayOps<T> vao(1, 10);
		//vao.GetDetail("fill Constructor");
		assert(typeid(vao) == typeid(ValArrayOps<T>));
		for(size_t i = 0; i < vatmp.size(); ++i)
		{
			//cout << vatmp[i] << "," ;
		}
		//cout << endl;

		//sizes shall match
		//C++参考中专门加了这一句
		vao = vi[ind];

		assert(vao.Size() ==  vatmp.size()) ;
		assert(equal(begin(vao.GetVt()), end(vao.GetVt()),  begin(vatmp)));
		//vao.GetDetail("Operator=: fill Constructor, indirect_array");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}
}

template<typename T>
inline void ValArrayOpsTest<T>::ExceptioinTest() {
	cout << __FUNCTION__ << endl;
	try
	{
		cout << "TestCase(" << ++ caseCount << ")" ;
		//throw out_of_range("Hello Exception");
		throw logic_error("Bad Alloc");
	}
	catch(out_of_range& oor)
	{
		cerr << oor.what() << endl;
	}
	catch(logic_error& le)
	{
		cerr << le.what() << endl;
		throw;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}
}

static sig_atomic_t signaled = 0;

static void my_handler (int param)
{
	signaled ++ ;
	cerr << "errno: " << errno << endl;
	cerr << "param: " << param << endl;
	perror("SIGINT");
	return;
}

template<typename T>
inline void ValArrayOpsTest<T>::SignalTest() {
	cout << __FUNCTION__ << endl;
	try
	{
		cout << "TestCase(" << ++ caseCount << ")" ;

		/*struct{           // function object type:
			void operator() (int param) { ++signaled;}
		} my_handler;*/

		map<size_t, string> msig;
		map<size_t, void(*)(int)> msig_hand;
		msig.insert(make_pair(SIGKILL, "SIGKILL"));
		msig.insert(make_pair(SIGABRT, "SIGABRT"));
		msig.insert(make_pair(SIGFPE, "SIGFPE"));
		msig.insert(make_pair(SIGILL, "SIGILL"));
		msig.insert(make_pair(SIGINT, "SIGINT"));
		msig.insert(make_pair(SIGSEGV, "SIGSEGV"));
		msig.insert(make_pair(SIGTERM, "SIGTERM"));

		void (*prev_handler)(int);

		for(auto i = msig.begin(); msig.begin() != msig.end() && i != msig.end(); ++i)
		{
			//Signal value
			i->first;
			//Signal name
			i->second;

			prev_handler = signal(i->first, my_handler);

			msig_hand.insert(make_pair(i->first, prev_handler));

			cout << setw(12) << setiosflags(ios::left) << i->second << " ";
			cout.flush();
			if(prev_handler == SIG_DFL)
			{
				cout << setw(20)<<"prev_hander: SIG_DFL(" ;
				//cout.setf(ios::hex | ios::showbase | ios::uppercase);
				//cout << hex << my_handler;
				//cout << my_handler;
				cout<<setw(16)/*<<setfill('0')*/<<setiosflags(ios::showbase | ios::right)<< (void*)my_handler;
				//cout.unsetf(ios::hex | ios::showbase | ios::uppercase);
				cout << ")" << endl;
			}
			else if(prev_handler == SIG_IGN)
			{
				cout << "prev_hander: SIG_IGN(0x" << hex << SIG_IGN << ")" << endl;
			}
			else if(prev_handler == SIG_ERR)
			{
				const string msg= "Register signal handler failed: " +  i->second;
				perror(msg.c_str());
			}
			else
			{
				cout << "prev_hander: Other(0x" << hex << prev_handler << ")" << endl;
			}
			//cout << "signaled: " << signaled << endl;
		}

		//if(i->first == SIGABRT)
		{
			//raise(i->first);
			abort();
		}
		//Restore old hanlder
		for(auto i = msig_hand.begin(); msig_hand.begin() != msig_hand.end() && i != msig_hand.end(); ++i)
		{
			signal(i->first, prev_handler);
		}

	}
	catch(out_of_range& oor)
	{
		cerr << oor.what() << endl;
	}
	catch(logic_error& le)
	{
		cerr << le.what() << endl;
		throw;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}
	//void (*signal(int sig, void (*func)(int)))(int);
	casePassed ++;
	cout << "Passed" << endl;
}

template<typename T>
inline void ValArrayOpsTest<T>::OperatorSquareBracketsTest() {
	cout << __FUNCTION__ << endl;
	cout << "TestCase(" << ++ caseCount << ")" ;
	assert(typeid(T) == typeid(int));
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}
		ValArrayOps<T> vao;
		vao = vi;
		assert(vao.Size() == vi.size());
		assert(equal(begin(vao.GetVt()), end(vao.GetVt()),  begin(vi)));
		for(size_t i = 0; i < sz; ++i)
		{
			assert(vao[i] == vi[i]);
		}

		assert(vao[1] == vi[1]);
		//vao.GetDetail("Operator[]: T, T&");

		const ValArrayOps<T> vaoc(vao);
		assert(vaoc[1] == vao[1]);
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}
		ValArrayOps<T> vao;
		vao = vi;
		slice sl = slice(0, sz/2, 2);

		valarray<T> vabase = vi[sl];

		valarray<T> va = vao[sl];

		assert(vabase.size() == sl.size());
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));

		//vao.GetDetail("Operator[]: slice");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}
		ValArrayOps<T> vao;
		vao = vi;

		size_t start = 0;
		size_t lengths[] = {2, 5};
		size_t strides[] = {4, 1};
		gslice sl = gslice(start, valarray<size_t>(lengths, 2), valarray<size_t>(strides, 2));


		valarray<T> vabase = vi[sl];

		valarray<T> va = vao[sl];

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		//for_each(begin(va), end(va), myobject );

		assert(vabase.size() == (sl.size())[0] * (sl.size())[1]);
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));

		//vao.GetDetail("Operator[]: gslice");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}
		ValArrayOps<T> vao;
		vao = vi;

		valarray<bool> sl(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			sl[i] = ((i%2) == 0);
		}

		valarray<T> vabase = vi[sl];

		valarray<T> va = vao[sl];

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		//for_each(begin(va), end(va), myobject );
		size_t  base_size = (size_t)(equal(begin(sl), end(sl), myobject));
		equal(begin(va), end(va),  begin(vabase));
		assert(vabase.size() == base_size);
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));

		//vao.GetDetail("Operator[]: mask_array");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}
		ValArrayOps<T> vao;
		vao = vi;

		valarray<size_t> sl(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			sl[i] = i;
		}
		sl = sl.cshift(sz - 1);

		valarray<T> vabase = vi[sl];

		valarray<T> va = vao[sl];

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		for_each(begin(va), end(va), myobject );


		assert(vabase.size() == sl.size());
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));

		vao.GetDetail("Operator[]: indirect_array");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}
}

//Func
template<typename T>
T func(T t) { return pow(t, 2); }

template<typename T>
inline void ValArrayOpsTest<T>::ApplyTest() {
	cout << __FUNCTION__ << endl;
	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}

//		struct {           // function object type:
//			T operator() (T &i) { return pow(i, 2);}
//		} func;

		//vi = vi.apply(func);

		ValArrayOps<T> vao;
		vao = vi;
		//cout << func(20) << endl;
/*		auto vatmp = vao.Apply(func);
		vao = vatmp;*/
		valarray<T> vabase = vi.apply(func);

		valarray<T> va = vao.Apply(func);

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		for_each(begin(va), end(va), myobject );

		assert(vabase.size() == sz);
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));

		//vao.GetDetail("Operator[]: indirect_array");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}
}

template<typename T>
inline void ValArrayOpsTest<T>::ShiftTest() {
	cout << __FUNCTION__ << endl;
	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}

		//vi = vi.apply(func);

		ValArrayOps<T> vao;
		vao = vi;
/*		auto vatmp = vao.Apply(func);
		vao = vatmp;*/
		valarray<T> vabase = vi.shift(0);

		valarray<T> va = vao.Shift(0);

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		for_each(begin(va), end(va), myobject );

		assert(vabase.size() == sz);
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));

		vao.GetDetail("Shift: 0");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}

		//vi = vi.apply(func);

		ValArrayOps<T> vao;
		vao = vi;
/*		auto vatmp = vao.Apply(func);
		vao = vatmp;*/
		valarray<T> vabase = vi.shift(1);

		valarray<T> va = vao.Shift(1);

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		for_each(begin(va), end(va), myobject );

		assert(vabase.size() == sz);
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));

		vao.GetDetail("Shift: 1");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}

		//vi = vi.apply(func);

		ValArrayOps<T> vao;
		vao = vi;
/*		auto vatmp = vao.Apply(func);
		vao = vatmp;*/
		valarray<T> vabase = vi.shift(-1);

		valarray<T> va = vao.Shift(-1);

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		for_each(begin(va), end(va), myobject );

		assert(vabase.size() == sz);
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));

		vao.GetDetail("Shift: -1");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}
}

template<typename T>
inline void ValArrayOpsTest<T>::ResizeTest() {
	cout << __FUNCTION__ << endl;
	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}

		ValArrayOps<T> vao;
		vao = vi;

		vi.resize(sz);
		valarray<T>& vabase = vi;

		vao.Resize(sz);
		valarray<T>& va = vao.GetVt();

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		for_each(begin(va), end(va), myobject );

		assert(vabase.size() == sz);
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));

		vao.GetDetail("Resize: same size");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		size_t new_sz = 8;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}

		ValArrayOps<T> vao;
		vao = vi;

		vi.resize(new_sz);
		valarray<T>& vabase = vi;

		vao.Resize(new_sz);
		valarray<T>& va = vao.GetVt();

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		for_each(begin(va), end(va), myobject );

		assert(vabase.size() == new_sz);
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));
		assert(distance(begin(va), end(va)) - new_sz == 0);

		vao.GetDetail("Resize: Shrink");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		size_t new_sz = 12;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}

		ValArrayOps<T> vao;
		vao = vi;

		vi.resize(new_sz);
		valarray<T>& vabase = vi;

		vao.Resize(new_sz);
		valarray<T>& va = vao.GetVt();

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		for_each(begin(va), end(va), myobject );

		assert(vabase.size() == new_sz);
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));
		assert(distance(begin(va), end(va)) - new_sz == 0);

		vao.GetDetail("Resize: Shrink");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
	try
	{
		size_t sz = 10;
		size_t new_sz = 0;
		valarray<T> vi(sz);
		for(size_t i = 0; i < sz ; ++i)
		{
			vi[i] = i;
		}

		ValArrayOps<T> vao;
		vao = vi;

		vi.resize(new_sz);
		valarray<T>& vabase = vi;

		vao.Resize(new_sz);
		valarray<T>& va = vao.GetVt();

		struct {           // function object type:
			void operator() (int i) {std::cout << ' ' << i;}
		} myobject;

		for_each(begin(va), end(va), myobject );

		assert(vabase.size() == new_sz);
		assert(vabase.size() == va.size());
		assert(equal(begin(va), end(va),  begin(vabase)));
		assert(distance(begin(va), end(va)) - new_sz == 0);

		vao.GetDetail("Resize: Shrink");
		casePassed ++;
		cout << "Passed" << endl;
	}
	catch(out_of_range& oor)
	{
		cerr << "out of range" << endl;
	}
	catch(...)
	{
		cout << "exception" << endl;
	}

	cout << "TestCase(" << ++ caseCount << ")" ;
		try
		{
			size_t sz = 10;
			size_t new_sz = 12;
			size_t new_val = 10;
			valarray<T> vi(sz);
			for(size_t i = 0; i < sz ; ++i)
			{
				vi[i] = i;
			}

			ValArrayOps<T> vao;
			vao = vi;

			vi.resize(new_sz, new_val);
			valarray<T>& vabase = vi;

			vao.Resize(new_sz, new_val);
			valarray<T>& va = vao.GetVt();

			struct {           // function object type:
				void operator() (int i) {std::cout << ' ' << i;}
			} myobject;

			for_each(begin(va), end(va), myobject );

			assert(vabase.size() == new_sz);
			assert(vabase.size() == va.size());
			assert(equal(begin(va), end(va),  begin(vabase)));
			assert(distance(begin(va), end(va)) - new_sz == 0);

			vao.GetDetail("Resize: Shrink, Default value");
			casePassed ++;
			cout << "Passed" << endl;
		}
		catch(out_of_range& oor)
		{
			cerr << "out of range" << endl;
		}
		catch(...)
		{
			cout << "exception" << endl;
		}
}

template<typename T>
inline void ValArrayOpsTest<T>::TestSuite() {
	//this->ContructorTest();
	//this->OperatorEqualTest();
	//this->ExceptioinTest();
	//this->SignalTest();
	this->OperatorSquareBracketsTest();
	//this->ApplyTest();
	//this->ShiftTest();
	//this->ResizeTest();
}

#endif /* VALARRAYOPSTEST_H_ */
