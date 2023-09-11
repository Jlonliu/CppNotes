#include<iostream>

using namespace std;

class Scientist {
private:
	int a_;
public:
	Scientist(int a = 0) { a_ = a; }
	virtual void Show_a()const { cout << &a_ << endl; }//同
	virtual void Show_all()const { cout << a_ * a_ << endl; }//基
};
class Physicist:public Scientist{
private:
	int b_;
public:
	Physicist(int a = 0, int b = 0) :Scientist(a), b_(b) {}
	virtual void Show_a()const { Scientist::Show_a(); cout << ", " << b_ << endl; }//同
	virtual void Show_bll()const { cout << b_ * b_ << endl; }//派
};
//测试虚函数表地址函数
int main(void) {
	
	Scientist one(7);
	Physicist two(8, 9);
	//第一步，类对象地址
	cout << "Scientist objection adress: " << &one << endl;
	cout << "Physicist objection's adress: " << &two << endl;
	//第1.5步，指向虚函数表地址的地址
	cout << "Scientist vptr adress: " << (intptr_t*)& one << endl;
	cout << "Physicist vtpr adress: " << (intptr_t*)& two << endl;
	//第二步，虚函数表地址
	cout << "Scientist VFT adress: " << *(intptr_t*)&one << endl;
	cout << "Physicist VFT adress: " << *(intptr_t*)&two << endl;
	//第二步，第一个虚函数的地址，也就是说，虚函数表里面的第一个元素
	cout << "Scientist #1(show_a) VF adress: " << *(intptr_t*)*(intptr_t*)& one << endl;
	cout << "Physicist #1(show_a) VF adress: " << *(intptr_t*)*(intptr_t*)& two << endl;
	//第三步，第二个虚函数的地址
	cout << "Scientist #2(show_all) VF adress: " << *(intptr_t*) (* (intptr_t*)& one+1) << endl;
	cout << "Physicist #2(show_all) VF adress: " << *(intptr_t*) (* (intptr_t*)& two+1) << endl;
	//第4步，第3个虚函数的地址
	cout << "Scientist #3(show_bll) VF adress: " << *(intptr_t*)(*(intptr_t*)& one + 2) << endl;
	cout << "Physicist #3(show_bll) VF adress: " << *(intptr_t*)(*(intptr_t*)& two + 2) << endl;
	cin.get();
	return 0;
}