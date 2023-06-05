#pragma once
typedef int SLDataType;//������д�ĺô��ǿ��������޸Ĵ洢����������
// ��̬˳���
typedef struct SeqList
{
	SLDataType* a;
	int size;//��ʾ����洢�˶��ٸ�����
	int capacity;//��ʾʵ���ܹ��洢��������
}SL;
//�ӿں�����x��ʾ��Ҫ�������
void SeqListInit(SL* ps);//��̬˳������
void SeqListCheckCapacity(SL* ps);
void SeqListDestory(SL*ps);
void SeqListPushBack(SL* ps,SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
int SeqListFind(SL* ps, SLDataType x);//�ҵ����ҷ��ظ�ֵ���±�
void SeqListInsert(SL* ps,int pos,SLDataType x);//���м����һ������pos��ʾ�ڼ���λ��
void SeqListErase(SL* ps, int pos);//ɾ��ָ��λ�õ�����
void SeqListPrintf(SL*ps);
















