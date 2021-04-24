template<typename T>
struct Node {
	T value;
	Node<T>* ptr;
	Node<T>(T value);
	Node(const T value) {
		this->value = value;
		this->ptr = nullptr;
	};

};
