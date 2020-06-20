/*
用于双链表
*/
#pragma once
#include "linearlist.h"

template<class T>
class DoubleList : public LinearLisr<T>
{
public:
	DoubleList();
	DoubleList(const DoubleList<T>& list);

	virtual ~DoubleList();
public:
	virtual bool empty();
	virtual int size();
	virtual T& get(int index)const;
	virtual int indexof(const T& elem)const;
	virtual void erase(int index);
	virtual void insert(int index, const T& elem);
	virtual void output(ostream& out)const;
protected:
	virtual bool checkIndex(int index)const;

private:
	int m_listSize;
	DChainNode<T>* p_firstNode;
};

template<class T>
DoubleList<T>::DoubleList()
{
	p_firstNode = new DChainNode<T>();
	p_firstNode->dataElem = -1;

	p_firstNode->pNext = NULL;
	p_firstNode->pPre = NULL;
	m_listSize = 0;
}

template<class T>
DoubleList<T>::DoubleList(const DoubleList<T>& list)
{
}

template<class T>
DoubleList<T>::~DoubleList()
{
	// 先保存下一个结点的地址，然后在释放当前结点，防止脱节
	while (p_firstNode != NULL)
	{
		DChainNode<T>* tempNode = p_firstNode->pNext;
		delete p_firstNode;
		p_firstNode = tempNode;
	}
	m_listSize = 0;
}

template<class T>
inline bool DoubleList<T>::empty()
{
	return (m_listSize == 0);
}

template<class T>
inline int DoubleList<T>::size()
{
	return m_listSize;
}

template<class T>
inline T& DoubleList<T>::get(int index) const
{
	if (!checkIndex(index))
		exit(EXIT_FAILURE);

	DChainNode<T>* currentNode = p_firstNode;
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->pNext;
	}
	return currentNode->dataElem;
}

template<class T>
inline int DoubleList<T>::indexof(const T& elem) const
{
	DChainNode<T>* currentNode = p_firstNode;
	int index = 0;
	while (currentNode != NULL)
	{
		if (currentNode->dataElem == elem)
			return index;
		currentNode = currentNode->pNext;
		index++;
	}
	return -1;
}

template<class T>
inline void DoubleList<T>::erase(int index)
{
	if (!checkIndex(index))
		return;

	DChainNode<T>* deleteNode;
	if (index == 0)
	{
		deleteNode = p_firstNode;
		p_firstNode = p_firstNode->pNext;
	}
	else
	{
		DChainNode<T>* tempNode = p_firstNode;
		for (int i = 0; i < index - 1; i++)
		{
			tempNode = tempNode->pNext;
		}
		deleteNode = tempNode->pNext;
		tempNode->pNext = tempNode->pNext->pNext;
	}
	m_listSize--;
	delete deleteNode;
	deleteNode = NULL;
}

template<class T>
inline void DoubleList<T>::insert(int index, const T& elem)
{
	if (!checkIndex(index))
		return;

	DChainNode<T>* insertNode = new DChainNode<T>();
	insertNode->dataElem = elem;
	if (index == 0)
	{
		insertNode->pNext = p_firstNode;
		p_firstNode->pPre = insertNode;
		insertNode->pPre = NULL;
		p_firstNode = insertNode;
	}
	else if (index == m_listSize)
	{
		DChainNode<T>* tempNode = p_firstNode;
		for (int i = 0; i < index - 1; i++)
		{
			tempNode = tempNode->pNext;
		}
		tempNode->pNext = insertNode;
		insertNode->pPre = tempNode;
		insertNode->pNext = NULL;
	}
	else
	{
		DChainNode<T>* tempNode = p_firstNode;
		for (int i = 0; i < index - 1; i++)
		{
			tempNode = tempNode->pNext;
		}
		insertNode->pNext = tempNode->pNext;
		tempNode->pNext->pPre = insertNode;
		tempNode->pNext = insertNode;		
		insertNode->pPre = tempNode;
		
	}
	m_listSize++;
}

template<class T>
inline void DoubleList<T>::output(ostream& out) const
{
	DChainNode<T>* curentNode = p_firstNode;
	while (curentNode != NULL)
	{
		cout << curentNode->dataElem << " ";
		curentNode = curentNode->pNext;
	}
}

template<class T>
inline bool DoubleList<T>::checkIndex(int index) const
{
	if (index > m_listSize)
	{
		return false;
	}
	return true;
}
