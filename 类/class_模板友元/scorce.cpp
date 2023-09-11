#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
//#include<cctype>
//#include"stackp.h"
//const int Num = 10;
using namespace std;

//------------------------------------------
/*
template<template <class T> class Thing>
class Crab {
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {};
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int & a, double &x) { return s1.pop(a) && s2.pop(x); }
};
*/
//------------------------------------------------------------
//非模板友元

template<class  T>
class HasFriend {
private:
	T item;
	static int ct;
public:
	HasFriend(const T & i) :item(i) {
		ct++;
	}
	HasFriend() { ct--; }
	friend void counts();
	friend void reports(HasFriend<T> &);

};
template<class T>
int HasFriend<T>::ct = 0;
void counts() {
	cout << "int count: " << HasFriend<int>::ct << ", ";
	cout << "double count: " << HasFriend<float>::ct << endl;
}
void reports(HasFriend<int> & hf) {
	cout << "HasFriend<int>: " << hf.item << endl;
}
void reports(HasFriend<double> & hf) {
	cout << "HasFriend<double>: " << hf.item << endl;
}
//---------------------------------------------------------
//约束模板友元

template<class T>void counts();
template<class F>void report(F &);
template<class A>
class HasFriendT {
private:
	A item;
	static int ct;
public:
	HasFriendT(const A & i) :item(i) { ct++; }
	~HasFriendT() { ct--; }
	friend void counts<A>();
	template<class F>
	friend void report<HasFriendT<A>>(F &);
};
template<class T>
int HasFriendT<T>::ct = 0;
template<class T>
void counts() {
	cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
	cout << "Template counts(): " << HasFriendT<T>::ct << endl;
}
template<class F>
void report(F & hf) {
	cout << hf.item << endl;
}

//------------------------------------------------------------
//非约束模板友元
template<class T>
class ManyFriend {
private:
	T item;
public:
	ManyFriend(const T & i) :item(i) {}
	template<class C,class D>
	friend void show2(C&, D&);
};
template<class C, class D>
void show2(C&c, D&d) {
	cout << c.item << ", " << d.item << endl;
}
//-----------------------------------------------------
int main(void) {
	{
		ManyFriend<int> hfi1(10);
		ManyFriend<int> hfi2(20);
		ManyFriend<double> hfdb(10.5);
		cout << "hfi1,hfi2: ";
		show2(hfi1, hfi2);
		cout << "hfi2,hfdb: ";
		show2(hfi2, hfdb);
	}
	getchar(); return 0;
}