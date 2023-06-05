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

void SeqListInit(SL* ps);//��̬˳������
void SeqListDestory(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
int SeqListFind(SL* ps, SLDataType x);//�ҵ����ҷ��ظ�ֵ���±�
void SeqListInsert(SL* ps, int pos, SLDataType x);//���м����һ������pos��ʾ�ڼ���λ��
void SeqListErase(SL* ps, int pos);//ɾ��ָ��λ�õ�����
void SeqListPrintf(SL* ps);
