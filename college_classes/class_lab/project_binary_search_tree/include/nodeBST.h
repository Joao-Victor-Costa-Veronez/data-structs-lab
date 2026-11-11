#ifndef NODEBST_H
#define NODEBST_H 1

// Importing libraries
#include <stdlib.h>
#include <stdio.h>

// Declaring structs
typedef struct nodeBST
{
    int key;
    struct nodeBST *leftChild;
    struct nodeBST *rightChild;
} nodeBST;

// Declaring functions
nodeBST *createNodeBST(int key, nodeBST *leftChild, nodeBST *rightChild);

#endif