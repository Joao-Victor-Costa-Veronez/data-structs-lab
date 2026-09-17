// Immporting libraries
#include "nodesll.h"

// Function that creates a node
node_sll *create_node_SLL(int value, node_sll *next)
{
    // Getting a space in the memory for the node
    node_sll *new = (node_sll *)malloc(sizeof(node_sll));

    if (new == NULL)
    {
        printf("Fatal error: Failed to allocate memory for node_sll.\n");
        exit(1);
    }

    // Addinng the value of the new node
    new->value = value;

    // Adding the pointer to the next node
    new->next = next;

    // Returning the struct's address of the new node
    return new;
}