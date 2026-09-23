#include "nodedll.h"

nodeDLL *createNewDLL(int value, nodeDLL *previous, nodeDLL *next)
{
    nodeDLL *new = (nodeDLL *)malloc(sizeof(nodeDLL));
    if (new == NULL)
    {
        printf("Fatal error: Falied to allocate memory for nodeDLL.\n");
        exit(1);
    }

    new->value = 0;
    new->previous = NULL;
    new->next = NULL;

    return new;
}