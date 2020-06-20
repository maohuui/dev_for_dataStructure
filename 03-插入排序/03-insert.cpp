#include<iostream>
using namespace std;

template<typename T>
void SWAP(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
template<typename T>
void insert_sort(T* array, int size)
{
	for (int j = 1; j < size; j++) //未排序的
	{
		for (int i = j; i > 0; i--) //已排序的
		{
			if (array[i - 1] > array[i]) // 比较 
				SWAP(array[i - 1], array[i]);
			else // 直到找到第一个小于待插入的数据为止，因为前面的都是有序的，所以break
				break;
		}
	}
}

template<typename T>
void print_array(const T* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	int array[] = { 29,10,14,37,13 };
	int size = sizeof(array) / sizeof(array[0]);

	cout << size << endl;

	cout << "==========排序前=============" << endl;
	print_array(array, size);

	insert_sort(array, size);

	cout << "==========排序后=============" << endl;
	print_array(array, size);

	return 0;
}