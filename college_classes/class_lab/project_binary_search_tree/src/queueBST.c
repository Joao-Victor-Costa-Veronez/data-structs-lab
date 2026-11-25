#include "queueBST.h"

QueueBST *createQueueBST()
{
    QueueBST *new = (QueueBST *)malloc(sizeof(QueueBST));
    if (new == NULL) // Error allocating memory
    {
        printf("Fatal error: Failed to allocate memory for QueueBST.\n");
        exit(1);
    }
    new->size = 0;
    new->front = NULL;
    new->rear = NULL;
    return new;
}

void clearQueueBST(QueueBST *queue)
{
    if (queue->size > 0)
    {
        QueueNodeBST *aux1, *aux2;
        aux1 = queue->front;
        aux2 = aux1->next;
        while (aux2 != NULL)
        {
            free(aux1);
            aux1 = aux2;
            aux2 = aux2->next;
        }
        free(aux1);
        queue->size = 0;
        queue->front = NULL;
        queue->rear = NULL;
    }
}

void destroyQueueBST(QueueBST **queuePointer)
{
    clearQueueBST(*queuePointer);
    free(*queuePointer);
    *queuePointer = NULL;
}

// Size = 0, Empty
// Size = 5, 6(F) -> 12 -> 4 -> 7 -> 2 -> NULL
void showQueueBST(QueueBST *queue)
{
    printf("Size = %d, ", queue->size);
    if (queue->size == 0) // EMPTY
    {
        printf("Empty\n");
    }
    else // 1 OR MORE ELEMENTS
    {
        QueueNodeBST *aux = queue->front;
        printf("%d(F) -> ", aux->node->key);
        aux = aux->next;
        while (aux != NULL)
        {
            printf("%d -> ", aux->node->key);
            aux = aux->next;
        }
        printf("NULL\n");
    }
}

void enqueueQueueBST(nodeBST *node, QueueBST *queue)
{
    QueueNodeBST *new = createQueueNodeBST(node, NULL);
    if (queue->size == 0) // queue->front == NULL
    {
        queue->front = new;
    }
    else // 1 OR MORE ELEMENTS
    {
        queue->rear->next = new;
    }
    queue->rear = new;
    queue->size++;
}

int *dequeueQueueBST(QueueBST *queue)
{
    if (queue->size == 0)
    {
        printf("Cannot remove from an empty queue\n");
        return 0;
    }
    else
    {
        QueueNodeBST *aux = queue->front;
        queue->front = aux->next;
        free(aux);
        queue->size--;
        if (queue->size == 0)
        {
            queue->rear = NULL;
        }
        return 1;
    }
}

nodeBST *peekQueueBST(QueueBST *queue)
{
    if (queue->size == 0)
    {
        printf("Cannot get the next item from an empty queue\n");
        return 0;
    }
    else
    {
        return queue->front->node;
    }
}