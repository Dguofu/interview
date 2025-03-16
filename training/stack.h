#pragma once
template<typename T>
class  stack 
{
private:

	int top=-1;
	T* key=nullptr;
	int capacity=0;
	int count=0;
public:
	 explicit stack(int capacity) {
		 key = new T[capacity];
		this->capacity = capacity;
		top = -1;
		count = 0;
	}
	stack(){
	}
	void push(const T& value) {
		if (!full) {
			T[++top] = value;
			count++;
		}

	}
	T& top() {
		return key[top];
	}
	void pop() {
		if (!empty()) {
			top--;
			count--;
		}
	}

	bool empty() {
		return top == -1;
	}
	bool full() {
		count == capacity;
	}
	int size() {
		return count;
	}
	~stack() {
		delete[] key;
	}

};


