#ifndef NODEDLL_H
#define NODEDLL_H 1

#include <stdio.h>
#include <stdlib.h>

typedef struct intDoublyNode
{
    int value;
    struct intDoublyList *previous;
    struct intDoublyList *next;
} nodeDLL;

nodeDLL *createListDLL(int value, nodeDLL *previous, nodeDLL *next);

#endif