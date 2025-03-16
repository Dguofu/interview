#pragma once

class list {
private:
	struct Node
	{
		int value;
		Node* next;
		Node(int vlue) {
			value = vlue;
			next = nullptr;

		}
		Node() {
			value = -1;
			next = nullptr;

		}
	};
	Node* head;
	Node* tail;
	int length;
	Node* get_pre(int index) {
		if (index >= 0 && index < length) {
			Node* pre = head;
			int s = 0;
			Node* p = pre->next;
			while (p&&s != index) {
				pre = p;
				p = p->next;
				s++;
			}
			return pre;

		}

		return nullptr;
	}
	
public:
	
	explicit list() : head(new Node()), tail(head), length(0) {}
	void add_end(int value) {
		tail->next=new Node(value);
		tail = tail->next;
		length++;
	}
	void add_front(int value) {
		Node* p = new Node(value);
		p->next = head->next;
		head->next = p;
		if (tail == head) {
			tail =p;
		}
		length++;
	}
	void add_index(int index,int value) {
		if (index <= 0) {
			add_front(value);
		}
		else if (index >= length) {
			add_end(value);
		}
		else {
			Node* tmp = new Node(value);
			Node* pre = get_pre(index);
			tmp->next = pre->next;
			pre->next = tmp;
			length++;
		}
		

	}
	void dele(int index) {
		if (index<0 || index>length) {
			return;
		}
		Node* pre = get_pre(index);
		Node* tmp = pre->next;
		pre->next = tmp->next;
		delete tmp;
		length--;

	}
	int get_index(int index) {
		if (index<0 || index>length) { 
			return -1;
		}
		Node * p= head->next;
		int current_index = 0;
		while (current_index != index) {
			current_index++;
			p = p->next;
		}
		return p->value;


	}
	~list() {
		Node* current = head;
		while (current != nullptr) {
			Node* tmp = current;
			current = current->next;
			delete tmp;
		}
	}


	int get_length() const {
		return length;
	}
	void reverse() {
		
		Node* in = head->next;
		head->next = nullptr;
		while (in)
		{	
			Node* tmp = in->next;
			tmp->next = head->next;
			head->next = tmp;
			tmp = in;
		}
	}
	//翻转可以不使用头插法 也可以进行新链表的合并

};
