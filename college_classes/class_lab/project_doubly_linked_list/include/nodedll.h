#ifndef NODEDLL_H
#define NODEDLL_H 1

#include <stdio.h>
#include <stdlib.h>

typedef struct intDoublyNode
{
    int value;
    struct intDoublyNode *previous;
    struct intDoublyNode *next;
} nodeDLL;

nodeDLL *createNodeDLL(int value, nodeDLL *previous, nodeDLL *next);

#endif