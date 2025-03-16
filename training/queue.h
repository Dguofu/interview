#pragma once
template <typename T>
class queue {
	int front=0;
	int rear=-1;
	T* key=nullptr;
	int capacity=0;
	int count=0;

public:

	 explicit queue(int capacity)
		: front(0), rear(-1)
	{
		 key = new T[capacity];
		 this->capacity = capacity;
		 count = 0;
	}
	 queue(){}
	 void push(const T& value) {
		 if (!full()) {
			 rear = (rear + 1) % capacity;
			 key[rear] = value;
			 count++;
		 }
	 }
	 void pop() {
		 if (!empty()) {
			 front = (front + 1) % capacity;
			 count--;
		 }
	 }
	 T& front() {
		 return key[front];
	 }
	 T& rear() {
		 return key[rear];
	 }
	 bool empty() {
		 return count == 0;
	 }
	 bool full() {
		return count == capacity;
	 }
	 int size() {
		 return count;
	 }
	 ~queue() {
		 delete[] key;
	 }

};