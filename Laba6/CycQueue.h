#include <iostream>
using namespace std;

template<typename T>
class CycQueue : public Queue<T> {
	Node<T>* front;
	Node<T>* rear;
	int size = 0;
public:
	template<typename T> friend ostream& operator<<(ostream& out, const CycQueue<T>& queue);
	CycQueue() {
		this->front = nullptr;
		this->rear = nullptr;
	}
	CycQueue(T value) {
		this->push(value);
		this->size = 1;
	}
	~CycQueue() {
		while (this->size > 1) {
			this->pop();
		}
		delete rear;
	}

	CycQueue(const CycQueue& other) {
		Node* temp = other.front;
		for (int i = 1; i <= other.size; i++) {
			this->push(temp->value);
			temp = temp->ptr;
		}
	}
	CycQueue(CycQueue&& other) {
		this->front = other.front;
		this->rear = other.rear;
		this->size = other.size;
		other.front = nullptr;
		other.rear = nullptr;
		other.size = 0;
	}
	void push(const T value) {
		Node<T>* temp = new Node<T>(value);
		this->size++;
		if (rear == nullptr) {
			front = rear = temp;
			return;
		}
		temp->ptr = this->front;
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

	CycQueue<T>& operator=(CycQueue<T>&& other) {
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

	CycQueue<T> operator=(const CycQueue<T>& other) {
		Node<T>* temp = other.front;
		for (int i = 1; i <= other.size; i++) {
			this->push(temp->value);
			temp = temp->ptr;
		}
		return *this;
	}

	T Peek() {
		return this->front->value;
	}

	int GetSize() {
		return this->size;
	}

};

template<typename T>
ostream& operator<<(ostream& out, const CycQueue<T>& queue) {
	Node<T>* temp = queue.front;
	out << temp->value;
	for (int i = 2; i <= queue.size; i++) {
		temp = temp->ptr;
		out << " " << temp->value;
	}
	return out;
}
