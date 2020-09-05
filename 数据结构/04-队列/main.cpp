#include <iostream>
#include "arrayqueue.hpp"
#include "linkedqueue.hpp"
using namespace std;

void test01()
{
	ArrayQueue<int> q1;
	cout << "�Ƿ�Ϊ�գ�" << q1.empty() << endl;

	for (int i = 0; i < 10; i++)
		q1.push(i);

	cout << "����";
	cout << "��С�� " << q1.size() << " ;ͷ�����ݣ�" << q1.front() << " ;β�����ݣ�" << q1.back() << endl;
	q1.visit();

	q1.pop();
	cout << "pop��";
	cout << "��С�� " << q1.size() << " ;ͷ�����ݣ�" << q1.front() << " ;β�����ݣ�" << q1.back() << endl;
	q1.visit();

	q1.clear();
	cout << "����Ƿ�Ϊ�գ�" << q1.empty() << endl;
}

void test02()
{
	ArrayCircleQueue<int> q1;
	cout << "�Ƿ�Ϊ�գ�" << q1.empty() << endl;

	for (int i = 0; i < 10; i++)
		q1.push(i);

	cout << "����";
	cout << "��С�� " << q1.size() << " ;ͷ�����ݣ�" << q1.front() << " ;β�����ݣ�" << q1.back() << endl;
	q1.visit();

	q1.pop();
	cout << "pop��";
	cout << "��С�� " << q1.size() << " ;ͷ�����ݣ�" << q1.front() << " ;β�����ݣ�" << q1.back() << endl;
	q1.visit();

	q1.clear();
	cout << "����Ƿ�Ϊ�գ�" << q1.empty() << endl;
}
void test03()
{
	ListQueue<int> q1;
	cout << "�Ƿ�Ϊ�գ�" << q1.empty() << endl;

	for (int i = 0; i < 10; i++)
		q1.push(i);

	cout << "����";
	cout << "��С�� " << q1.size() << " ;ͷ�����ݣ�" << q1.front() << " ;β�����ݣ�" << q1.back() << endl;
	q1.visit();

	q1.pop();
	cout << "pop��";
	cout << "��С�� " << q1.size() << " ;ͷ�����ݣ�" << q1.front() << " ;β�����ݣ�" << q1.back() << endl;
	q1.visit();

	q1.clear();
	cout << "����Ƿ�Ϊ�գ�" << q1.empty() << endl;
}

void test04()
{
}

int main()
{
	cout << "====================�ǻ�������=================== " << endl;
	test01();

	cout << "====================��������=================== " << endl;
	test02();

	cout << "====================�ǻ�������=================== " << endl;
	test03();

	//cout << "====================��������=================== " << endl;
	//test04();

	return EXIT_SUCCESS;
}