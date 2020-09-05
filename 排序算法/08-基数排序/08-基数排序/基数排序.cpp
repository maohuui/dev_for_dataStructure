#include <iostream>
using namespace std;

void  print_array(int array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}

// ��ؼ�������Ͱ�����һ��
void radix_sort(int array[], int n)
{
	
	//�ҵ�������
	int max_val = array[0];
	int base = 1;
	for (int i = 1; i < n; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}
	int* t = (int*)malloc(sizeof(int) * n); // ��ʱ���򣬴洢��������
	while (max_val / base > 0) //ѭ���Ĵ���������λ��
	{
		int bucket[10] = { 0 }; // Ͱ
		for (int i = 0; i < n; i++) // Ͱ��������ָ���++
		{
			bucket[array[i] / base % 10] ++;
		}

		for (int i = 1; i < 10; i++) // ��n����Ӧ�÷��� Ͱ���������ۼӵ�λ��
		{
			bucket[i] += bucket[i - 1];
		}

		for (int i = n-1; i >= 0; i--) //  �Ӻ���ǰ��
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