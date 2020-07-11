#pragma once
#include "stack.h"

//Êý×éÕ»

template<class T>
class ArrayStak : public Stack<T>
{
public:
	ArrayStak(int capacity = 10);
	virtual ~ArrayStak();

public:
	virtual bool empty();
	virtual int size();
	virtual T& top();
	virtual void pop();
	virtual void push(const T& elem);

private:
	int m_capacity;
	int m_stackTop;
	T* p_stack;
};

template<class T>
inline ArrayStak<T>::ArrayStak(int capacity)
{
	if (capacity < 0)
	{
		exit(EXIT_FAILURE);
	}
	p_stack = new T[capacity];
	m_capacity = capacity;
	m_stackTop = -1;
}

template<class T>
inline ArrayStak<T>::~ArrayStak()
{
	if (p_stack != NULL)
		delete[] p_stack;
	p_stack = NULL;
}

template<class T>
inline bool ArrayStak<T>::empty()
{
	return (m_stackTop == -1);
}

template<class T>
inline int ArrayStak<T>::size()
{
	return m_stackTop + 1;
}

template<class T>
inline T& ArrayStak<T>::top()
{
	if (m_stackTop == -1)
		exit(EXIT_FAILURE);
	return p_stack[m_stackTop];
}

template<class T>
inline void ArrayStak<T>::pop()
{
	if (m_stackTop == -1)
		exit(EXIT_FAILURE);
	p_stack[m_stackTop] = -1;
	m_stackTop--;
}

template<class T>
inline void ArrayStak<T>::push(const T& elem)
{
	if (m_stackTop == m_capacity-1)
	{
		T* p_stackNew = new T[m_capacity * 2];
		for (int i = 0; i < m_capacity; i++)
		{
			p_stackNew[i] = p_stack[i];
		}
		delete[] p_stack;
		p_stack = p_stackNew;
		m_capacity = m_capacity * 2;
		cout << "stack is full, resize to " << m_capacity << endl;
	}
	m_stackTop++;
	p_stack[m_stackTop] = elem;
		
}
