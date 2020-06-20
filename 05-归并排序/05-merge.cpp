#include<iostream>
using namespace std;

template<typename T>
void SWAP(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
//��n�Ľ׳�
int factorial(int n)
{
	if (n == 1)
		return n;
	return n * factorial(n - 1);
}

//�ϲ�
template<typename T>
void merge(T* array, int lo, int mid, int hi)
{
	int* assist = new int[hi-lo+1];

	//��������λ��ָ�룬λ������
	int i = lo;
	int j = mid+1
;
	int z = 0;

	//�������ƶ�p1��p2 ָ���ж϶�Ӧ�����ֵ���ҳ���С�������ŵ����������Ӧ��λ��
	while (i <= mid && j <= hi)
	{
		//�Ƚ϶�Ӧ����λ�õ�ֵ
		if (array[i] > array[j])
			assist[z++] = array[j++];
		else
			assist[z++] = array[i++];
	}
	//�������������p1 �� p2 û�����꣬�ͽ�ʣ���Ԫ�طŵ����������Ӧ������λ��
	while (i <= mid)
	{
		assist[z++] = array[i++];
	}
	while (j <= hi)
	{
		assist[z++] = array[j++];
	}

	//�Ѹ��������Ԫ�طŵ�ԭ�����С�
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

	//��lo��hi֮������ݽ��з�Ϊ������
	int mid = lo + (hi - lo) / 2;

	//�ֱ��ÿһ���������
	sort(array, lo, mid);
	sort(array, mid+1, hi);

	// �ڰѷ���֮��ķ�������ݽ��кϲ�
	merge(array, lo, mid, hi);
}

template<typename T>
void merge_sort(T* array, int size)
{
	//����lo���� hi �������ֱ��¼��ֵ����С�������������
	int lo = 0;
	int hi = size - 1;

	//����sort ������ݣ�������lo ��hi��Ԫ������
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

	cout << "==========����ǰ=============" << endl;
	print_array(array, size);

	merge_sort(array, size);

	cout << "==========�����=============" << endl;
	print_array(array, size);

	return 0;
}