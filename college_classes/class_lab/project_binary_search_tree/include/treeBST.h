#ifndef TREEBST_H
#define TREEBST_H 1

// Importing libraries
#include "nodeBST.h"

// Declaring structs
typedef struct BST
{
    nodeBST *root;
    int nodesQuantity;
} BST;

// Declarign functions
BST *createTreeBST();

#endif