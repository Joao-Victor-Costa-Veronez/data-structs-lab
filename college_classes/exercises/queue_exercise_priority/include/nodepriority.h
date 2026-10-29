#ifndef NODEPRIORITY_H
#define NODEPRIORITY_H 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct priorityNode
{
    char value[255];
    int priority;
    struct priorityNode *next;
    struct priorityNode *previous;
} nodePriority;

nodePriority *createNodePriority(char *value, int priority, nodePriority *next, nodePriority *previous);

#endif