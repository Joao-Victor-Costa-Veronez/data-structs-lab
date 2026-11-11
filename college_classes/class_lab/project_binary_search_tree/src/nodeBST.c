// Importing libraries
#include "nodeBST.h"

// Function that creates a new tree node
nodeBST *createNodeBST(int key, nodeBST *leftChild, nodeBST *rightChild)
{
    // Allocing the memory
    nodeBST *new = (nodeBST *)malloc(sizeof(nodeBST));

    // If there was an error
    if (new == NULL)
    {
        // Inform and exit
        printf("Fatal error: Failed to allocate memory to nodeBST.\n");
        exit(1);
    }
    // Putting default values in the variables
    new->key = key;
    new->leftChild = leftChild;
    new->rightChild = rightChild;

    // Returning the new node created
    return new;
}