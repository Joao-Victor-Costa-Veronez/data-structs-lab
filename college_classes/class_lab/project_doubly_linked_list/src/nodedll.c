#include "nodedll.h"

nodeDLL *createNodeDLL(int value, nodeDLL *previous, nodeDLL *next)
{
    nodeDLL *new = (nodeDLL *)malloc(sizeof(nodeDLL));
    if (new == NULL)
    {
        printf("Fatal error: Falied to allocate memory for nodeDLL.\n");
        exit(1);
    }

    new->value = value;
    new->previous = previous;
    new->next = next;

    return new;
}