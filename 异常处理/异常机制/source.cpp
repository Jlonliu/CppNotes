#include <iostream>
//#include<string>
#include<cstdlib>
#include"exc_mean.h"
//using namespace std;

using std::cout;
using std::cin;
using std::endl;

double hmean(double a, double b);
double gmean(double a, double b);
int main(void) {
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y) {
		try {
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x,y) << endl;
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