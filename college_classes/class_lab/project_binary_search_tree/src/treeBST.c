// Importing libraries
#include "treeBST.h"

// Function that creates a new BST
BST *createTreeBST()
{
    // Allocing the memory
    BST *new = (BST *)malloc(sizeof(BST));

    // If there was an error
    if (new == NULL)
    {
        // Inform and exit
        printf("Fatal error: Failed to allocate memory to BST.\n");
        exit(1);
    }
    // Putting default values in the variables
    new->root = NULL;
    new->nodesQuantity = 0;

    // Returning the new tree created
    return new;
}

// Function that inserts a value in the BST
void insertBST(int key, BST *BSTpoint)
{

}