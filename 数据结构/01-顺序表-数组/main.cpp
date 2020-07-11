#include "sequence_list.hpp"
#include <iostream>
using namespace std;

template<class T>
ostream& operator<<(ostream& out, SequenceList<T>& s)
{
	s.output(out);
	return out;
}

void test01()
{
	SequenceList<int> a;
	a.insert(0, 10);
	a.insert(0, 20);
	a.insert(0, 3);
	a.insert(0, 2);
	a.insert(0, 50);
	a.insert(0, 100);

	cout << a << endl;

	a.erase(5);
	cout << a << endl;

	cout << " capacity:  " << a.capacity() << endl;
	cout << " size:  " << a.size() << endl;

	cout << " a[4] :  " << a.get(4) << endl;
	cout << " find 20 the index:  " << a.indexof(20) << endl;
}

int main()
{
	test01();
	return EXIT_SUCCESS;
}