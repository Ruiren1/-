#pragma once
typedef int SLDataType;//这样子写的好处是可以随意修改存储的数据类型
// 动态顺序表
typedef struct SeqList
{
	SLDataType* a;
	int size;//表示数组存储了多少个数据
	int capacity;//表示实际能够存储多少数据
}SL;
//接口函数，x表示需要插入的数
void SeqListInit(SL* ps);//动态顺序表插入
void SeqListCheckCapacity(SL* ps);
void SeqListDestory(SL*ps);
void SeqListPushBack(SL* ps,SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
int SeqListFind(SL* ps, SLDataType x);//找到并且返回该值的下标
void SeqListInsert(SL* ps,int pos,SLDataType x);//从中间插入一个数，pos表示第几个位置
void SeqListErase(SL* ps, int pos);//删除指定位置的数据
void SeqListPrintf(SL*ps);
















