#include<iostream>
//#include"new.h"
//#include<utility>
//#include<iterator>
//#include<list>
//#include<functional>
//#include<string>
#include<vector>
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

template<class T, class N> void compare(T num1, N num2) {
	cout << "standard function template " << endl;
		if (num1 > num2)
			cout << "num1: " << num1 << " > num2: " << num2 << endl;
		else
			cout << "num1: " << num1 << " <= num2: " << num2 << endl;
}

//����ģ������ػ�
template<class N> void compare(int num1, N num2) {
	cout << "partitial specialization " << endl;
	if (num1 > num2)
		cout << "num1: " << num1 << " > num2: " << num2 << endl;
	else
		cout << "num1: " << num1 << " <= num2: " << num2 << endl;
}

//ģ������ػ�Ϊָ��
template<class T, class N> void compare(T* num1, N* num2) {
	cout << "new partitial secialization " << endl;
	if (*num1 > *num2)
		cout << "num1: " << *num1 << " > num2: " << *num2 << endl;
	else
		cout << "num1: " << *num1 << " <= num2: " << *num2 << endl;
}

//��ģ������ػ�Ϊ��һ��ģ����
template<class T, class N> void compare(vector<T>& vecLeft, vector<N>& vecRight) {
	cout << "to vector partitial specialization " << endl;
	if (vecLeft.size() > vecRight.size())
		cout << "vecLeft.size(): " << vecLeft.size() << " > vecRight.size(): " << vecRight.size() << endl;
	else
		cout << "vecLeft.size(): " << vecLeft.size() << " < vecRight.size(): " << vecRight.size() << endl;
}

template<class C>
class A {
private:
	C data;
public:
	A(C d) :data(d) {}
	C dis() { return data; }
};

template<class T, class N> void compare(A<T> a1, A<N> a2) {
	cout << "LOOK HERE!!! IT'S TEMPLATE.";
	compare(a1.dis(), a2.dis());
}

int main(void) {
	compare<double, double>(3.14, 2.73);//���÷��ػ��汾
	compare<char>(3, '1');//�����ػ��汾template<class N> compare()
	int a = 3;
	char c = '1';
	compare(&a, &c);//�����ػ��汾template<class T, class N> void compare(T* num1, N* num2)
	vector<int> vec1{ 0 };
	vector<char> vec2{ '1','2' };
	compare<int, char>(vec1, vec2);//�����ػ��汾template<class T, class N> void compare(vector<T>& vecLeft, vector<N>& vecRight)
	A<int> di(7);
	A<char> dc('1');
	compare(di, dc);//�����ػ��汾template<class T, class N> void compare(A<T> a1, A<N> a2)
	cout << "\n�ݰ��ˣ����ţ�\n";
	return 0;
}
