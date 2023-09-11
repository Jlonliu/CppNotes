#pragma once
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include<iostream>
#include<string>
#include<valarray>
class Student :private std::string, private std::valarray<double>{
private:
	typedef std::valarray<double>ArrayDb;
	//没有显示名称，使用隐式的类
	std::ostream & arr_out(std::ostream & os)const;//私有的成绩输出函数
public:
	Student() :std::string("Null Student"), ArrayDb() {}
	explicit Student(const std::string & s) :std::string(s), ArrayDb() {}
	explicit Student(int n) :std::string("Nully"), ArrayDb(n) {}//设置n个元素
	Student(const std::string & s, const ArrayDb &a) :std::string(s), ArrayDb(a) {}
	Student(const char * str, const double * pd, int n) :std::string(str), ArrayDb(pd, n) {}//n个元素，每一个是*pd
	~Student() { std::cout << "Student类的析构函数，无操作.\n"; }
	double Average()const;//返回学生平均数的函数
	const std::string & Name()const;
	double & operator[](int i);
	double operator[](int i)const;
	friend std::istream & operator>>(std::istream & is, Student & stu);
	friend std::istream & getline(std::istream & is, Student & stu);
	friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};
#endif // !STUDENTC_H_