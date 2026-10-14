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
} nodeSLL;

// Declaring functions
nodeSLL *create_node_SLL(int value, nodeSLL *next);

#endif