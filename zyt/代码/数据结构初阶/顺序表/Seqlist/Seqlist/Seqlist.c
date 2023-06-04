#include"Seqlist.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = (SLDataType*)realloc(ps->a, newcapacity * (sizeof(SLDataType)));
		assert(temp);
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

void SeqListPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(&ps);
	for (int i = 0; i <ps->size; i++)
	{
		ps->a[i+1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPrintf(SL* ps)
{
	assert(ps);
	assert(ps->size);
	for (int i=0; i < ps->size; i++)
	{
		printf("%d", ps->a[i]);
	}
}

