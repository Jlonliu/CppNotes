#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cctype>
#include"stackp.h"
using namespace std;
int main(void) {
	{
		Stack<string>st;//create an empty stack for string
		char ch;
		string po;
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
		while (cin >> ch && toupper(ch) != 'Q') {
			while (cin.get() != '\n')
				continue;
			if (!isalpha(ch)) {
				cout << '\a';
				continue;
			}
			switch (ch) {
			case'A':
			case'a':cout << "Enter a PO number to add: ";
				cin >> po; getchar();
				if (st.isfull())
					cout << "Stack already full\n";
				else
					st.push(po);
				break;
			case'P':
			case'p':if (st.isempty())
				cout << "Stack already empty\n";
					else {
						st.pop(po);
						cout << "PO #" << po << " popped\n";
						break;
					}
			}
			cout << "Please enter A to add a purchase order,\n"
				<< "P to process a PO, or Q to quit.\n";
		}
		cout << "Bye!\n";
	}
	getchar(); return 0;
}