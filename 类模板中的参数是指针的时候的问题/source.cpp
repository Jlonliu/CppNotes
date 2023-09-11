#include <iostream>
#include<cstdlib>
#include<ctime>
#include"stacktp1.h"
const int Num = 10;
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main(void) {
	/*std::srand(std::time(0));
	cout << "Please enter stack size: ";
	int stacksize;
	std::cin >> stacksize;
	Stack<const char* >st(stacksize);
	const char* in[Num] = {
		"1: Hank Gilgamesh","2: Kiki Ishtar",
		"3: Betty Rocker","4: Ian Flagranti",
		"5: Wolfgang Kibble","6:Portia Koop",
		"7: Joy Almondo","8: Xaverie Paprik",
		"9: Juan Moore","10: Misha Mache"
	};
	const char* out[Num];
	int processed = 0;
	int nextin = 0;
	while (processed < Num) {
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++) {
		cout << out[i] << endl;
	}
	cout << "\n";
	for (int i = 0; i < Num; i++) {
		cout << in[i] << endl;
	}*/

	//测试关于指针的引用的问题
	/*int i = 7;
	int* pi = &i;
	int& k = i;
	int*& ppi = pi;
	cout << i << k << *pi << *ppi << endl;*/

	//关于析构函数析构指向指针的指针类型（int**）的时候的问题
	/*int i = 7;
	int* pi = &i;

	int** ppi = new int*[1];
	ppi[0] = pi;
	cout << *ppi[0] << *pi << i << endl;
	delete[]ppi;
	cout << i << endl;
	cout << *pi << endl;*/

	cout << "\nDone!\n";
	return 0;
}