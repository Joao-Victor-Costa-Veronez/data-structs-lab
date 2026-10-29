#ifndef IQUEUE_H
#define IQUEUE_H 1

#include "nodepriority.h"

typedef struct priorityQueue
{
    nodePriority *inicial;
    nodePriority *final;
    int length;
} priorityQueue;

priorityQueue *createpriorityQueue();
void showPriorityQueue(priorityQueue *queuePoint);
void queuePriorityQueue(char *value, int priority, priorityQueue *queuePoint);
int unqueuePriorityQueue(priorityQueue *queuePoint);
char nextPriorityQueue(priorityQueue *queuePoint);
void cleanUpPriorityQueue(priorityQueue *queuePoint);
void deletePriorityQueue(priorityQueue **queuePointPoint);

#endif