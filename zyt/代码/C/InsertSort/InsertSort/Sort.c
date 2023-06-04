﻿#include<stdio.h>
#include<stdlib.h>
void ArrPrintf(int* a, int m)
{
	for (int i = 0; i < m; i++)
	{
		printf("%d  ", a[i]);
	}
}
void Swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void InsertSort(int* a, int m)
{
	int i;
	for (i = 0; i < m - 1; ++i)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > temp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}
void ShellSort(int *a, int m)
{
	int gap=m;
	while(gap>1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < m - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > temp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}
	}
}

void SelectSort(int* a, int m)
{
	int begin = 0;
	int end = m - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
			if (a[mini] > a[i])
			{
				mini = i;
			}
		}
		Swap(&a[end], &a[maxi]);
		if (mini == end)
		{
			mini = maxi;
		}
		Swap(&a[begin], &a[mini]);
		
		begin++;
		end--;
	}
}
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//建堆
	int i;
	int end = n - 1;
	for (i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i); 
	}
	while (end > 0)
	{
	    Swap(a, &a[end]);
		end--;
		AdjustDown(a, end+1, 0);
	}
	
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else//a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//挖坑法
int PartSort1(int* a, int left, int right)
{

	int begin = left, end = right;
	int mid = GetMidIndex(a, left, right);//三数取中
	Swap(&a[mid], &a[begin]);
	int key = a[begin];
	int pivot = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[pivot] = a[end];
		pivot = end;
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pivot] = a[begin];
		pivot = begin;
	}
	a[begin] = key;
	return pivot;
}
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int begin = left, end = right;
	int keyi = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}
		while (begin < end && a[begin] <= a[keyi])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[keyi], &a[begin]);
	return begin;
}

int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int prev = left, cur = left + 1;
	int keyi = left;
	while (cur<=right)
	{
		while (a[cur] < a[keyi]&&++prev!=cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int keyindex = PartSort3(a, left, right);
	if (keyindex - 1 - left > 10)
	{
		QuickSort(a, left, keyindex - 1);
	}
	else
	{
		InsertSort(a+left, keyindex - 1 - left + 1);
	}
	if (right - (keyindex + 1) > 10)
	{
		QuickSort(a, keyindex + 1, right);
	}
	else
	{
		InsertSort(a + keyindex + 1, right - (keyindex + 1)+1);
	}
}

void _MergeSort(int* a, int left, int right, int* temp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, temp);
	_MergeSort(a, mid + 1, right, temp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[index++] = a[begin1++];
		}
		else
		{
			temp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		temp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[index++] = a[begin2++];
	}
	for (int i = left; i<=right; i++)
	{
		a[i] = temp[i];
	}
}

void MergeSort(int* a, int m)
{
	int* temp = (int*)malloc(sizeof(int) * m);
	_MergeSort(a, 0, m - 1, temp);
	free(temp);
}

int main()
{
	int a[] = { 3,5,9,7,8,6,1,2,4 ,0}; 
	//SelectSort(a, sizeof(a) / sizeof(int));
	MergeSort(a,sizeof(a) / sizeof(int));
	ArrPrintf(a, sizeof(a) / sizeof(int));
}