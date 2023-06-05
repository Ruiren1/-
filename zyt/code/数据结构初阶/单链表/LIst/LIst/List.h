#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLN;
SLN* SListMalloc(SLTDataType x);
void SListPrint(SLN* phead);
void SListPushBack(SLN** phead, SLTDataType x);
void SListPushFront(SLN** pphead, SLTDataType x);
void SListPopBack(SLN** pphead);
void SListPopFront(SLN** pphead);
SLN* SListFind(SLN** pphead, SLTDataType x);
void SListInsert(SLN** pphead, SLN* pos, SLTDataType x);
void SListErase(SLN** pphead, SLN* pos);
void SListDestroy(SLN** pphead);
