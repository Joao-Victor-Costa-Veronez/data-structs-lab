#ifndef IQUEUE_H
#define IQUEUE_H 1

#include "nodesll.h"

typedef struct int_queue
{
    nodeSLL *inicial;
    nodeSLL *final;
    int length;
} IQueue;

IQueue * createIQueue();

void cleanUpIQueue(IQueue *queuePoint);
void deleteIQueue(IQueue **pontqueuePoint);
void showIQueue(IQueue *queuePoint);

void queueIQueue(int valor, IQueue *queuePoint);
int unqueueIQueue(IQueue *queuePoint);
int nextIQueue(IQueue *queuePoint);

#endif