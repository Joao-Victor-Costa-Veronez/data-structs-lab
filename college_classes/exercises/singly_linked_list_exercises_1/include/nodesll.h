#ifndef NODESLL_H
#define NODESLL_H 1

// Including libraries
#include <stdlib.h>
#include <stdio.h>

typedef struct simple_node_int
{
    // Declaring variables
    int value;
    struct simple_node_product *next;
} node_sll;

// Declaring functions
node_sll *create_node_SLL(int value, node_sll *next);

#endif