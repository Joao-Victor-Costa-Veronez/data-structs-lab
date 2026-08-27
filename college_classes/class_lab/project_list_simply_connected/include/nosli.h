#ifndef NOSLI_H
#define NOSLI_H 1

#include <stdlib.h>

typedef struct simple_node_int
{
    int value;
    struct simple_node_int *next;
} node_LSC;

node_LSC *create_node_LSC(int value, node_LSC *next);

#endif