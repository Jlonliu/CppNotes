#include<iostream>

using namespace std;

//测试const关键字在不同位置产生的不同作用
int main(void) {

	int iNum1 = 7;
	int iNum2 = 8;
	int iNum3 = 9;
	//置于首位
	const int* p1 = &iNum1;//p1指向了iNum1的地址
	//置于*前
	int const* p2 = &iNum2;//p2指向了iNum2的地址
	//置于*后
	int* const p3 = &iNum3;//p3指向了iNum3的地址

	//更改指针指向变量的数据
	*p1 = 1;//不可修改
	*p2 = 1;//不可修改
	*p3 = 1;//可修改

	//更改指针指向的变量
	p1 = &iNum2;//可修改
	p2 = &iNum3;//可修改
	p3 = &iNum1;//不可修改

	//结论：
	//const置于*前（const int*同int const* ），*p(被指向的变量)是常量，不可更改
	//const置于*后，p(指针)是常量，不可更改
	
	return 0;
}
