#pragma once
#include "queue.h"

// 数组队列---非环形队列
// 删除数据：队尾加1，造成空间浪费，
//素

template<class T>
class ArrayQueue : public Queue<T>
{
public:
	ArrayQueue(int capacity = 10);
	virtual ~ArrayQueue();

public:
	bool empty() const;
	int size() const;
	T& front();
	T& back();
	void pop();
	void push(const T& elem);

private:
	int m_capacity;
	int m_queueFront; // 队头
	int m_queueBack;  // 队尾
	T* p_queueData;
};

template<class T>
ArrayQueue::ArrayQueue(int capacity)
{
	m_capacity = capacity;
	m_queueFront = -1;
	m_queueBack = m_queueFront;
	p_queueData = NULL;
}

template<class T>
ArrayQueue::~ArrayQueue()
{
	if (p_queueData != NULL)
		delete[] p_queueData;

}

template<class T>
bool ArrayQueue::empty() const
{
	return (m_queueFront == m_queueBack);
}

template<class T>
int ArrayQueue::size() const
{
	return (m_queueBack - m_queueFront + 1);
}

template<class T>
T& ArrayQueue::front()
{
	if (m_queueFront == -1)
		exit(EXIT_FAILURE);
	return p_queueData[m_queueFront];
}

template<class T>
T& ArrayQueue::back()
{
	if (m_queueFront == -1)
		exit(EXIT_FAILURE);
	return p_queueData[m_queueBack];
}

template<class T>
void ArrayQueue::pop()
{
	if (m_queueFront == -1)
		exit(EXIT_FAILURE);
	m_queueFront = m_queueFront + 1;
}

template<class T>
void ArrayQueue::push(const T& elem)
{
	if (this->size() = m_capacity)
		exit(EXIT_FAILURE);
	m_queueBack++;
	p_queueData[m_queueBack] = elem;
}
