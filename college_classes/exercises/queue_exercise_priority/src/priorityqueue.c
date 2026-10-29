#include "priorityqueue.h"

// Function that creates a new priority queue
priorityQueue *createPriorityQueue()
{
    // Creating a new priority queue
    priorityQueue *new = (priorityQueue *)malloc(sizeof(priorityQueue));

    // Checking if the priority queue was created
    if (new == NULL)
    {
        // Informing the error and exiting
        printf("Fatal error: Falied to allocate memory for priorityQueue.\n");
        exit(1);
    }

    // Default configuration of a priority queue
    new->length = 0;
    new->inicial = NULL;
    new->final = NULL;

    // Returning the priority queue's address
    return new;
}

// Function that cleans up a priority queue
void cleanUpPriorityQueue(priorityQueue *queuePoint)
{
    // If the priority queue's empty
    if (queuePoint->length > 0)
    {
        // While the priority queue's inicial pointer isn't the priority queue's final pointer
        while (queuePoint->inicial != queuePoint->final)
        {
            // Making th priority queue's inical goes to the next node
            queuePoint->inicial = queuePoint->inicial->next;

            // Freeing the priority queue's previous inicial node
            free(queuePoint->inicial->previous);
        }
        // Freeing the priority queue's inicial pointer
        free(queuePoint->inicial);

        // Making the priority queue receive it's default values
        queuePoint->inicial = NULL;
        queuePoint->final = NULL;
        queuePoint->length = 0;
    }
}

// Function that destroys a priority queue
void destroyPriorityQueue(priorityQueue **queuePointPoint)
{
    // Cleanning up the priority queue
    cleanUpPriorityQueue(*queuePointPoint);

    // Freeing the priority queue's memory
    free(*queuePointPoint);

    // Making the priority queue's pointer points to NULL
    *queuePointPoint = NULL;
}

// Function that shows a priority queue
void showPriorityQueue(priorityQueue *queuePoint)
{
    // Showing the priority queue's length
    printf("Length: %d\n", queuePoint->length);

    // If the priority queue's empty
    if (queuePoint->length == 0)
    {
        // Just print NULL
        printf("NULL\n\n");
    }
    // Else
    else
    {
        // Creating an auxiliar pointer
        nodePriority *auxPoint = queuePoint->inicial;

        // Showing the first NULL
        printf("NULL <- (Next) %c", nextPriorityQueue(queuePoint));
        // While the auxiliar pointer isn't at the priority queue's final pointer
        while (auxPoint != queuePoint->final)
        {
            for (int i = 0; i < (strlen(auxPoint->value) - 1); i++)
            {
                printf(" <-> %c <->", auxPoint->value[i]);
            }

            // Go to the next element
            auxPoint = auxPoint->next;
        }
        // Showing the last element, and the last NULL
        printf(" %c -> NULL\n\n", auxPoint->value[strlen(auxPoint->value)]);
    }
}

// Function that inserts in the priority queue's end
void queuePriorityQueue(char *value, int priority, priorityQueue *queuePoint)
{
    // Creating a new node
    nodePriority *new = createNodePriority(value, priority, NULL, queuePoint->final);

    // If the priority queue's empty
    if (queuePoint->length == 0)
    {
        // Making the priority queue's inicial pointer points to the new node
        queuePoint->inicial = new;
    }
    // Else
    else
    {
        // Making the priority queue's next final pointer points to the new node
        queuePoint->final->next = new;
    }

    // Making the priority queue's final pointer points to the new node
    queuePoint->final = new;

    // Increasing the priority queue's length
    queuePoint->length++;
}

// Function that removes the priority queue's beginning
int unqueuePriorityQueue(priorityQueue *queuePoint)
{
    // If the priority queue's empty
    if (queuePoint->length == 0)
    {
        // Informing the user
        printf("The priority queue's empty, there isn't a node to be removed. No changes.\n\n");

        // Return 0
        return 0;
    }
    // Else if, the priority queue has just one element
    else if (queuePoint->length == 1)
    {
        // Freeing the priority queue's inical node
        free(queuePoint->inicial);

        // Making the both priority queue's pointers point to NULL
        queuePoint->inicial = NULL;
        queuePoint->final = NULL;

        // Reducing the priority queue's length
        queuePoint->length--;

        // Return 1
        return 1;
    }
    // Else
    else
    {
        // Moving the priority queue's inicial pointer to the next node
        queuePoint->inicial = queuePoint->inicial->next;

        // Freeing the old inicial node
        free(queuePoint->inicial->previous);

        // Making the new inicial node's previous point to NULL
        queuePoint->inicial->previous = NULL;

        // Reducing the priority queue's length
        queuePoint->length--;

        // Return 1
        return 1;
    }
}

// Function that obtains the queuePoint's inicial value
char nextPriorityQueue(priorityQueue *queuePoint)
{
    // If the queuePoint's empty
    if (queuePoint->length == 0)
    {
        // Informing the user
        printf("The queue's empty, there isn't a node to be obtained.\n\n");

        // Return 0
        return 0;
    }
    // Else
    else
    {
        // Return the queuePoint's inicial value
        return *queuePoint->inicial->value;
    }
}
