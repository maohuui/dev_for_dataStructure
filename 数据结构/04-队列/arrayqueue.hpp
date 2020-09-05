#pragma once
#include "queue.h"

// 数组队列---非环形队列
// 删除数据：对头加1，造成空间浪费，
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
	void clear();
	void visit();

private:
	int m_capacity;   // 容量
	int m_queueFront; // 队头
	int m_queueBack;  // 队尾
	int m_queueSize;  // 队列大小
;	T* p_queueData;   // 存取数据
};

template<class T>
class ArrayCircleQueue : public Queue<T>
{
public:
	ArrayCircleQueue(int capacity = 10);
	virtual ~ArrayCircleQueue();

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
	int m_capacity;
	int m_queueFront; // 队头
	int m_queueBack;  // 队尾
	int m_queueSize;
	T* p_queueData;
};

// ====================== 非环形
template<class T>
ArrayQueue<T>::ArrayQueue(int capacity)
{
	m_capacity = capacity;
	m_queueFront = 0;
	m_queueBack = m_queueFront;
	m_queueSize = 0;
	p_queueData = new T[capacity];
}

template<class T>
ArrayQueue<T>::~ArrayQueue()
{
	if (p_queueData != NULL)
		delete[] p_queueData;
	p_queueData = NULL;
}

template<class T>
bool ArrayQueue<T>::empty() const
{
	return (m_queueSize == 0);
}

template<class T>
int ArrayQueue<T>::size() const
{
	return m_queueSize;
}

template<class T>
void ArrayQueue<T>::visit()
{
	for (int i = m_queueFront; i <= m_queueBack; i++)
		cout << " " << p_queueData[i] << " ; ";
	cout << endl;
}

template<class T>
T& ArrayQueue<T>::front()
{
	if (m_queueSize == 0)
		cout << "error: m_queueSize = 0 " << endl;
	else return p_queueData[m_queueFront];
}

template<class T>
T& ArrayQueue<T>::back()
{
	if (m_queueSize == 0)
		cout << "error: m_queueSize = 0 " << endl;
	else return p_queueData[m_queueBack];
}

template<class T>
void ArrayQueue<T>::pop()
{
	if (m_queueSize == 0)
	{
		cout << "error: m_queueSize = 0 " << endl;
		return;
	}
	
	//1. 对头指针往前移动
	m_queueFront = m_queueFront + 1;

	//2. 后面的数据往前移动
	/*
	
	for (int i = m_queueFront; i < m_queueBack; i++)
	{
		p_queueData[m_queueFront] = p_queueData[m_queueFront + 1];
	}
	m_queueBack--;
	*/
	m_queueSize--;
}

template<class T>
void ArrayQueue<T>::push(const T& elem)
{
		if (m_capacity == m_queueSize)
		{
			cout << "error: m_queueSize = m_capacity " << endl;
			return;
		}

	p_queueData[m_queueBack] = elem;
	m_queueBack++;
	if (m_queueBack == m_capacity)
		m_queueBack -= 1;

	m_queueSize++;
}

template<class T>
void ArrayQueue<T>::clear()
{
	m_queueFront = 0;
	m_queueBack = m_queueFront;
	m_queueSize = 0;
}
// ========================环形队列, 顺时针
template<class T>
ArrayCircleQueue<T>::ArrayCircleQueue(int capacity)
{
	m_capacity = capacity;
	m_queueFront = 0;
	m_queueBack = m_queueFront;
	m_queueSize = 0;
	p_queueData = new T[capacity];
}

template<class T>
ArrayCircleQueue<T>::~ArrayCircleQueue()
{
	if (p_queueData != NULL)
		delete[] p_queueData;
	p_queueData = NULL;
}

template<class T>
bool ArrayCircleQueue<T>::empty() const
{
	return (m_queueSize == 0);
}

template<class T>
void ArrayCircleQueue<T>::clear()
{
	m_queueFront = 0;
	m_queueBack = m_queueFront;
	m_queueSize = 0;	
}

template<class T>
void ArrayCircleQueue<T>::visit()
{
	for (int i = m_queueFront; i < (m_queueFront+m_queueSize); i++)
		cout << " " << p_queueData[i] << " ; ";
	cout << endl;
}

template<class T>
int ArrayCircleQueue<T>::size() const
{
	return m_queueSize;
}

template<class T>
T& ArrayCircleQueue<T>::front()
{
	if (m_queueSize == 0)
		cout << "error: m_queueSize = 0 " << endl;
	else return p_queueData[m_queueFront];
}

template<class T>
T& ArrayCircleQueue<T>::back()
{
	if (m_queueSize == 0)
		cout << "error: m_queueSize = 0 " << endl;
	if (m_queueBack == 0 )
		return p_queueData[m_capacity-1];
	else return p_queueData[m_queueBack-1];
}

template<class T>
void ArrayCircleQueue<T>::pop()
{
	if (m_queueSize == 0)
	{
		cout << "error: m_queueSize = 0 " << endl;
		return;
	}
	m_queueFront = (m_queueSize + 1) % m_capacity;
	m_queueSize--;
}

template<class T>
void ArrayCircleQueue<T>::push(const T& elem)
{
	if (m_queueSize == m_capacity)
	{
		cout << "error: m_queueSize = m_capacity " << endl;
		return;
	}
	p_queueData[m_queueBack] = elem;
	m_queueBack = (m_queueBack + 1) % m_capacity;
	m_queueSize++;	
}
