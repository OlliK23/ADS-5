// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template <typename T, int size>
class Stack {
private:
	T* arr = nullptr;
	int top;
public:
	Stack() : top(-1) {
		arr = new T[size];
	}
	T get() {
		return arr[top];
	}
	void pop() {
		if (top >= 0) {
			begin--;
		}
	}
	void push(T s) {
		if (top < size - 1) {
			arr[++top] = s;
		}

	}
	bool isEmpty() {
		if (top == -1) {
			return true;
		}
		return false;
	}
};
#endif  // INCLUDE_TSTACK_H_
