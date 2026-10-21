// Immporting libraries
#include "nodesll.h"

// Function that creates a node
nodeSLL *create_node_SLL(int value, nodeSLL *next)
{
    // Getting a space in the memory for the node
    nodeSLL *new = (nodeSLL *)malloc(sizeof(nodeSLL));

    if (new == NULL)
    {
        printf("Fatal error: Failed to allocate memory for node_SLL.\n");
        exit(1);
    }

    // Addinng the value of the new node
    new->value = value;

    // Adding the pointer to the next node
    new->next = next;

    // Returning the struct's address of the new node
    return new;
}