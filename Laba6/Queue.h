template<typename T>
class Queue {
	virtual int GetSize() = 0;
	virtual void Push(const T& element) = 0;
	virtual T Pop() = 0;
	virtual T Peek() = 0;
};