#include"Queue.h"
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
    pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
    assert(pq);
    QNode* cur = pq->head;
    while (cur)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
    pq->size = 0;

}

void QueuePush(Queue* pq, QDatatype x)
{
    assert(pq);
    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    assert(newnode);
    newnode->Data = x;
    newnode->next;
    if (pq->size == 0)
    {
        pq->head =pq->tail= newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
    pq->size++;

}

void QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->size);
    if (pq->head->next==NULL)
    {
        free(pq->head);
        pq->head =pq->tail= NULL;
    }
    else
    {
        QNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }
    pq->size--;
}

int QueueSize(Queue* pq)
{
    assert(pq);
    return pq->size;
}

bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->size==0;
}

QDatatype QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->Data;
}

QDatatype QueueBack(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty);
    return pq->tail->Data;
}


