#include<iostream>
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include<string>
using std::string;
class AcctABC {
private:
	std::string fullname;//姓名
	long acctnum;//账号
	double balance;//余额
protected:
	struct Formatting {
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string &Fullname() const { return fullname; }
	long Acctnum()const { return acctnum; }
	Formatting SetFormat()const;
	void Restore(Formatting &f)const;
public:
	AcctABC(const string & s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;//纯虚函数 
	virtual void ViewAcct()const = 0;//纯虚函数 (查看账户)
	double Balance()const { return balance; }
	virtual ~AcctABC() { std::cout << "我是AcctABC类的虚构函数,我删除了" << fullname << "。\n"; }
};
class Brass:public AcctABC {
public:
	Brass(const string & s = "Nullbody", long an = -1, double bal = 0.0) :AcctABC(s, an, bal) {}
	virtual void Withdraw(double amt);
	virtual void ViewAcct()const;//查看账户
	virtual ~Brass() { std::cout << "我是Brass类的虚构函数,我删除了" << AcctABC::Fullname() << "。\n"; }
	//void Deposit(double amt);//在ABC类里面
	//const std::string & showname() { return fullname; }
	//double Balance()const { return balance; }
};
class BrassPlus :public AcctABC {
private:
	double maxLoan;//透支上限
	double rate;//利率
	double owesbank;//透支总额
public:
	BrassPlus(const string & s = "Nullbody", long an = -1, double bal = 0.0, double mL = 500, double r = 0.1);
	BrassPlus(const Brass & ba, double mL = 500, double r = 0.1);
	virtual void Withdraw(double amt);
	virtual void ViewAcct()const;//查看账户
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesbank = 0; }
	virtual ~BrassPlus(){ std::cout << "我是BrassPlus类的虚构函数,我删除了" << AcctABC::Fullname() << "。\n"; }
};

#endif