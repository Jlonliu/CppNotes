#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
double hmean(double a, double b);
double gmean(double a, double b);
class Bad_hmean {
private:
	double v1;
	double v2;
public:
	Bad_hmean(double a = 0, double b = 0) :v1(a), v2(b) {}
	void mesg();
};
inline void Bad_hmean::mesg() {
	cout << "Hmean(" << v1 << ", " << v2 << "): invalid arguments: a = -b\n";
}
class Bad_gmean {
public:
	double v1;
	double v2;
	Bad_gmean(double a = 0, double b = 0) :v1(a), v2(b) {}
	const char * mesg();
};
inline const char*Bad_gmean::mesg() {
	return "gmean() arguments should be >= 0\n";
}
int main(void) {
	{
		double x, y, z;
		cout << "Enter two numbers: ";
		while (cin >> x >> y) {
			try {
				z = hmean(x, y);
				cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
				cout<<"Geometric mean of " << x << " and " << y << " is " << gmean(x,y) << endl;
				cout << "Enter next set of numbers<q to quit>: ";
			}
			catch (Bad_hmean &bg) {
				bg.mesg();
				cout << "try again.\n";
				continue;
			}
			catch (Bad_gmean & hg) {
				cout << hg.mesg();
				cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
				cout << "Sorry, you don't get to play any more.\n";
				break;
			}
		} 
		cout << "Bye.\n";
	}
	while (getchar() != '\n')
		continue;
	getchar(); return 0;
}
double hmean(double a, double b) {
	if (a == -b)
		throw Bad_hmean(a, b);
	return 2.0*a*b / (a + b);
}
double gmean(double a, double b) {
	if (a < 0 || b < 0)
		throw Bad_gmean(a, b);
	return sqrt(a*b);
}