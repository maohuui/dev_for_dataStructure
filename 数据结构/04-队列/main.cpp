#include <iostream>
#include "arrayqueue.hpp"
#include "linkedqueue.hpp"
using namespace std;

void test01()
{
	ArrayQueue<int> q1;
	cout << "是否为空：" << q1.empty() << endl;

	for (int i = 0; i < 10; i++)
		q1.push(i);

	cout << "插入";
	cout << "大小： " << q1.size() << " ;头部数据：" << q1.front() << " ;尾部数据：" << q1.back() << endl;
	q1.visit();

	q1.pop();
	cout << "pop：";
	cout << "大小： " << q1.size() << " ;头部数据：" << q1.front() << " ;尾部数据：" << q1.back() << endl;
	q1.visit();

	q1.clear();
	cout << "清空是否为空：" << q1.empty() << endl;
}

void test02()
{
	ArrayCircleQueue<int> q1;
	cout << "是否为空：" << q1.empty() << endl;

	for (int i = 0; i < 10; i++)
		q1.push(i);

	cout << "插入";
	cout << "大小： " << q1.size() << " ;头部数据：" << q1.front() << " ;尾部数据：" << q1.back() << endl;
	q1.visit();

	q1.pop();
	cout << "pop：";
	cout << "大小： " << q1.size() << " ;头部数据：" << q1.front() << " ;尾部数据：" << q1.back() << endl;
	q1.visit();

	q1.clear();
	cout << "清空是否为空：" << q1.empty() << endl;
}
void test03()
{
	ListQueue<int> q1;
	cout << "是否为空：" << q1.empty() << endl;

	for (int i = 0; i < 10; i++)
		q1.push(i);

	cout << "插入";
	cout << "大小： " << q1.size() << " ;头部数据：" << q1.front() << " ;尾部数据：" << q1.back() << endl;
	q1.visit();

	q1.pop();
	cout << "pop：";
	cout << "大小： " << q1.size() << " ;头部数据：" << q1.front() << " ;尾部数据：" << q1.back() << endl;
	q1.visit();

	q1.clear();
	cout << "清空是否为空：" << q1.empty() << endl;
}

void test04()
{
}

int main()
{
	cout << "====================非环形数组=================== " << endl;
	test01();

	cout << "====================环形数组=================== " << endl;
	test02();

	cout << "====================非环形链表=================== " << endl;
	test03();

	//cout << "====================环形链表=================== " << endl;
	//test04();

	return EXIT_SUCCESS;
}