#pragma once//ֻ������һ��
#ifndef STACKP_H_
#define STACKP_H_
#include<iostream>
template<typename T>
class Stack {
private:
	enum { MAX = 10 };
	T items[MAX];
	int top;
public:
	Stack();// { top = 0; }
	bool isempty();
	bool isfull();
	bool push(const T & item);
	bool pop(T & item);
	~Stack() { std::cout << "Stack's,do nothing.\n"; }
};
template<typename T>
Stack<T>::Stack() { top = 0; }
template<typename T>
bool Stack<T>::isempty() { return top == 0; }
template<typename T>
bool Stack<T>::isfull() { return top == MAX; }
template<typename T>
bool Stack<T>::push(const T & item) {
	if (top < MAX) {
		items[top++] = item;
		return true;
	}
	else return false;
}
template<typename T>
bool Stack<T>::pop(T & item) {
	if (top > 0) {
		item = items[--top];
		return true;
	}
	else return false;
}
#endif