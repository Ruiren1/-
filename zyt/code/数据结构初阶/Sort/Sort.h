#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
void Swap(int* a, int* b);
void PrintArray(int* a, int n);
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int n);
void BubbleSort(int* a, int n);
void QuickSort(int* a, int left, int right);
void MergeSort(int* a, int n);
void CountSort(int* a, int n);
void TestOP();
void QuickSortNonR(int* a, int n);
void MergeSortNonR(int* a, int n);