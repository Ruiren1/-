#include"SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void SeqListInit(SL*ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListDestory(SL*ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity =0;
	ps->size = 0;

}
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2; //->的优先级比这里的运算符都高
		SLDataType* temp = (SLDataType*)realloc(ps->a, newcapacity * (sizeof(SLDataType)));
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = temp;
		ps->capacity = newcapacity;
	}
}
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(&ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(SL*ps)
{
	assert(ps->size > 0);
	ps->size--;	
}
void SeqListPushFront(SL*ps,SLDataType x)
{
	SeqListCheckCapacity(ps);
	int end = ps->size-1;
	while (end > 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
}
void SeqListPopFront(SL*ps)
{
	int begain = 0;
	assert(ps->size > 0);
	while (begain < ps->size - 1)
	{
		ps->a[begain] = ps->a[begain + 1];
		begain++;
	}
	ps->size--;
}
int SeqListFind(SL* ps, SLDataType x)
{
	if (ps->size <= 0)
	{
		exit(-1);
	}
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->a[i])
		{
			return i;
		}
	}
}
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	SeqListCheckCapacity(ps);
	int end = ps->size;
	while (end>=pos)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
	assert(ps ->size > 0);
	while (pos < ps->size)
	{
		ps->a[pos - 1] = ps->a[pos];
		pos++;
	}
	ps->size--;

}
void SeqListPrintf(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}



