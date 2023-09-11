#include <iostream>
#include<string>
//#include<cstdlib>
#include<cmath>
#include"exc_mean.h"
//using namespace std;

using std::cout;
using std::cin;
using std::endl;
class Demo {
private:
	std::string word;
public:
	Demo(const std::string& str) {
		word = str;
		std::cout << "Demo " << word << " created\n";
	}
	~Demo() {
		std::cout << "Demo " << word << " destroyed\n";

	}
	void Show()const {
		std::cout << "Demo " << word << " lives!\n";
	}
};
double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);
int main(void) {
	double x, y, z;
	{
		Demo d1("found in block in main()");
		cout << "Enter two numbers: ";
		while (cin >> x >> y) {
			try {
				z = means(x, y);
				cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
				//cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
				cout << "Enter next set of numbers<q to quit>: ";
			}
			catch (bad_hmean& bh) {
				bh.mesg();
				cout << "Try again.\n";
				continue;
			}
			catch (bad_gmean& bg) {
				cout << bg.mesg();
				cout << "Values used: " << bg.v1 << ", " << bg.v2 << endl;
				cout << "Sorry, you don't get to play any more.\n";
				break;
			}
		}
		d1.Show();
	}
	cout << "\nDone!\n";
	return 0;
}
double hmean(double a, double b) {
	if (a == -b) {
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) {
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}
double means(double a, double b) {
	double am, hm, gm;
	Demo d2("found in means()");
	am = (a + b) / 2.0;
	try {
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch (bad_hmean& bg) {
		bg.mesg();
		std::cout << "Caught in means()\n";
		throw;
	}
	d2.Show();
	return (am + hm + gm) / 3.0;
}