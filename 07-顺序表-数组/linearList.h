#ifndef _LINEARLISR_H_
#define _LINEARLISR_H_


#include <iostream>
using namespace std;

template <class T>
class LinearList
{
public:
	virtual ~LinearList() {};

	virtual bool empty() const = 0; //判断是否为空
	virtual int size() const = 0; //大小
	virtual T& get(int index)const = 0; //获取索引为index下的元素
	virtual void insert(int index, int value) = 0; // 在索引为index处插入value
	virtual void erase(int index) = 0; //删除索引为index的元素
	virtual int indexof(const T& elem)const = 0;//找出elem元素第一次出现的索引
	virtual void output(ostream& out)const = 0;
};
#endif // _LINEARLISR_H_