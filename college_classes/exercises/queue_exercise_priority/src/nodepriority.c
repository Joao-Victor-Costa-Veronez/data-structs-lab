// Including libraries
#include "priorityqueue.h"

// Function that creates a new node
nodePriority *createnodePriority(char *value, int priority, nodePriority *next, nodePriority *previous)
{
    // Creating a new node
    nodePriority *new = (nodePriority *)malloc(sizeof(nodePriority));
    // Checking if the node was created
    if (new == NULL)
    {
        // Informing the error and exiting
        printf("Fatal error: Falied to allocate memory for nodePriority.\n");
        exit(1);
    }

    // Default configuration of a node
    new->next = next;
    new->previous = previous;
    new->priority = priority;
    strcpy(new->value, value);

    // Returning the node's address
    return new;
}