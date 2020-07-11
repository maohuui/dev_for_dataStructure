#pragma once

#include "stack.h"

//µ•¡¥±Ì’ª
template<class T>
struct ChainNode
{
	T data;
	ChainNode* p_next;
};

template<class T>
class LinkedStack : public Stack<T>
{
public:
	LinkedStack();
	virtual ~LinkedStack();

public:
	virtual bool empty();
	virtual int size();
	virtual T& top();
	virtual void pop();
	virtual void push(const T& elem);

private:
	int m_size;
	ChainNode<T>* p_stackTop;
};

template<class T>
inline LinkedStack<T>::LinkedStack()
{
	p_stackTop = NULL;
	m_size = 0;
}

template<class T>
inline LinkedStack<T>::~LinkedStack()
{
	while (p_stackTop != NULL)
	{
		ChainNode<T>* nextNode = p_stackTop->p_next;
		delete p_stackTop;
		p_stackTop = nextNode;
	}
	p_stackTop = NULL;
}

template<class T>
inline bool LinkedStack<T>::empty()
{
	return (m_size == 0);
}

template<class T>
inline int LinkedStack<T>::size()
{
	return m_size;
}

template<class T>
inline T& LinkedStack<T>::top()
{
	if (m_size ==0)
		exit(EXIT_FAILURE);
	return p_stackTop->data;
}

template<class T>
inline void LinkedStack<T>::pop()
{
	if (m_size == 0)
		exit(EXIT_FAILURE);
	
	ChainNode<T>* nextNode = p_stackTop->p_next;
	delete p_stackTop;
	p_stackTop = nextNode;
	m_size--;
}

template<class T>
inline void LinkedStack<T>::push(const T& elem)
{
	ChainNode<T>* insertNode = new ChainNode<T>;
	insertNode->data = elem;

	insertNode->p_next = p_stackTop;
	p_stackTop = insertNode;
	m_size++;
}
