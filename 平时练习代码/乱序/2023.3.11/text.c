#include<stdio.h>
#include"SList.h"
void LText1();
int main()
{

	LText1();
	return 0;
}
void LText1()
{
	LN* plist = NULL;
	ListInit(&plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPushFront(plist, -1);
	ListPrint(plist);


}