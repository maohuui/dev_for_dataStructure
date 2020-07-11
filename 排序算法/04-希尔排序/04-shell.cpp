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

/*
ȷ��hֵ��
	int h = 1;
	while (h < size / 2)
	{
		h = 2 * h + 1;
	}
h �ļ�С���� 
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
	int h = calc_h(size); //��ʼ��������
	cout << "h: " << h << endl;
	
	while (h >= 1)
	{
		//�ҵ��������Ԫ�� h
		for (int i = h; i < size;i++)
		{
			//�Ѵ������Ԫ�ز��뵽����������
			for (int j = i; j >= h; j-=h)
			{
				//�������Ԫ����a[j] �� a[j-h]
				if (array[j] < array[j-h]) // �Ƚ� 
					SWAP(array[j], array[j-h]);
				else // ֱ���ҵ���һ��С�ڴ����������Ϊֹ����Ϊǰ��Ķ�������ģ�����break
					break;
			}

		}
		//��Сh��ֵ
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

	cout << "==========����ǰ=============" << endl;
	print_array(array, size);

	shell_sort(array, size);

	cout << "==========�����=============" << endl;
	print_array(array, size);

	return 0;
}