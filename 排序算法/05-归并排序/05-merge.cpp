#include<iostream>
using namespace std;

template<typename T>
void SWAP(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
//求n的阶乘
int factorial(int n)
{
	if (n == 1)
		return n;
	return n * factorial(n - 1);
}

//合并
template<typename T>
void merge(T* array, int lo, int mid, int hi)
{
	int* assist = new int[hi-lo+1];

	//定义三个位置指针，位置索引
	int i = lo;
	int j = mid+1
;
	int z = 0;

	//遍历，移动p1和p2 指针判断对应多余的值，找出较小的树，放到辅助数组对应的位置
	while (i <= mid && j <= hi)
	{
		//比较对应索引位置的值
		if (array[i] > array[j])
			assist[z++] = array[j++];
		else
			assist[z++] = array[i++];
	}
	//遍历，如果其中p1 和 p2 没有走完，就将剩余的元素放到辅助数组对应的索引位置
	while (i <= mid)
	{
		assist[z++] = array[i++];
	}
	while (j <= hi)
	{
		assist[z++] = array[j++];
	}

	//把辅助数组的元素放到原数组中。
	int k = 0;
	for (int index = lo; index <= hi; index++)
	{
		array[index] = assist[k++];
	}
	delete[]assist;

}

template<typename T>
void sort(T* array, int lo, int hi)
{
	if (lo >= hi)
 	{
		return;
	}

	//对lo到hi之间的数据进行分为两个组
	int mid = lo + (hi - lo) / 2;

	//分别对每一组进行排序
	sort(array, lo, mid);
	sort(array, mid+1, hi);

	// 在把分组之后的分组的数据进行合并
	merge(array, lo, mid, hi);
}

template<typename T>
void merge_sort(T* array, int size)
{
	//定义lo变量 hi 变量，分别记录数值中最小索引和最大索引
	int lo = 0;
	int hi = size - 1;

	//调用sort 完成数据，从索引lo 到hi的元素排序
	sort(array, lo, hi);
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
	//int result = factorial(5);
	//cout << " " << result << endl;

	int array[] = { 29,10,14,37,13 };
	int size = sizeof(array) / sizeof(array[0]);

	cout << "==========排序前=============" << endl;
	print_array(array, size);

	merge_sort(array, size);

	cout << "==========排序后=============" << endl;
	print_array(array, size);

	return 0;
}