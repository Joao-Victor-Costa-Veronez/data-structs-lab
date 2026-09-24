#ifndef NODEDLL_H
#define NODEDLL_H 1

// Including libraries
#include <stdio.h>
#include <stdlib.h>

// Declaring structs
// Interger Doubly Linked Node Struct
typedef struct intDoublyNode
{
    // Declaring variables
    int value;
    struct intDoublyNode *previous;
    struct intDoublyNode *next;
  // Declaring struct's nickname
} nodeDLL;

// Declaring functions
nodeDLL *createNodeDLL(int value, nodeDLL *previous, nodeDLL *next);

#endif