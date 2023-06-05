#include"Seqlist.h"

void text1()
{
	SL ps;
	SeqListInit(&ps);
	SeqListCheckCapacity(&ps);
	SeqListPushBack(&ps, 1);
	SeqListPushFront(&ps,2);

	SeqListPrintf(&ps);



}
int main()
{
	text1();
}
