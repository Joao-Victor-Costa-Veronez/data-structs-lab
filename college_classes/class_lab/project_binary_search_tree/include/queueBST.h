#ifndef QUEUEBST_H
#define QUEUEBST_H 1

#include "queueNodeBST.h"

typedef struct queueBST
{
    QueueNodeBST *front;
    QueueNodeBST *rear;
    int size;
} QueueBST;

QueueBST *createQueueBST();
void clearQueueBST(QueueBST *queue);
void destroyQueueBST(QueueBST **queuePointer);
void showQueueBST(QueueBST *queue);

void enqueueQueueBST(nodeBST *node, QueueBST *queue);
int *dequeueQueueBST(QueueBST *queue);
nodeBST *peekQueueBST(QueueBST *queue);

#endif