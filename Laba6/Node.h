template<typename T>
struct Node {
	T value;
	Node<T>* ptr;
	Node(const T value) {
		this->value = value;
		this->ptr = nullptr;
	};
};
