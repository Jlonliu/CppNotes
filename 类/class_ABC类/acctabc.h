#include<iostream>
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include<string>
using std::string;
class AcctABC {
private:
	std::string fullname;//����
	long acctnum;//�˺�
	double balance;//���
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
	virtual void Withdraw(double amt) = 0;//���麯�� 
	virtual void ViewAcct()const = 0;//���麯�� (�鿴�˻�)
	double Balance()const { return balance; }
	virtual ~AcctABC() { std::cout << "����AcctABC����鹹����,��ɾ����" << fullname << "��\n"; }
};
class Brass:public AcctABC {
public:
	Brass(const string & s = "Nullbody", long an = -1, double bal = 0.0) :AcctABC(s, an, bal) {}
	virtual void Withdraw(double amt);
	virtual void ViewAcct()const;//�鿴�˻�
	virtual ~Brass() { std::cout << "����Brass����鹹����,��ɾ����" << AcctABC::Fullname() << "��\n"; }
	//void Deposit(double amt);//��ABC������
	//const std::string & showname() { return fullname; }
	//double Balance()const { return balance; }
};
class BrassPlus :public AcctABC {
private:
	double maxLoan;//͸֧����
	double rate;//����
	double owesbank;//͸֧�ܶ�
public:
	BrassPlus(const string & s = "Nullbody", long an = -1, double bal = 0.0, double mL = 500, double r = 0.1);
	BrassPlus(const Brass & ba, double mL = 500, double r = 0.1);
	virtual void Withdraw(double amt);
	virtual void ViewAcct()const;//�鿴�˻�
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesbank = 0; }
	virtual ~BrassPlus(){ std::cout << "����BrassPlus����鹹����,��ɾ����" << AcctABC::Fullname() << "��\n"; }
};

#endif