// MergeSort.cpp : 定义控制台应用程序的入口点。
#include "iostream"
using namespace std;
void _MergeSort(int *a, int *tmp, int start, int end)
{
	int mid = start + ((end - start) >> 1);//除2操作
	if (start < mid)
		_MergeSort(a, tmp, start, mid);
	if (mid + 1<end)
		_MergeSort(a, tmp, mid + 1, end);
	//分成两部分分别进行合并排序
	int start1 = start;
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = end;
	int index = start;
	//从两个区间选择较小的放入tmp中
	while ((start1 <= end1) && (start2 <= end2))
	{
		if (a[start1] < a[start2])
			tmp[index++] = a[start1++];//++等级小于[]
		else
			tmp[index++] = a[start2++];
	}
	while (start1 <= end1)
	{
		tmp[index++] = a[start1++];
	}
	while (start2 <= end2)
	{
		tmp[index++] = a[start2++];
	}
	//将tmp中的数据写入a中
	for (int i = start; i < index; i++)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int*a, int start, int end)
{
	int*tmp = new int[end - start + 1];
	_MergeSort(a, tmp, start, end);
	delete[]tmp;
}
int main()
{
	int a[8] = { 2, 9, 5, 4, 3, 6, 8, 7 };
	int start = 0;
	int end = 7;
	MergeSort(a, start, end);
	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}