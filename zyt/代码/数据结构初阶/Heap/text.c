#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

int main()
{
	/*HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 4);
	HeapPush(&hp, 18);
	HeapPush(&hp, 42);
	HeapPush(&hp, 12);
	HeapPush(&hp, 21);
	HeapPush(&hp, 3);
	HeapPush(&hp, 5);
	HeapPush(&hp, 5);
	HeapPush(&hp, 50);
	HeapPush(&hp, 5);
	HeapPush(&hp, 5);
	HeapPush(&hp, 15);
	HeapPush(&hp, 5);
	HeapPush(&hp, 45);
	HeapPush(&hp, 5);

	int k = 0;
	scanf("%d", &k);
	while (!HeapEmpty(&hp) && k--)
	{
		printf("%d ", HeapPop(&hp));
	}
	printf("\n");

	return 0;*/
	int i = 0;
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0])-1; i++)
	{
		printf("%d  ", a[i]);
	}
}