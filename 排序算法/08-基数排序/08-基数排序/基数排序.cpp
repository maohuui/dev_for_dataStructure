#include <iostream>
using namespace std;

void  print_array(int array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}

// 多关键字排序，桶排序的一种
void radix_sort(int array[], int n)
{
	
	//找到最大的数
	int max_val = array[0];
	int base = 1;
	for (int i = 1; i < n; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}
	int* t = (int*)malloc(sizeof(int) * n); // 临时区域，存储排序后的数
	while (max_val / base > 0) //循环的次数，最大的位数
	{
		int bucket[10] = { 0 }; // 桶
		for (int i = 0; i < n; i++) // 桶里面的数字个数++
		{
			bucket[array[i] / base % 10] ++;
		}

		for (int i = 1; i < 10; i++) // 第n个数应该放在 桶里面数的累加的位置
		{
			bucket[i] += bucket[i - 1];
		}

		for (int i = n-1; i >= 0; i--) //  从后往前放
		{
			t[bucket[array[i] / base % 10] - 1] = array[i];
			bucket[array[i] / base % 10]--;
		}

		for (int i = 0; i < n; i++)
			array[i] = t[i];
		base = base * 10; 
	}
}


int main()
{
	int array[] = {412, 240, 115, 532, 305, 430, 124, 4123};
	int size = sizeof(array) / sizeof(int);

	print_array(array, size);
	radix_sort(array, size);
	print_array(array,size);

	return EXIT_SUCCESS;
}