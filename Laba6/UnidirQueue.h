#include "Node.h"
#include "Queue.h"

#include <iostream>
using namespace std;

template<typename T>
class UnidirQueue : Queue<T> {
	Node<T>* front;
	Node<T>* rear;
	int size = 0;
public:
	UnidirQueue() {
		this->front = nullptr;
		this->rear = nullptr;
	}
	UnidirQueue(T value) {
		this->push(value);
		this->size = 1;
	}
	~UnidirQueue() {
		while (this->size > 1) {
			this->pop();
		}
		delete rear;
	}

	UnidirQueue(const UnidirQueue& other) {
		Node* temp = other.front;
		for (int i = 1; i <= other.size; i++) {
			this->push(temp->value);
			temp = temp->ptr;
		}
	}
	UnidirQueue(UnidirQueue&& other) {
		this->front = other.front;
		this->rear = other.rear;
		this->size = other.size;
		other.front = nullptr;
		other.rear = nullptr;
		other.size = 0;
	}
	push(const T value) {
		Node<T>* temp = new Node<T>(value);
		this->size++;
		if (rear == nullptr) {
			front = rear = temp;
			return;
		}
		this->rear->ptr = temp;
		this->rear = temp;
	}

	T pop() {
		if (front == nullptr)
			return NULL;
		this->size--;
		Node<T>* temp = front;
		this->front = front->ptr;
		if (front == nullptr)
			rear = nullptr;
		T res = temp->value;
		delete temp;
		return res;
	}

	UnidirQueue<T>& operator=(UnidirQueue&& other) {
		if (this == &other) {
			return *this;
		}

		this->rear = other.rear;
		this->front = other.front;
		other.rear = nullptr;
		other.front = nullptr;
		other.size = 0;
		return *this;
	}

	UnidirQueue<T> operator=(const UnidirQueue<T>& other) {
		Node<T>* temp = other.front;
		for (int i = 1; i <= other.size; i++) {
			this->push(temp->value);
			temp = temp->ptr;
		}
		return *this;
	}

	ostream& operator<<(ostream& out, const UnidirQueue<T>& queue) {
		Node<T>* temp = queue.front;
		out << temp->value;
		for (int i = 2; i <= queue.size; i++) {
			temp = temp->ptr;
			out << " " << temp->value;
		}
		return out;
	}

	T Peek() {
		return this->front->value;
	}

	int GetSize() {
		return this->size;
	}
};