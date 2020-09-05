#pragma once

#include <iostream>
#include "queue.h"
using namespace std;

template<class T>
struct ListNode
{
	T val;
	ListNode<T>* next;
};

template<class T>
class ListQueue : public Queue<T>
{
public:
	ListQueue();
	virtual ~ListQueue();

public:
	bool empty() const;
	 int size() const;
	 T& front();
	 T& back();
	 void pop();
	 void push(const T& elem);
	 void clear();
	 void visit();

private:
	ListNode<T>* p_queueHead;
	ListNode<T>* p_queueTail;
	int m_size;
};

template<class T>
inline ListQueue<T>::ListQueue()
{
	p_queueHead = new ListNode<T>;
	p_queueTail = NULL;
	m_size = 0;
}

template<class T>
inline ListQueue<T>::~ListQueue()
{
	ListNode<T>* temp = p_queueHead->next;
	while (temp != p_queueTail)
	{
		ListNode<T>* deleteNode = temp;
		temp = deleteNode->next;
		delete deleteNode;
	}
	if(p_queueTail != NULL)
		delete p_queueTail;
	if(p_queueHead != NULL)
		delete p_queueHead;
	p_queueHead = NULL;
	p_queueTail = NULL;
	m_size = 0;
}

template<class T>
inline bool ListQueue<T>::empty() const
{
	return (m_size == 0);
}

template<class T>
inline int ListQueue<T>::size() const
{
	return m_size;
}

template<class T>
inline T& ListQueue<T>::front()
{
	if (m_size == 0)
		cout << "error: m_size == 0 " << endl;
	else return p_queueHead->next->val;
}

template<class T>
inline T& ListQueue<T>::back()
{
	if (m_size == 0)
		cout << "error: m_size == 0 " << endl;
	else return p_queueTail->val;
}

template<class T>
inline void ListQueue<T>::pop()
{
	if (m_size == 0)
	{
		cout << "error: m_size == 0 " << endl;
	}
	ListNode<T>* deleteNode = p_queueHead->next;
	p_queueHead->next = deleteNode->next;
	delete deleteNode;
	m_size--;
}

template<class T>
inline void ListQueue<T>::push(const T& elem)
{
	ListNode<T>* newNode = new ListNode<T>;
	newNode->val = elem;

	if (m_size == 0)
	{
		p_queueHead->next = newNode;
		p_queueTail = newNode; 
		p_queueTail->next = NULL;
	}
	else
	{
		p_queueTail->next = newNode;
		p_queueTail = p_queueTail->next;
	}
	m_size++;
}

template<class T>
inline void ListQueue<T>::clear()
{
	ListNode<T>* temp = p_queueHead->next;
	while (temp != p_queueTail)
	{
		ListNode<T>* deleteNode = temp;
		temp = deleteNode->next;
		delete deleteNode;
	}
	delete p_queueTail;
	p_queueTail = NULL;
	p_queueHead->next = p_queueTail;
	m_size = 0;
}

template<class T>
inline void ListQueue<T>::visit()
{
	ListNode<T>* temp = p_queueHead->next;
	while (temp != p_queueTail->next)
	{
		cout << " " << temp->val << ";";
		temp = temp->next;
	}
	cout << endl;
}
