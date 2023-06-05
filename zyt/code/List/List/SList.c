#include"SList.h"
#include<assert.h>
SLN* SListMalloc(SLTDataType x)
{
	SLN* newnode = (SLN*)malloc(sizeof(SLN));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPrint(SLN*phead)
{
	//遍历链表
	SLN* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}
void SListPushBack(SLN** pphead ,SLTDataType x)
{
	SLN*newnode= SListMalloc(x);
	if (*pphead== NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLN* tail = *pphead;
		while (tail->next != NULL)//找到含有NULL节点的位置；即最后的位置；
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
void SListPushFront(SLN** pphead, SLTDataType x)
{
	SLN* newnode = SListMalloc(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}
void SListPopBack(SLN** pphead)//这里需要考虑NULL，只有一个和两个及两个以上
{
	SLN* tail=*pphead;
	SLN* prev = NULL;
	assert(*pphead != NULL);
	if ((*pphead)->next == NULL)
	{
		*pphead = NULL;
	}
	else
	{
		while (tail->next !=NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
void SListPopFront(SLN** pphead)//这里不需要用考虑只有一个节点的情况，因为没有引用next
{
	SLN* temp = *pphead;
	assert(*pphead != NULL);
	*pphead = (*pphead)->next;	
	free(temp);
}
SLN* SListFind(SLN** pphead, SLTDataType x)
{
	SLN* temp = *pphead;
	while (temp)
	{

		if(temp->data == x)
		{
			return temp;
		}
		else
		{
			temp = temp->next;
		}
		
	}
	return NULL;
}
void SListInsert(SLN** pphead, SLN* pos, SLTDataType x)//在pos的前面插入
{
	if (pos = *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLN* newnode = SListMalloc(x);
		assert(newnode != NULL);
		SLN* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SListErase(SLN** pphead, SLN* pos)
{
	if (*pphead == pos)
	{
		SListPopBack(pphead);
	}
	else
	{
		SLN* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
	}
}
void SListDestroy(SLN** pphead)
{
	assert(*pphead != NULL);
	while(*pphead!=NULL)
	{
		SLN* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

