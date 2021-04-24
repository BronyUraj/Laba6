template<typename T>
class Queue {
public:
	virtual int GetSize() = 0;
	virtual void push(const T& value) = 0;
	virtual T pop() = 0;
	virtual T Peek() = 0;
};