// Including libraries
#include "nodedll.h"

// Function that creates a new node
nodeDLL *createNodeDLL(int value, nodeDLL *previous, nodeDLL *next)
{
    // Creating a new node
    nodeDLL *new = (nodeDLL *)malloc(sizeof(nodeDLL));
    // Checking if the node was created
    if (new == NULL)
    {
        // Informing the error and exiting
        printf("Fatal error: Falied to allocate memory for nodeDLL.\n");
        exit(1);
    }

    // Default configuration of a node
    new->value = value;
    new->previous = previous;
    new->next = next;

    // Returning the node's address
    return new;
}