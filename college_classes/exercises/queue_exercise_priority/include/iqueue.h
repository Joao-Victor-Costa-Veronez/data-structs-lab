#ifndef IQUEUE_H
#define IQUEUE_H 1

#include "noSLI.h"
#include "listaSLI.h"

typedef struct int_queue
{
    NoSLI *inicial;
    NoSLI *final;
    int length;
} IQueue;

IQueue *createIQueue();

void cleanUpIQueue(IQueue *queuePoint);
void deleteIQueue(IQueue **queuePointPoint);
void showIQueue(IQueue *queuePoint);

void queueIQueue(int value, IQueue *queuePoint);
int unqueueIQueue(IQueue *queuePoint);
int nextIQueue(IQueue *queuePoint);

#endif