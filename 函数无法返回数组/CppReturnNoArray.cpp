#include<iostream>

using namespace std;
//C++函数返回值无法直接返回数组，但是可以以指针形式返回数组
char* ReturnArrayFunction(void);
char* ReturnArrayFunction2(void);
int main(void) {
	char* pt = ReturnArrayFunction();//接受到了数组首地址指针
	char* pt2 = ReturnArrayFunction2();
	//char newdata[3] = { 'N','e','w' };
	for (int i = 0; i < 3; i++) {
		//打印出来的数据未必是"Ary"，
		//因为地址已经被释放，地址存储的数据可能被覆盖了
		cout << pt[i];
	}
	cout << '\n';

	for (int i = 0; i < 3; i++) {
		cout << pt2[i];
	}
	cout << '\n';
	delete[] pt2;
	cout << "pt2已经被释放\n";
	return 0;
}
char* ReturnArrayFunction(void) {
	char arrTest[3] = { 'A','r','y'};//数组存储在局部变量中，存在被清除的风险
									 //成功运行是侥幸，数据丢失是常态
	return arrTest;//返回数组首地址指针
}

char* ReturnArrayFunction2(void) {
	//new申请的内存空间，在delete之前是不会被释放的，子函数结束，不会被释放
	//即使主函数结束也不会被释放（内存泄漏）
	char* parr = new char[3];
	parr[0] = 'A';
	parr[1] = 'r';
	parr[2] = 'y';
	return parr;//返回数组首地址指针
}