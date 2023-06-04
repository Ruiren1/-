#include"Sort.h"

int main()
{
	int a[] = { 6 ,45 ,45, 34 ,34 ,76 ,76 ,1,-1,-8,-4};
	CountSort(a,sizeof(a) / sizeof(int));
	/*TestOP();*/
	//MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}