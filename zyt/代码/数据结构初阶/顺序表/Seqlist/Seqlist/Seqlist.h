#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma once

typedef int SLDataType;
typedef struct Seqlist
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

void SeqListInit(SL* ps);//动态顺序表插入
void SeqListDestory(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
int SeqListFind(SL* ps, SLDataType x);//找到并且返回该值的下标
void SeqListInsert(SL* ps, int pos, SLDataType x);//从中间插入一个数，pos表示第几个位置
void SeqListErase(SL* ps, int pos);//删除指定位置的数据
void SeqListPrintf(SL* ps);
