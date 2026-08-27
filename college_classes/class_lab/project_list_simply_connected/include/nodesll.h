#ifndef NODESLL_H
#define NODESLL_H 1

#include <stdlib.h>

typedef struct simple_node_int
{
    int value;
    struct simple_node_int *next;
} node_SLL;

node_SLL *create_node_LSC(int value, node_SLL *next);

#endif