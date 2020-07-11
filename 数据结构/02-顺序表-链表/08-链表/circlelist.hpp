/*
用于循环链表
*/
#pragma once
#include "linearlist.h"

template<class T>
class CircleList : public LinearLisr<T>
{
public:
	CircleList();
	CircleList(const CircleList<T>& list);

	virtual ~CircleList();
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

public:
	bool isCircle()const;

private:
	int m_listSize;
	ChainNode<T>* p_firstNode;
};

template<class T>
CircleList<T>::CircleList()
{
	p_firstNode = new ChainNode<T>();
	p_firstNode->pNext = p_firstNode;
	m_listSize = 0;
}

template<class T>
CircleList<T>::CircleList(const CircleList<T>& list)
{
	m_listSize = list.m_listSize;
	if (m_listSize == 0)
	{
		p_firstNode = NULL;
		m_listSize = 0;
	}
	// 先复制头结点的元素
	ChainNode<T>* srcNode = list.p_firstNode;
	p_firstNode = new ChainNode<T>(srcNode->dataElem);
	srcNode = srcNode->pNext;

	// 头结点的位置不能动，新创建一个指针用来移动好创建新的结点
	ChainNode<T>* destNode = p_firstNode;

	while (srcNode->pNext != srcNode)
	{
		destNode->pNext = new ChainNode<T>(srcNode->dataElem);
		destNode->pNext = destNode->pNext;
		srcNode->pNext = srcNode->pNext;
	}
	destNode->pNext = p_firstNode;
}

template<class T>
CircleList<T>::~CircleList()
{
	// 先保存下一个结点的地址，然后在释放当前结点，防止脱节
	int i = m_listSize;
	while (i)
	{
		ChainNode<T>* tempNode = p_firstNode->pNext;
		delete p_firstNode;
		p_firstNode = tempNode;
		i--;
	}
	m_listSize = 0;
	delete p_firstNode;
	p_firstNode = NULL;
}

template<class T>
inline bool CircleList<T>::empty()
{
	return (m_listSize == 0);
}

template<class T>
inline int CircleList<T>::size()
{
	return m_listSize;
}

template<class T>
inline T& CircleList<T>::get(int index) const
{
	if (!checkIndex(index))
		exit(EXIT_FAILURE);

	ChainNode<T>* currentNode = p_firstNode;
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->pNext;
	}
	return currentNode->dataElem;
}

template<class T>
inline int CircleList<T>::indexof(const T& elem) const
{
	ChainNode<T>* currentNode = p_firstNode;
	int index = 0;
	while (currentNode->pNext != p_firstNode)
	{
		if (currentNode->dataElem == elem)
			return index;
		currentNode = currentNode->pNext;
		index++;
	}
	return -1;
}

template<class T>
inline void CircleList<T>::erase(int index)
{
	if (!checkIndex(index))
		return;

	ChainNode<T>* deleteNode;
	if (index == 0)
	{
		deleteNode = p_firstNode;
		p_firstNode = p_firstNode->pNext;
	}
	else
	{
		ChainNode<T>* tempNode = p_firstNode;
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
inline void CircleList<T>::insert(int index, const T& elem)
{
	if (!checkIndex(index))
		return;

	ChainNode<T>* tailNode = p_firstNode;
	ChainNode<T>* insertNode = new ChainNode<T>(elem);

	if (index == 0)
	{
		while (tailNode->pNext != p_firstNode)
		{
			tailNode = tailNode->pNext;
		}
		insertNode->pNext = p_firstNode;
		p_firstNode = insertNode;
		tailNode->pNext = p_firstNode;
	}
	else if (index == m_listSize)
	{
		while (tailNode->pNext != p_firstNode)
		{
			tailNode = tailNode->pNext;
		}
		tailNode->pNext = insertNode;
		insertNode->pNext = p_firstNode;
	}
	else
	{
		ChainNode<T>* tempNode = p_firstNode;
		for (int i = 0; i < index - 1; i++)
		{
			tempNode = tempNode->pNext;
		}
		insertNode->pNext = tempNode->pNext;
		tempNode->pNext = insertNode;		
	}

	m_listSize++;
}

template<class T>
inline void CircleList<T>::output(ostream& out) const
{
	ChainNode<T>* curentNode = p_firstNode;
	while (curentNode->pNext != p_firstNode)
	{
		cout << curentNode->dataElem << " ";
		curentNode = curentNode->pNext;
	}
}

template<class T>
inline bool CircleList<T>::isCircle() const
{
	ChainNode<T>* curentNode = p_firstNode;
	int size = m_listSize;
	while (--size)
	{
		curentNode = curentNode->pNext;
	}
	if (curentNode->pNext != p_firstNode)
		return true;

	return false;
}

template<class T>
inline bool CircleList<T>::checkIndex(int index) const
{
	if (index > m_listSize)
	{
		return false;
	}
	return true;
}
