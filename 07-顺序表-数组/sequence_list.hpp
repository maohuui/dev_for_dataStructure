#ifndef _SEQUENCE_LIST_H_
#define _SEQUENCE_LIST_H_

#include "linearList.h"
#include <stdexcept>
#include <string>
#include <ostream>
using namespace std;

template<class T>
class SequenceList : public LinearList<T>
{
public:
	SequenceList(int capacity=10);
	SequenceList(const SequenceList<T>& s);
	~SequenceList();

	int capacity()const { return m_iCapacity; }
	bool empty()const { return m_iSize == 0; }
	int size()const { return m_iSize; }

	T& get(int index)const;
	void insert(int index, int value);
	void erase(int index);
	int indexof(const T& elem)const;
	void output(ostream& out)const;

private:
	//void changeCapacity1D(int newCapacity)const; // 改变数组容量
	int checkIndex(int index);

private:
	T* m_pElems;
	int m_iCapacity;
	int m_iSize;
};

template<class T>
SequenceList<T>::SequenceList(int capacity)
{
	if (capacity < 1)
	{
		throw invalid_argument(" the capacity must be > 0");
	}
	m_iCapacity = 10;
	m_iSize = 0;
	m_pElems = new T[m_iCapacity];
}

template<class T>
SequenceList<T>::SequenceList(const SequenceList<T>& s)
{
	m_iCapacity = s.m_iCapacity;
	m_iSize = s.m_iSize;
	m_pElems = new T[m_iCapacity];
	for (int i = 0; i < m_iSize; i++)
	{
		m_pElems[i] = s.m_pElems[i];
	}
}

template<class T>
SequenceList<T>::~SequenceList()
{
	delete[] m_pElems;
}

template<class T>
int SequenceList<T>::checkIndex(int index)
{
	if (index < 0 || index > m_iSize)
	{
		throw invalid_argument(" the index must be > 0 and < size");
	}
	return 0;
}

template<class T>
T& SequenceList<T>::get(int index)const
{
	if (index < 0 || index >= m_iSize)
		throw invalid_argument(" the index must be > 0 and < size");

	return m_pElems[index];
}

template<class T>
int SequenceList<T>::indexof(const T& elem) const
{
	for (int i = 0; i < m_iSize; i++)
	{
		if (m_pElems[i] == elem)
		{
			return i;
		}
	}
	return -1;
}


template<class T>
void SequenceList<T>::insert(int index, int value)
{
	checkIndex(index);
	if (m_iSize == m_iCapacity)
	{
		//扩容
		T* temp = new T[m_iCapacity * 2];
		for (int i = 0; i < m_iSize; i++)
		{
			temp[i] = m_pElems[i];
		}
		delete[] m_pElems;
		m_pElems = temp;

		m_iCapacity = m_iCapacity * 2;
	}

	for (int i = m_iSize; i > index; i--)
	{
		m_pElems[i] = m_pElems[i - 1];
	}
	m_pElems[index] = value;
	m_iSize++;
}

template<class T>
void SequenceList<T>::erase(int index)
{
	checkIndex(index);
	for (int i = index; i < m_iSize; i++)
		m_pElems[i] = m_pElems[i + 1];
	m_iSize--;
}


template<class T>
void SequenceList<T>::output(ostream& out) const
{
	for (int i = 0; i < m_iSize; i++)
	{
		out << m_pElems[i] << " ";
	}
}

#endif // !_SEQUENCE_LIST_H_