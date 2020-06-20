#pragma once
#include <iostream>
using namespace std;


// 链表结点
template<class T>
struct DChainNode
{
	T dataElem;
	DChainNode<T>* pNext;
	DChainNode<T>* pPre;
};

// 链表结点
template<class T>
struct ChainNode
{
	T dataElem;
	ChainNode<T>* pNext;

	ChainNode() {}
	ChainNode(const T& elem) { dataElem = elem; }
	ChainNode(const T& elem, ChainNode<T>* next) {
		dataElem = elem; pNext = next;
	}
};

template<class T>
class LinearLisr
{
public:
	LinearLisr() {}
	virtual ~LinearLisr() {}

public:
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual T& get(int index)const = 0;
	virtual int indexof(const T& elem)const = 0;
	virtual void erase(int index) = 0;
	virtual void insert(int index, const T& elem) = 0;
	virtual void output(ostream& out)const = 0;
protected:
	virtual bool checkIndex(int index)const = 0;
};