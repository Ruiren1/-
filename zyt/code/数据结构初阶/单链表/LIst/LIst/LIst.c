#include"List.h"

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
	return ;
}

void SListPrint(SLN* phead)
{
	SLN* newnode;
	while (phead != NULL)
	{
		printf("%d", phead->data);
		newnode = phead->next;
		phead = newnode;
	}
}
