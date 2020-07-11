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

/*
确定h值：
	int h = 1;
	while (h < size / 2)
	{
		h = 2 * h + 1;
	}
h 的减小规则 
	h = h / 2;
*/

int calc_h(int size)
{
	int h = 1;
	while (h < (size / 2))
	{
		h = 2 * h + 1;
	}
	return h;
}

template<typename T>
void shell_sort(T* array, int size)
{
	int h = calc_h(size); //初始化增长量
	cout << "h: " << h << endl;
	
	while (h >= 1)
	{
		//找到待插入的元素 h
		for (int i = h; i < size;i++)
		{
			//把待插入的元素插入到有序序列中
			for (int j = i; j >= h; j-=h)
			{
				//待插入的元素是a[j] 与 a[j-h]
				if (array[j] < array[j-h]) // 比较 
					SWAP(array[j], array[j-h]);
				else // 直到找到第一个小于待插入的数据为止，因为前面的都是有序的，所以break
					break;
			}

		}
		//减小h的值
		h = h / 2;
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

	cout << "==========排序前=============" << endl;
	print_array(array, size);

	shell_sort(array, size);

	cout << "==========排序后=============" << endl;
	print_array(array, size);

	return 0;
}