// Immporting libraries
#include "nodesll.h"

// Function that creates a node
node_SLL *create_node_SLL(int value, node_SLL *next)
{
    // Getting a space in the memory for the node
    node_SLL *new = (node_SLL *)malloc(sizeof(node_SLL));

    // Addinng the value of the new node
    new->value = value;

    // Adding the pointer to the next node
    new->next = next;

    // Returning the struct's address of the new node
    return new;
}