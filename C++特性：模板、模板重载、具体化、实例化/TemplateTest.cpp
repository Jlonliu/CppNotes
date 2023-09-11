#include<iostream>
#include<vector>
#include<string>
using namespace std;

//函数模板
//函数调用优先级：非模板函数>具体化模板函数>常规模板

//建立一个模板，将类型名命名为Typename
template<class Typename>
//用模板类型名代替标准类型名
vector<double> ArrayToVector(Typename arr[], int size);//并非所有模板参数都要用模板类型，但不能有默认值
template<class Typename>//函数模板也可以重载
vector<vector<double>> ArrayToVector(Typename* arr[], int rows, int cols);//但必须要有不同的特征标
//显示具体化：当编译器遇到与函数调用匹配的具体化定义时，不再寻找模板
//疑问：那我直接定义具体的非模板函数不是更好，要什么显示具体化
//针对char的显式具体化
template<>vector<double> ArrayToVector(char arr[], int size);
//针对char的非模板函数
vector<double> ArrayToVector(char arr[], int size);
//针对char的显式实例化
template vector<double> ArrayToVector(char arr[], int size);
int main(void) {

	int iArr[3] = { 1,2,3 };//int数组
	char cArr[3] = { 'A','B','C' };//char数组
	double dArr[3] = { 3.14,2.78,1.41 };//double数组
	int* piArr[2] = { iArr,iArr };//int指针数组
	double* pdArr[2] = {dArr,dArr};//double指针数组

	vector<double> vec_int = ArrayToVector(iArr, 3);
	vector<double> vec_dou = ArrayToVector(dArr, 3);
	vector<double> vec_char = ArrayToVector(cArr, 3);//优先调用非模板型
	vector<vector<double>> mat_int = ArrayToVector(piArr, 2, 3);
	vector<vector<double>> mat_dou = ArrayToVector(pdArr, 2, 3);


	return 0;

}
template<class Typename>
vector<double> ArrayToVector(Typename arr[], int size) {
	cout << "调用了数组型参数模板函数\n";
	vector<double> vec(arr, arr + size);
	return vec;
}
template<class Typename>
vector<vector<double>> ArrayToVector(Typename* arr[], int rows, int cols) {
	cout << "调用了指针数组型参数模板函数\n";
	vector<vector<double>> mat(rows, vector<double>(cols));
	for (int i = 0; i < rows; i++) {//遍历数组内的每一个指针
		mat[i] = vector<double>(arr[i], arr[i] + cols);//将每个指针指向的数组赋值给矩阵的列
	}
	return mat;
}
template<>vector<double> ArrayToVector(char arr[], int size) {
	cout << "调用了具体化char型数组参数模板函数\n";
	vector<double> vec;
	return vec;
}

//实例化不允许再定义：实例化仅是将模板工作的隐式过程显示了出来
//template vector<double> ArrayToVector(char arr[], int size){
//	cout << "调用了实例化char型数组参数模板函数\n";
//	vector<double> vec;
//	return vec;
//}
// 
vector<double> ArrayToVector(char arr[], int size) {
	cout << "调用了非模板char数组参数函数\n";
	vector<double> vec;
	return vec;
}