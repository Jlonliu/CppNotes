#pragma once
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include<iostream>
#include<string>
#include<valarray>
class Student :private std::string, private std::valarray<double>{
private:
	typedef std::valarray<double>ArrayDb;
	//û����ʾ���ƣ�ʹ����ʽ����
	std::ostream & arr_out(std::ostream & os)const;//˽�еĳɼ��������
public:
	Student() :std::string("Null Student"), ArrayDb() {}
	explicit Student(const std::string & s) :std::string(s), ArrayDb() {}
	explicit Student(int n) :std::string("Nully"), ArrayDb(n) {}//����n��Ԫ��
	Student(const std::string & s, const ArrayDb &a) :std::string(s), ArrayDb(a) {}
	Student(const char * str, const double * pd, int n) :std::string(str), ArrayDb(pd, n) {}//n��Ԫ�أ�ÿһ����*pd
	~Student() { std::cout << "Student��������������޲���.\n"; }
	double Average()const;//����ѧ��ƽ�����ĺ���
	const std::string & Name()const;
	double & operator[](int i);
	double operator[](int i)const;
	friend std::istream & operator>>(std::istream & is, Student & stu);
	friend std::istream & getline(std::istream & is, Student & stu);
	friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};
#endif // !STUDENTC_H_