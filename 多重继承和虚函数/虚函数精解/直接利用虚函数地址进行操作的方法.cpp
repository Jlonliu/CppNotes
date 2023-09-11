#include <iostream>
using namespace std;
class Animal{
protected:
	int age_;
	Animal(int age) : age_(age) { }
public:
	virtual void print_age(void) = 0;
	virtual void print_kind() = 0;
	virtual void print_status() = 0;
};
class Dog : public Animal{
public:
	Dog() : Animal(2) { }
	~Dog() { }
	virtual void print_age(void) {
		cout << "Woof, my age = " << age_ << endl;
	}
	virtual void print_kind() {
		cout << "I'm a dog" << endl;
	}
	virtual void print_status() {
		cout << "I'm barking" << endl;
	}
};
class Cat : public Animal{
public:
	Cat() : Animal(1) { }
	~Cat() { }
	virtual void print_age(void) {
		cout << "Meow, my age = " << age_ << endl;
	}
	virtual void print_kind() {
		cout << "I'm a cat" << endl;
	}
	virtual void print_status() {
		cout << "I'm sleeping" << endl;
	}
};

void print_random_message(void* something) {
	cout << "I'm crazy" << endl;
}

int main(void){
	Cat kitty;
	Dog puppy;
	Animal* pa = &kitty;
	//获取Cat、Dog类的虚函数列表的地址
	//(intptr_t*)&kitty是指向虚函数列表地址的指针的地址
	//*(intptr_t*)(&kitty)是虚函数列表的地址
	//*(intotr_t*)*(intptr_t*)(&kitty)
        //是虚函数列表的第一个元素，即第一个虚函数的地址
	//(intptr_t * *)(&kitty)把(&kitty)强制转换成存放地址的地址
	//*((intptr_t * *)(&kitty))就是一个地址
        //                                ——指向虚函数列表的地址
	//下面这两条注销的操作是与未注销的操作等价的，即
	//*((intptr_t * *)(&kitty)) == (intptr_t*) * (intptr_t*)(&kitty)
	//intptr_t* cat_vptr = (intptr_t*) * (intptr_t*)(&kitty);
	//intptr_t* dog_vptr = (intptr_t*) * (intptr_t*)(&puppy);
        //这里是为了让cat_vptr指向虚函数表的地址
	intptr_t* cat_vptr = *((intptr_t * *)(&kitty));
	intptr_t* dog_vptr = *((intptr_t * *)(&puppy));
	
	intptr_t fake_vtable[] = {
	  dog_vptr[0],         // for dog::print_age->2
	  cat_vptr[1],         // for cat::print_kind->cat
	  (intptr_t)print_random_message
	};

	*((intptr_t * *)pa) = fake_vtable;
	pa->print_age();    // Woof, my age = 1，
                            //pa里面的age是猫的age，用的是狗的print_age();

	pa->print_kind();   // I'm a cat,用的是猫的print_kind();
	pa->print_status(); // I'm crazy
	cin.get();
	return 0;
}