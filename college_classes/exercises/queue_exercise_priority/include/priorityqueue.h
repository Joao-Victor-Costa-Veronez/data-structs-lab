#ifndef IQUEUE_H
#define IQUEUE_H 1

#include "nodepriority.h"
#include "listdll.h"

typedef struct priorityQueue
{
    nodeDLL *inicial;
    nodeDLL *final;
    int length;
} priorityQueue;

priorityQueue *createpriorityQueue();
void showPriorityQueue(priorityQueue *queuePoint);
int unqueuePriorityQueue(priorityQueue *queuePoint);
void queuePriorityQueue(int value, priorityQueue *queuePoint);
int nextPriorityQueue(priorityQueue *queuePoint);
void cleanUpPriorityQueue(priorityQueue *queuePoint);
void deletePriorityQueue(priorityQueue **queuePointPoint);

#endif