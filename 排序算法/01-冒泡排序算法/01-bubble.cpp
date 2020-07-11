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
void bubble_sort(T *array, int size)
{
	for (int i = 0; i < size; i++ ) //有多什么个元素参与冒泡排序
	{
		for (int j = 0; j < i; j++)
		{
			if (array[j] > array[j+1])
				SWAP(array[j], array[j+1]);
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
	int array[] = {29,10,14,37,13};
	int size = sizeof(array) / sizeof(array[0]);

	cout << size << endl;

	cout << "==========排序前=============" << endl;
	print_array(array, size);

	bubble_sort(array, size);

	cout << "==========排序后=============" << endl;
	print_array(array, size);

	return 0;
}