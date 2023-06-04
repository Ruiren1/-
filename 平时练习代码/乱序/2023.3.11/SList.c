#include"SList.h"
void ListPrint(LN* phead)
{
	assert(phead);
	LN*cur = phead->next;
	while (cur!=phead)
	{
		printf("%d", cur->data);
		cur = cur->next; 
	}

}
void ListInit(LN* *pphead)
{
	*pphead = (LN*)malloc(sizeof(LN));
	assert(*pphead);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
	(* pphead)->data = -1;
}
bool LEMpty(LN* phead)
{
	assert(phead);
	return phead->prev = phead->next;
}
void ListPushBack(LN* phead, LTDataType x)
{
	assert(phead);
	LN* newnode = (LN*)malloc(sizeof(LN));
	assert(newnode);
	newnode->data = x;
	LN* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode; 
}
void ListPopBack(LN* phead)
{
	assert(phead);
	LN* tail = phead->prev;
	LN* mtail = tail->prev;
	mtail->next = phead;
	phead->prev = mtail;
	free(tail);
	tail = NULL;
}

void ListPushFront(LN* phead, LTDataType x)
{
	LN* newnode = (LN*)malloc(sizeof(LN));
	assert(newnode);
	newnode->data = x;
	LN* temp = phead->next;
	phead->next = newnode;
	temp->prev = newnode;
	newnode->prev = phead;
	newnode->next = temp;
}

void ListPopFront(LN* phead)
{
	assert(phead);
	LN* temp = phead->next;
	phead->next = temp->next;
	temp->next->prev = phead;
	free(temp);
	temp=NULL;
}

void ListInsert(LN* phead, int pos, int x)
{
	assert(phead);
	LN* cur = phead;
	LN* newnode = (LN*)malloc(sizeof(LN));
	assert(newnode);
	newnode->data = x;
	while (cur->data != pos)
	{
		cur = cur->next;
	}
	LN* prev = cur->prev;
	prev->next = newnode;
	newnode->prev = prev;
	cur->next->prev = newnode;
	newnode->next = cur;

}

	
