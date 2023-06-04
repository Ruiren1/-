

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int BTDatatype;
typedef struct BinaryTreeNoDe
{
	BTDatatype data;
	struct BinaryTreeNoDe* left;
	struct BinaryTreeNoDe* right;
}BTNode;

typedef BTNode* QDatatype;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDatatype Data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDatatype x);
void QueuePop(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
QDatatype QueueFront(Queue* pq);
QDatatype QueueBack(Queue* pq);
