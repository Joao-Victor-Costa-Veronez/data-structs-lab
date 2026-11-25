#ifndef QUEUENODEBST_H
#define QUEUENODEBST_H 1

#include <stdlib.h>
#include <stdio.h>
#include "nodeBST.h"

typedef struct queueNodeBST
{
    nodeBST *node;
    struct queueNodeBST *next;
} QueueNodeBST;

QueueNodeBST *createQueueNodeBST(nodeBST *node, QueueNodeBST *next);

#endif