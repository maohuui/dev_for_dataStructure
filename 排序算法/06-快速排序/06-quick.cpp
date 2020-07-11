#include<iostream>
using namespace std;

template<typename T>
void SWAP(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// 返回值为 分组后的分界值所在的索引，变换后的索引
template<typename T>
int  partition(T* array, int lo, int hi)
{
	//确定分界值
	int key = lo;

	// 确定两个位置指针下标，分别指向待切分的元素的最小索引处，和最大索引处的下一个位置。
	int left = lo;
	int right = hi + 1;

	//开始切分
	while (left <= right) // 判断条件为left 不能超过right的指针
	{
		//先从右往左扫描，移动right ,找到一个比分界值小的元素，停止
		while (array[--right] > array[key])
		{
			if (right == lo)
			{
				break;
			}
		}
		//先从左往右扫描，移动left ,找到一个比分界值大的元素，停止
		while (array[++left] < array[key])
		{
			if (left == hi)
			{
				break;
			}
		}
		//找到之后进行交换
		SWAP(array[left], array[right]);
	}
	//交换分界值
	SWAP(array[key], array[right]);
	return right;
}

template<typename T>
void sort(T* array, int lo, int hi)
{
	//安全性检测
	if (hi <= lo)
		return;
	//需要对数组中lo-hi数组进行分组，（左子组 和 右子组）
	int part = partition(array, lo, hi);

	// 左子组有序
	sort(array, lo, part - 1);

	// 右子组有序
	sort(array, part + 1, hi);
}

template<typename T>
void quick_sort(T* array, int size)
{
	int lo = 0;
	int hi = size - 1;

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

	quick_sort(array, size);

	cout << "==========排序后=============" << endl;
	print_array(array, size);

	return 0;
}