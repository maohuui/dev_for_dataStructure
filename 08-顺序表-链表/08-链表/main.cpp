#include <iostream>
using namespace std;
#include "singlelist.hpp"
#include "doublelist.hpp"
#include "circlelist.hpp"

template<class T>
ostream& operator<<(ostream& out, const LinearLisr<T>& list)
{
	list.output(out);
	return out;
}

template<class T>
void test(LinearLisr<T>& list)
{
	list.insert(0, 0);
	list.insert(0, 1);
	list.insert(0, 2);
	list.insert(0, 3);
	list.insert(0, 4);
	list.insert(0, 5);

	cout << "==============size: " << list.size() << endl;
	cout << list << endl;

	list.insert(5, 500);
	cout << "==============size: " << list.size() << endl;
	cout << list << endl;

	int index = list.indexof(500);
	cout << "==============index: " << index << endl;

	list.erase(5);
	cout << "==============size: " << list.size() << endl;
	cout << list << endl;
}

void test01()
{
	SingleList<int> sList;
	test(sList);
}

void test02()
{
	CircleList<int> cList;
	test(cList);
	cout << cList.isCircle() << endl;
}

void test03()
{
	DoubleList<int> dList;
	test(dList);
}

int main()
{
	cout << " ------------------------" << endl;
	test01();

	cout << " ------------------------" << endl;
	test02();

	cout << " ------------------------" << endl;
	test03();
	return EXIT_SUCCESS;
}