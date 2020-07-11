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
	for (int j = 1; j < size; j++) //δ�����
	{
		for (int i = j; i > 0; i--) //�������
		{
			if (array[i - 1] > array[i]) // �Ƚ� 
				SWAP(array[i - 1], array[i]);
			else // ֱ���ҵ���һ��С�ڴ����������Ϊֹ����Ϊǰ��Ķ�������ģ�����break
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

	cout << "==========����ǰ=============" << endl;
	print_array(array, size);

	insert_sort(array, size);

	cout << "==========�����=============" << endl;
	print_array(array, size);

	return 0;
}