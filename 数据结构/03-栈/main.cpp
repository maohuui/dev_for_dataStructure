#include "arraystack.hpp"
#include "linkedstack.hpp"
#include "stack.h"

template<class T>
void test(Stack<T>& s)
{
	s.push(10);
	s.push(9);
	s.push(8);
	s.push(7);
	s.push(6);
	s.push(5);

	cout << "size: " <<  s.size() << endl;
	cout << "top: " << s.top() << endl;
	s.pop();
	cout << "top: " << s.top() << endl;

	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	s.push(0);
	s.push(0);
	cout << "size: " << s.size() << endl;
}


void test01()
{
	ArrayStak<int> as;
	test(as);
}

void test02()
{
	LinkedStack<int> ls;
	test(ls);
}


int main()
{
	cout << "----------------------" << endl;
	test01();

	cout << "----------------------" << endl;
	test02();

	return EXIT_SUCCESS;
}