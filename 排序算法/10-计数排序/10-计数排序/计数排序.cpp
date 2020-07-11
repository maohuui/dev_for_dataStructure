#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void count_sort(int arr[], int n)
{
	int* countArray = (int*)calloc(10, sizeof(int));// 分配内存之后会初始化为0
	if (NULL == countArray)
		return;
	int* sortArray = (int*)malloc(n * sizeof(int));
	if (NULL == sortArray)
		return;

	for (int i = 0; i < n; i++)
	{
		countArray[arr[i]]++;
	}
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		int num = countArray[i];
		while (num--)
		{
			sortArray[j] = i;
			j++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = sortArray[i];
	}
	free(countArray);
	free(sortArray);
	countArray = NULL;
	sortArray = NULL;
}

int main()
{
	int arr[] = { 2,3,2,4,5,6,3,2,4,5,7,8,1,9,0};
	int size = sizeof(arr) / sizeof(int);

	printArray(arr, size);
	count_sort(arr, size);
	printArray(arr, size);

	return EXIT_SUCCESS;
}