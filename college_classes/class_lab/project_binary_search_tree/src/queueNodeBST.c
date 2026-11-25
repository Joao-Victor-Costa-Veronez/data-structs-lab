#include "queueNodeBST.h"

QueueNodeBST *createQueueNodeBST(nodeBST *node, QueueNodeBST *next)
{
    QueueNodeBST *new = (QueueNodeBST *)malloc(sizeof(QueueNodeBST));
    if (new == NULL)   // Error allocating memory
    {
        printf("Fatal error: Failed to allocate memory for QueueNodeBST.\n");
        exit(1);
    }
    new->node = node;
    new->next = next;
    return new;
}