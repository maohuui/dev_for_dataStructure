#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
/*
��� i �ĸ��ڵ���±�Ϊ (i - 1)/2
��� i �����ӵ��±�Ϊ i * 2 + 1
��� i ���Һ��ӵ��±�Ϊ i * 2 + 2
*/
//ά��������
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;
	if (lson < n && arr[largest] < arr[lson])
		largest = lson;
	if (rson < n && arr[largest] < arr[rson])
		largest = rson;
	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}
//������
/*
���ڵ� �� ���һ�������н��������Ԫ���Ѿ�������ģ�Ȼ����е����������
*/
void heap_sort(int arr[], int n)
{
	// ����
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	//����
	for (int i = 0; i < n; i++)
	{
		swap(arr[0], arr[n - i - 1]);
		heapify(arr, n-i-1, 0);
	}
}


int main()
{
	int a[] = {2,3,8,1,4,9,10,7,16,14};
	int size = sizeof(a) / sizeof(a[0]);

	printArray(a, size);
	heap_sort(a, size);
	printArray(a, size);
	return EXIT_SUCCESS;
}