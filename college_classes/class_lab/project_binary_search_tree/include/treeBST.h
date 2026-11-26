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

// Declaring functions
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
nodeBST *searchWithFatherBST(int key, BST *BSTPoint, nodeBST **fatherPointPoint);
void cleansUpBST(BST *BSTPoint);
void cleansUpRecBST(nodeBST *nodePoint);
void destroyBST(BST **BSTPointPoint);
nodeBST *predecessorBST(nodeBST *nodeBSTPoint);
nodeBST *successorBST(nodeBST *nodeBSTPoint);
int removeFusionBST(int key, BST *BSTPoint);
int removeCopyBST(int key, BST *BSTPoint);
void drawBST(BST *BSTPoint, const char *outputFileName);

#endif