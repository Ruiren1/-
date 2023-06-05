#include "Sort.h"
#include"Stack.h"
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// 升序
// 最坏：O(N^2)  逆序
// 最好：O(N)    顺序有序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
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

void ShellSort(int* a, int n)
{
	int gap=n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
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

// 最坏：O(N^2)
// 最好：O(N^2).
void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	int maxi = 0, mini = 0;
	while (left < right)
	{
		maxi = mini = left;
		for (int i = left+1; i <= right; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[maxi])
			{
				mini = i;
			}
		}
		int temp=a[maxi];
		if (a[left] == a[maxi])
			temp = a[left];
		Swap(&a[left], &a[mini]);
		Swap(&a[right], &temp);
		left++;
		right--;
	}
}

void AdjustDown(int* a,int n, int parent)
{
	int child = parent * 2 + 1;
	
	while (child<n)
	{
		if (child+1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
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

	int i;
	int end = n - 1;
	for (i = ((end - 1) - 1) / 2; i >= 0; i--)//向下调整建堆， O(N*logN)
	{
		AdjustDown(a, n, i);
	}
	while (end > 0)//首位交换之后pop，从根再次建堆
	{
		Swap(&a[0], &a[end]);
		end--;
		AdjustDown(a, end+1, 0);
	}
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}
int GetMidNumi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
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
	else // a[left] > a[mid]
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

//左右指针法
int  PartSort1(int* a, int left, int right)
{
	int midi = GetMidNumi(a, left, right);
	if(midi!=left)
	Swap(&a[midi], &a[left]);
	int begin = left;
	int end = right;
	int keyi = left;
	while (begin < end)
	{
		while (begin < end && a[keyi] <= a[end])//找小的等于不行
		{
			end--;
		}
		while (begin < end && a[keyi]>=a[begin])//找大的，等于不行
		{
			begin++;
		}

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[keyi], &a[begin]);

	return begin;
}

int PartSort2(int* a, int left, int right)
{
	int midi = GetMidNumi(a, left, right);
	if (midi != left)
		Swap(&a[midi], &a[left]);
	int begin = left;
	int end = right;
	int key = a[left];//等下会填坑，保存key的值
	int hole = begin;
	while (begin < end)
	{
		while (begin < end && key <= a[end])
		{
			end--;
		}
		a[hole] = a[end];
		hole = end;
		while (begin < end && key >= a[begin])
		{
			begin++;
		}
		a[hole] = a[begin];
		hole = begin;
	}
	a[begin] = key;
	return begin;
}

int PartSort3(int* a, int left, int right)
{
	int midi = GetMidNumi(a, left, right);
	if (midi != left)
		Swap(&a[midi], &a[left]);
	int begin = left;
	int end = right;
	int keyi = left;
	int cur = begin + 1;
	int prev = begin;
	while (cur <= right)
	{
		if (a[keyi] >= a[cur] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	if (right-left + 1<10)
	{
		SelectSort(a + left ,right-left+1);
	}
	else
	{
		int keyi = PartSort3(a, left, right);
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
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
	_MergeSort(a, mid + 1,right,temp);
	int begin = left;
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	while (begin1<=mid&&begin2<=right)
	{
		if (a[begin1] < a[begin2])
		{
			temp[begin++] = a[begin1++];
		}
		else
		{
			temp[begin++] = a[begin2++];
		}

	}
	while(begin1<=mid)
	{
		temp[begin++] = a[begin1++];
	}
	while (begin2 <= right)
	{
		temp[begin++] = a[begin2++];
	}

	memcpy(a + left, temp + left, sizeof(int )*(right - left + 1));

}
void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	assert(temp);
	_MergeSort(a, 0, n - 1, temp);
	
	free(temp);
}

void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
		if (min > a[i])
		{
			min= a[i];
		}
	}
	int size = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * size);
	memset(count, 0, sizeof(int)*size);
	for (int i = 0; i < n; i++)
	{
		count[a[i]-min]++;
	}
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}

	free(count);



}

void QuickSortNonR(int* a, int n)
{
	ST st;
	StackInit(&st);
	StackPush(&st, n - 1);
	StackPush(&st, 0);
	while (!StackEmpty(&st))
	{
		int begin  = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		if (end - begin + 1 < 10)
		{
			SelectSort(a + begin, end - begin + 1);
		}
		else
		{
			int keyi = PartSort3(a, begin, end);
			if (end > keyi + 1)
			{
				StackPush(&st, end);
				StackPush(&st, keyi + 1);
			}
			if (begin < keyi - 1)
			{
				StackPush(&st, keyi - 1);
				StackPush(&st, begin);
			}
		}
	}

	StackDestroy(&st);
}
void MergeSortNonR(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	assert(temp);
	int gap = 1;
	int i;
	while (gap < n)
	{
		for (i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			int begin = begin1;
			if (begin2 >= n || end1 >= n)
			{
				break;
			}
			if (end2>=n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					temp[begin++] = a[begin1++];
				}
				else
				{
					temp[begin++] = a[begin2++];
				}

			}
			while (begin1 <= end1)
			{
				temp[begin++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				temp[begin++] = a[begin2++];
			}
			memcpy(a + i, temp + i, sizeof(int) * (end2-i+1));
		}
		gap *= 2;
	}

	free(temp);
}
 

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

		int begin1 = clock();
		InsertSort(a1, N);
		int end1 = clock();
		int begin2 = clock();
		ShellSort(a2, N);
		int end2 = clock();
		int begin3 = clock();
		SelectSort(a3, N);
		int end3 = clock();
		int begin4 = clock();
		HeapSort(a4, N);
		int end4 = clock();
		int begin5 = clock();
		QuickSort(a5, 0, N - 1);
		int end5 = clock();
		int begin6 = clock();
		//MergeSort(a6, N);
		int end6 = clock();
		printf("InsertSort:%d\n", end1 - begin1);
		printf("ShellSort:%d\n", end2 - begin2);
		printf("SelectSort:%d\n", end3 - begin3);
		printf("HeapSort:%d\n", end4 - begin4);
		printf("QuickSort:%d\n", end5 - begin5);
		//printf("MergeSort:%d\n", end6 - begin6);
		free(a1);
		free(a2);
		free(a3);
		free(a4);
		free(a5);
		free(a6);
	

}
