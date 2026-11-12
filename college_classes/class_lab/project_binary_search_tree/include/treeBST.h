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
void insertBST(int key, BST *BSTPoint);
void visitBST(nodeBST *node);
void preRecOrderBST(BST *BSTPoint);
void preAuxRecOrderBST(nodeBST *nodePoint);
void inRecOrderBST(BST *BSTPoint);
void inAuxRecOrderBST(nodeBST *nodePoint);
void posRecOrderBST(BST *BSTPoint);
void posAuxRecOrderBST(nodeBST *nodePoint);

#endif