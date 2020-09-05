#pragma once
#include "queue.h"

// �������---�ǻ��ζ���
// ɾ�����ݣ���ͷ��1����ɿռ��˷ѣ�
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
	int m_capacity;   // ����
	int m_queueFront; // ��ͷ
	int m_queueBack;  // ��β
	int m_queueSize;  // ���д�С
;	T* p_queueData;   // ��ȡ����
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
	int m_queueFront; // ��ͷ
	int m_queueBack;  // ��β
	int m_queueSize;
	T* p_queueData;
};

// ====================== �ǻ���
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
	
	//1. ��ͷָ����ǰ�ƶ�
	m_queueFront = m_queueFront + 1;

	//2. �����������ǰ�ƶ�
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
// ========================���ζ���, ˳ʱ��
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
