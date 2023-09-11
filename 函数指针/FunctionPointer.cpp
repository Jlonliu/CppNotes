#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//三个将被调用的函数
double add(double x, double y);//两数相加
double multi(double x, double y);//两数相乘
double divi(double x, double y);//两数相除


//获取函数地址的方式：仅使用函数名(后面不跟括号和参数)
//函数指针的声明方式：写出要指向的函数，将函数名替换为"(*指针名)"
double (*Dtype_p_1)(double x, double y) = add;//指向函数的指针
double (*Darr_type_p[3])(double x, double y ) = { add,multi,divi };//存放函数指针的数组
//使用后typedef进行简化
//typedef double (*Dtype_p)(double x, double y);
//typedef double (*Darr_type_p[3])(double x, double y);


double calculate(double x, double y, double (*Dtype_p)(double x, double y));

int main() {
	double x = 0;
	double y = 0;
	for (int i = 0; i < 3; i++) {
		cout << "Please enter # " << i + 1 << " couple number: ";
		cin >> x;
		cin >> y;
		cout << calculate(x, y, *Darr_type_p[i]) << endl;
	}
	
	return 0;
} 
double add(double x, double y) {

	return x + y;
}
double multi(double x, double y) {
	return x * y;
}
double divi(double x, double y) {
	return x / y;
}
double calculate(double x, double y, double (*Dtype_p)(double x, double y)) {
	return (*Dtype_p)(x, y);
}