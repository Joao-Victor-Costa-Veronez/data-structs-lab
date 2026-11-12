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
void insertBST(int key, BST *BSTPoint)
{
    // Creating a new node
    nodeBST *new = createNodeBST(key, NULL, NULL);

    // If the BST it's empty
    if (BSTPoint->nodesQuantity == 0)
    {
        // Make the new node the BST's root
        BSTPoint->root = new;
    }
    // Else
    else
    {
        // Declaring auxiliar pointers
        nodeBST *aux = BSTPoint->root;
        nodeBST *auxFather = NULL;

        // While aux is different NULL
        while (aux != NULL)
        {
            // Aux father goes to aux
            auxFather = aux;

            // If the key is lower than the node
            if (key < aux->key)
            {
                // Go to the left child
                aux = aux->leftChild;
            }
            // Else if, the key is greater than the node
            else if (key > aux->key)
            {
                // Go to the right child
                aux = aux->rightChild;
            }
            // Else
            else
            {
                // Inform that the user can't use a key that is already in the BST
                printf("It's not allowed to insert values that are already in the tree.\n");
                exit(1);
            }
        }

        // If the key is lower than the node
        if (key < auxFather->key)
        {
            // The new node goes to the left
            auxFather->leftChild = new;
        }
        // Else
        else
        {
            // The new node goes to the right
            auxFather->rightChild = new;
        }
    }

    // Increasing the quantity
    BSTPoint->nodesQuantity++;
}