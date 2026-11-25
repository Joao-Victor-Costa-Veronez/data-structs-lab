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
void widthBST(BST *nodePoint);
nodeBST *searchBST(int key, BST *BSTPoint);
void cleansUpBST(BST *BSTPoint);
void cleansUpRecBST(nodeBST *nodePoint);
void destroyBST(BST **BSTPointPoint);
int removeFusionBST(int key, BST *BSTPoint);
int removeCopyBST(int key, BST *BSTPoint);
void predecessorBST(nodeBST *nodeBSTPoint);
void successorBST(nodeBST *nodeBSTPoint);

#endif