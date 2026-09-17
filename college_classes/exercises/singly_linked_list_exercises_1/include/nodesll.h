#ifndef NODESLL_H
#define NODESLL_H 1

// Including libraries
#include <stdlib.h>
#include <stdio.h>

// Declaring structs
typedef struct simple_node_int
{
    // Declaring variables
    int value;
    struct simple_node_int *next;
} node_sll;

// Declaring functions
node_sll *create_node_sll(int value, node_sll *next);

#endif