 #pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct LIstNode* prev;
	struct ListNode* next;
}LN;
void ListPrint(LN* phead);
void ListInit(LN** phead);
bool LEMpty(LN* phead);
void ListPushBack(LN* phead,LTDataType x);
void ListPopBack(LN* phead);
void ListPushFront(LN* phead, LTDataType x);
void ListPopFront(LN* phead);
void ListInsert(LN* phead,int pos,int x);



