#include<iostream>
using namespace std;

template<typename T>
void SWAP(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// ����ֵΪ �����ķֽ�ֵ���ڵ��������任�������
template<typename T>
int  partition(T* array, int lo, int hi)
{
	//ȷ���ֽ�ֵ
	int key = lo;

	// ȷ������λ��ָ���±꣬�ֱ�ָ����зֵ�Ԫ�ص���С�����������������������һ��λ�á�
	int left = lo;
	int right = hi + 1;

	//��ʼ�з�
	while (left <= right) // �ж�����Ϊleft ���ܳ���right��ָ��
	{
		//�ȴ�������ɨ�裬�ƶ�right ,�ҵ�һ���ȷֽ�ֵС��Ԫ�أ�ֹͣ
		while (array[--right] > array[key])
		{
			if (right == lo)
			{
				break;
			}
		}
		//�ȴ�������ɨ�裬�ƶ�left ,�ҵ�һ���ȷֽ�ֵ���Ԫ�أ�ֹͣ
		while (array[++left] < array[key])
		{
			if (left == hi)
			{
				break;
			}
		}
		//�ҵ�֮����н���
		SWAP(array[left], array[right]);
	}
	//�����ֽ�ֵ
	SWAP(array[key], array[right]);
	return right;
}

template<typename T>
void sort(T* array, int lo, int hi)
{
	//��ȫ�Լ��
	if (hi <= lo)
		return;
	//��Ҫ��������lo-hi������з��飬�������� �� �����飩
	int part = partition(array, lo, hi);

	// ����������
	sort(array, lo, part - 1);

	// ����������
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

	cout << "==========����ǰ=============" << endl;
	print_array(array, size);

	quick_sort(array, size);

	cout << "==========�����=============" << endl;
	print_array(array, size);

	return 0;
}