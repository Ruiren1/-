#include"Heap.h"


void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType temp = *b;
	*b = *a;
	*a = temp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0 )
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1 < n&&a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] >a[parent])
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

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* temp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		assert(temp);
		php->a = temp;
		php->capacity = newcapacity;
	}
	php->a[php->size++] = x;
	AdjustUp(php->a, php->size - 1);
}


HPDataType HeapPop(HP* php)
{

	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	HPDataType temp = php->a[php->size - 1];
	php->size--;
	AdjustDown(php->a, php->size, 0);
	return temp;
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

void HeapSort(int* a, int n)
{
	//for (int i = 0; i < n; i++)//向下调整算法主要是从0开始，每次i++时，我们就将插入的元素的看成push
	//{
	//	AdjustUp(a, i);
	//}
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a,end,0);
		end--;
	}

}
