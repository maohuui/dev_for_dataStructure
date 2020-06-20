//#ifndef _TEST_ITERATOR_H_
//#define _TEST_ITERATOR_H_
//
//template<class T>
//class MyIterator
//{
//public:
//	MyIterator();
//	~MyIterator();
//
//	typedef bidirectional_iterator_tag iterator_categoty;
//	typedef T value_type;
//
//	typedef ptrdiff_t difference_type;
//	typedef T* pointer;
//	typedef T& reference;
//
//	MyIterator(T* thePosition = 0) { position = thePosition };
//	T* operator* ()const { return *position; }
//	T* operator-> ()const { return &*position; }
//
//	MyIterator& operator++ () { ++position; return *this; }
//	MyIterator operator++ (int) { MyIterator old = *this; ++position; return old; }
//
//	MyIterator& operator-- () { --position; return *this; }
//	MyIterator operator-- (int) { MyIterator old = *this; --position; return old; }
//
//	bool operator != (const MyIterator right)const { return position != right.position; }
//	bool operator == (const MyIterator right)const { return position == right.position; }
//
//
//protected:
//	T* position;
//};
//
//template<class T>
//MyIterator::MyIterator()
//{
//}
//
//template<class T>
//MyIterator::~MyIterator()
//{
//}
//
//MyIterator begin()
//{
//	return MyIterator(element);
//}
//
//MyIterator end()
//{
//	return MyIterator(element+listsize);
//}
//
//#endif // !_TEST_ITERATOR_H_
