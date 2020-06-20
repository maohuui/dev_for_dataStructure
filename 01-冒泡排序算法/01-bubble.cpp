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
	for (int i = 0; i < size; i++ ) //�ж�ʲô��Ԫ�ز���ð������
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

	cout << "==========����ǰ=============" << endl;
	print_array(array, size);

	bubble_sort(array, size);

	cout << "==========�����=============" << endl;
	print_array(array, size);

	return 0;
}