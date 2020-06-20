#ifndef _LINEARLISR_H_
#define _LINEARLISR_H_


#include <iostream>
using namespace std;

template <class T>
class LinearList
{
public:
	virtual ~LinearList() {};

	virtual bool empty() const = 0; //�ж��Ƿ�Ϊ��
	virtual int size() const = 0; //��С
	virtual T& get(int index)const = 0; //��ȡ����Ϊindex�µ�Ԫ��
	virtual void insert(int index, int value) = 0; // ������Ϊindex������value
	virtual void erase(int index) = 0; //ɾ������Ϊindex��Ԫ��
	virtual int indexof(const T& elem)const = 0;//�ҳ�elemԪ�ص�һ�γ��ֵ�����
	virtual void output(ostream& out)const = 0;
};
#endif // _LINEARLISR_H_