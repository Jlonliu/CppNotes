#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"string1.h"
const int Arsize = 10;
const int Maxlen = 81;
int main() {
	
	using std::cout;
	using std::cin;
	using std::endl;
	String name;
	cout << "Hi, What's your name?\n";
	cin >> name;
	cout << name << ", Please enter up to " << Arsize<< " short saying<empty line to quit>:\n";
	String sayings[Arsize];
	char temp[Maxlen];
	int i;
	for (i = 0; i < 10; i++) {
		cout << i + 1 << ": ";
		cin.get(temp, Maxlen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0) {
		cout << "Here are your sayings:\n";
		for (int i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; i++) {
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}
		cout << "Shortest saying:\n" << sayings[shortest] << endl;
		cout << "First alphabetically:\n" << sayings[first] << endl;
		cout << "This program used " << String::HowMany() << "String objects. \nBye.\n";
	}
	else
		cout << "No input! Thank u\n";
	return 0;
}