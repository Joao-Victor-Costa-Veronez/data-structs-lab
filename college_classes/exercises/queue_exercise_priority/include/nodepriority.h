#ifndef NODEPRIORITY_H
#define NODEPRIORITY_H 1

#include <stdlib.h>
#include <stdio.h>

typedef struct priorityNode
{
    char value;
    int priority;
    struct priorityNode *next;
} nodePriority;

nodePriority *createNodePriority(char value, int priority, nodePriority *next);

#endif