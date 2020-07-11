#pragma once
#include <iostream>
using namespace std;

template<class T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual T& top() = 0;
	virtual void pop() = 0;
	virtual void push(const T& elem) = 0;
};