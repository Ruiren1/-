#include"Queue.h"
int main()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 5);
	QueuePush(&pq, 4);
	printf("%d", QueueFront(&pq));
	QueuePop(&pq);
	printf("%d", QueueFront(&pq));


}