#pragma once
#ifndef WORKER_H_
#define WORKER_H_
#include<string>
#include<iostream>
class Worker {
private:
	std::string fullname;
	long id;
protected:
	virtual void Data()const;
	virtual void Get();
public:
	Worker() :fullname("no one"), id(0L) {}
	Worker(const std::string & s, long n) :fullname(s), id(n) {}
	//Worker(const Waiter * wt) :fullname(wt->fullname), id(wt->id) {}
	//Worker(const Singer * wt) :fullname(wt->fullname), id(wt->id) {}
	virtual~Worker() = 0;//纯虚函数，基类的象征
	virtual void Set() = 0;
	virtual void Show()const = 0;
};
class Waiter :virtual public Worker {
private:
	int panache;
protected:
	void Data()const;
	void Get();
public:
	Waiter() :Worker(), panache(0) {}
	Waiter(const std::string & s, long n, int p = 0) :Worker(s, n), panache(p) {}
	Waiter(const Worker & wk, int p = 0) :Worker(wk), panache(p) {}
	//Waiter(const Waiter * wt) :panache(wt->panache) {}
	//Waiter(const Singer * wt, int p) :panache(p) {}
	~Waiter() { std::cout << "I of Waiter,do nothing.\n"; }
	void Set();
	void Show()const;
};
class Singer :virtual public Worker {
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };//为什么Vtypes要声明在protected里面
	void Data()const;
	void Get();
private:
	static const char *pv[Vtypes];//指向字符串常量的指针数组
	int voice;
public:
	Singer() :Worker(), voice(other) {}
	Singer(const std::string & s, long n, int v = other) :Worker(s, n), voice(v) {}
	Singer(const Worker & wk, int v = other) :Worker(wk), voice(v) {}
	//Singer(const Singer * wt) :voice(wt->voice) {}
	//Singer(const Waiter * wt, int v) :voice(v) {}
	~Singer() { std::cout << "I of Singer,do nothing.\n"; }
	void Set();
	void Show()const;
};
class SingingWaiter :public Singer, public Waiter {
protected:
	void Data()const;
	void Get();
public:
	SingingWaiter() {}
	SingingWaiter(const std::string & s, long n, int p = 0, int v = other) :
		Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
	SingingWaiter(const Waiter & wt, int v = other) :
		Worker(wt), Waiter(wt), Singer(wt, v) {}
	SingingWaiter(const Singer & wt, int p = 0) :
		Worker(wt), Waiter(wt, p), Singer(wt) {}
	~SingingWaiter() { std::cout << "I of SingingWaiter, do nothing.\n"; }
	void Set();
	void Show()const;
};
#endif