#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void Swap(HPDataType* a, HPDataType* b);
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent);
void HeapInit(HP* php);
void HeapPush(HP* php, HPDataType x);
HPDataType HeapPop(HP* php);
bool HeapEmpty(HP* php);
void HeapSort(int* a, int n);