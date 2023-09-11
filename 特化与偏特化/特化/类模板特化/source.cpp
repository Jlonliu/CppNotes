#include<iostream>
//#include"new.h"
//#include<utility>
//#include<iterator>
//#include<list>
//#include<functional>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<map>
//#include<set>
//#include<cstdlib>
//#include<ctime>
//#include<typeinfo>
//#include<cmath>
//#include<new>
//#include<exception>
//#include<memory>
//#include<cstring>

using namespace std;

template<class T>class A {
private:
	T num;
public:
	A(T n) :num(n) {}
	void dis() { cout << "A'num: " << num << endl; }
	~A() {}
};

template<>class A<char*> {
private:
	char* str;
public:
	A(const char* c) {
		str = new char[strlen(c) + 1];
		for (unsigned int i = 0; i < strlen(c) + 1; i++)
			str[i] = c[i];
		
	}
	void dis() { cout << "A's name: " << str << endl; }
	~A() { delete[]str; }
};
int main(void) {
	A<int> a1(7);
	a1.dis();
	A<char*> a2("seven");
	a2.dis();
	cout << "\n°Ý°ÝÁË£¬ÄúÄÅ£¡\n";
	return 0;
}
