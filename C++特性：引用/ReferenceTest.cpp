#include<iostream>

using namespace std;

//C++的新特性：引用
//引用相当于给另一个变量起了一个别名，引用和变量的地址和存储的数据都相同
//引用不同于指针的地方：引用在声明时必须将其初始化
//引用接近const指针，必须在创建时初始化，一旦与某个变量关联起来，就一直效忠于它。
int main(void) {

	int rats = 101;
	int& rodents = rats;//rodents是rats的引用

	//查看变量和引用的地址及其存储值
	cout << "rats address is    :" <<&rats<<"; its value is :" << rats << endl;
	cout << "rodents address is :" << &rodents << "; its value is :" << rodents << endl;
	cout << "-------------------------------------------" << endl;//分隔符
	int bunnies = 50;
	rodents = bunnies;//给别名赋值为50

	//再次查看变量和引用的地址及其存储值
	cout << "bunnies address is :" << &bunnies << "; its value is :" << bunnies << endl;
	cout << "rats address is    :" << &rats << "; its value is :" << rats << endl;
	cout << "rodents address is :" << &rodents << "; its value is :" << rodents << endl;
	//结果是:
	//rats address is    : 00000001000FF904; its value is : 101
	//rodents address is : 00000001000FF904; its value is : 101
	//---------------------------------------------------------
	//bunnies address is : 00000001000FF944; its value is : 50
	//rats address is    : 00000001000FF904; its value is : 50
	//rodents address is : 00000001000FF904; its value is : 50

	//给别名赋值同时改变了别名和被引用的变量
	//无法让别名重新引用另一个变量
	//引用的实质就是const指针
	//int &rodents = rats类似于int* cosnt rodents = &rats
	return 0;
}
