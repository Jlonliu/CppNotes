#include <iostream>
#include"queuetp.h"
#include<string>
//using namespace std;

using std::cout;
using std::cin;
using std::endl;

int main(void) {
	QueueTP<std::string>cs(5);
	std::string temp;
	while (!cs.isfull()) {
		cout << "Please enter your name. You will be served int the order of arrival.\n";
		cout << "Name: ";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	cout << "The queue is full. processing begins!\n";
	while (!cs.isempty()) {
		cs.dequeue(temp);
		cout << "Now processing " << temp << "....\n";
	}

	cout << "\nDone!\n";
	return 0;
}