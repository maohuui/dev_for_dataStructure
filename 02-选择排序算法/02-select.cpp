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
void select_sort(T* array, int size)
{
	int min = 0;
	for (int i = 0; i < size; i++) 
	{
		min = i; //假定第i个数最小
		for (int j = i+1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		SWAP(array[i], array[min]);
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

	select_sort(array, size);

	cout << "==========排序后=============" << endl;
	print_array(array, size);

	return 0;
}