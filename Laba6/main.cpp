#include "UnidirQueue.h"
#include "CycQueue.h"
#include <iostream>
using namespace std;

template<typename T>
void testP(Queue<T> *test) {
	test->push("First");
	test->push("Second");
	test->push("Third");
	cout << test->pop() << " ";
	cout << test->pop() << " ";
	cout << test->pop() << " " << endl;
}

template<typename T>
void testR(Queue<T> &test) {
	test.push("First");
	test.push("Second");
	test.push("Third");
	cout << test.pop() << " ";
	cout << test.pop() << " ";
	cout << test.pop() << " " << endl;
}

int main() {
	UnidirQueue<string> Q1("3");
	Q1.push("5");
	Q1.push("1");
	CycQueue<string> Q2("88");
	Q2.push("77");
	Q2.push("66");
	testP(&Q1);
	testR(Q2);
	return 0;
}