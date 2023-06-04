#include<stdio.h>
#include"SList.h"
void SLText1();
int main()
{
	
	SLText1();
	return 0;
}
void SLText1()
{
	SLN* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 6);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPushFront(&plist, 6);
	SListPrint(plist);
	printf("\n");
	SListPopBack(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SLN* pos=SListFind(&plist, 2);
	
	
		
}