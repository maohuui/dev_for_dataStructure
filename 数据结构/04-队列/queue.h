#pragma once

#include <iostream>
using namespace std;

template<class T>
class Queue
{
public:
	virtual ~Queue(){}

public:
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& front() = 0;
	virtual T& back() = 0;
	virtual void pop() = 0;
	virtual void push(const T& elem) = 0;
	virtual void clear() = 0;
	virtual void visit() = 0;
};