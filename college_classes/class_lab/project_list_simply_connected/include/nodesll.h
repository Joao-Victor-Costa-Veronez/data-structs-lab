#ifndef NODESLL_H
#define NODESLL_H 1

// Including libraries
#include <stdlib.h>

// Declaring structs
typedef struct simple_node_int
{
    // Declaring variables
    int value;
    struct simple_node_int *next;
} node_SLL;

// Declaring functions
node_SLL *create_node_SLL(int value, node_SLL *next);

#endif