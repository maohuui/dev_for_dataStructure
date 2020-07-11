/*
用于单链表
*/
#pragma once
#include "linearlist.h"

template<class T>
class SingleList : public LinearLisr<T>
{
public:
	SingleList();
	SingleList(const SingleList<T>& list);

	virtual ~SingleList();
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
	ChainNode<T>* p_firstNode;
};

template<class T>
SingleList<T>::SingleList()
{
	p_firstNode = NULL;
	m_listSize = 0;
}

template<class T>
SingleList<T>::SingleList(const SingleList<T>& list)
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

	while (srcNode != NULL)
	{
		destNode->pNext = new ChainNode<T>(srcNode->dataElem);
		destNode->pNext = destNode->pNext;
		srcNode->pNext = srcNode->pNext;
	}
	destNode->pNext = NULL;
}

template<class T>
SingleList<T>::~SingleList()
{
	// 先保存下一个结点的地址，然后在释放当前结点，防止脱节
	while (p_firstNode != NULL)
	{
		ChainNode<T>* tempNode = p_firstNode->pNext;
		delete p_firstNode;
		p_firstNode = tempNode;
	}
	m_listSize = 0;
}

template<class T>
inline bool SingleList<T>::empty()
{
	return (m_listSize == 0);
}

template<class T>
inline int SingleList<T>::size()
{
	return m_listSize;
}

template<class T>
inline T& SingleList<T>::get(int index) const
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
inline int SingleList<T>::indexof(const T& elem) const
{
	ChainNode<T>* currentNode = p_firstNode;
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
inline void SingleList<T>::erase(int index)
{
	if (!checkIndex(index))
		return ;

	ChainNode<T>* deleteNode;
	if (index == 0)
	{
		deleteNode = p_firstNode;
		p_firstNode = p_firstNode->pNext;
	}
	else
	{
		ChainNode<T>* tempNode = p_firstNode;
		for (int i = 0; i < index-1; i++)
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
inline void SingleList<T>::insert(int index, const T& elem)
{
	if (!checkIndex(index))
		return ;

	ChainNode<T> *insertNode = new ChainNode<T>(elem);
	if (index == 0)
	{
		insertNode->pNext = p_firstNode;
		p_firstNode = insertNode;
	}
	else
	{
		ChainNode<T>* tempNode = p_firstNode;
		for (int i = 0; i < index - 1; i++)
		{
			tempNode = tempNode->pNext;
		}
		tempNode->pNext = new ChainNode<T>(elem, tempNode->pNext);
	}
	m_listSize++;
}

template<class T>
inline void SingleList<T>::output(ostream& out) const
{
	ChainNode<T>* curentNode = p_firstNode;

	while (curentNode != NULL)
	{
		
		cout << curentNode->dataElem << ";";
		curentNode = curentNode->pNext;
	}
}

template<class T>
inline bool SingleList<T>::checkIndex(int index) const
{
	if (index > m_listSize)
	{
		return false;
	}
	return true;
}
