#include<iostream>
#include"acctabc.h"
using namespace std;

//Abstract Base Class
AcctABC::AcctABC(const string & s, long an, double bal) {
	fullname = s;
	acctnum = an;
	balance = bal;
}
void AcctABC::Deposit(double amt) {
	if (amt < 0)
		cout << "Negative deposit not allowed; deposit is canselled.\n";
	else
		balance += amt;
}
void AcctABC::Withdraw(double amt) {//ȡ��
	balance -= amt;
}
AcctABC::Formatting AcctABC::SetFormat()const {
	//set up ###.## format
	Formatting f;
	f.flag= cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}
void AcctABC::Restore(Formatting &f)const {
	cout.setf(f.flag, std::ios_base::floatfield);
	cout.precision(f.pr);
}

//Brass methods
void Brass::Withdraw(double amt) {
	if (amt < 0)
		cout << "Withdrawal amount must be positive; " << "withdrawl canceled.\n";
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);
	else
		cout << "Withdrawal amount of $" << amt << " exceeds your balance.\nWithdrawal canceled.\n";
}
void Brass::ViewAcct()const {
	Formatting f = SetFormat();

	cout << "Brass Client: " << Fullname() << endl;
	cout << "Account Number: " << Acctnum() << endl;
	cout << "Balance: $" << Balance() << endl;
	Restore(f);
}

//Brassplus methods
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) :AcctABC(s, an, bal) {
	maxLoan = ml;
	owesbank = 0.0;
	rate = r;
}
BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : AcctABC(ba) {
	maxLoan = ml;
	owesbank = 0.0;
	rate = r;
}
void BrassPlus::ViewAcct()const {
	Formatting f = SetFormat();
	cout << "Brassplus Client: " << Fullname() << endl;
	cout << "Account Number: " << Acctnum() << endl;
	cout << "Balance: $" << Balance() << endl;

	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesbank << endl;
	cout.precision(3);
	cout << "Loan Rate: " << 100 * rate << "%\n";
	Restore(f);
}
void BrassPlus::Withdraw(double amt) {
	Formatting f = SetFormat();
	double bal = Balance();
	if (amt <= bal)
		AcctABC::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesbank) {
		double advance = amt - bal;
		owesbank += advance * (1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled.\n";
	Restore(f);
}