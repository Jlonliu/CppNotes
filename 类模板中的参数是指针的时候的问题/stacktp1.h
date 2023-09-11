#pragma once
#pragma once
#ifndef STACKTP1_H_
#define STACKTP1_H_

template<class Type>
class Stack {
private:
	enum { SIZE = 10 };
	int stacksize;
	Type* items;
	int top;
public:
	explicit Stack(int ss = SIZE);
	Stack(const Stack& st);
	~Stack() { delete[]items; }
	bool isempty();
	bool isfull();
	bool push(const Type& item);
	bool pop(Type& item);
	Stack& operator=(const Stack& st);
};


template<class Type>
Stack<Type>::Stack(int ss):stacksize(ss),top(0) {
	items = new Type[stacksize];
}

template<class Type>
Stack<Type>::Stack(const Stack& st) {
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}

template<class Type>
bool Stack<Type>::isempty() {
	return top == 0;
}

template<class Type>
bool Stack<Type>::isfull() {
	return top == SIZE;
}

template<class Type>
bool Stack<Type>::push(const Type& item) {
	if (top < SIZE) {
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template<class Type>
bool Stack<Type>::pop(Type& item) {
	if (top > 0) {
		item = items[--top];
		return true;
	}
	else
		return false;
}

template<class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& st) {
	if (this == &st)
		return *this;
	delete[] items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	//const char ** items=new const char*[stacksize]
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}

#endif