#include "priorityqueue.h"

// Function that creates a new list
priorityQueue *createPriorityQueue()
{
    // Creating a new list
    priorityQueue *new = (priorityQueue *)malloc(sizeof(priorityQueue));
    // Checking if the list was created
    if (new == NULL)
    {
        // Informing the error and exiting
        printf("Fatal error: Falied to allocate memory for priorityQueue.\n");
        exit(1);
    }

    // Default configuration of a list
    new->length = 0;
    new->inicial = NULL;
    new->final = NULL;

    // Returning the list's address
    return new;
}

// Function that cleans up a list
void cleanUpPriorityQueue(priorityQueue *queuePoint)
{
    // If the list's empty
    if (queuePoint->length > 0)
    {
        // While the list's inicial pointer isn't the list's final pointer
        while (queuePoint->inicial != queuePoint->final)
        {
            // Making th list's inical goes to the next node
            queuePoint->inicial = queuePoint->inicial->next;

            // Freeing the list's previous inicial node
            free(queuePoint->inicial->previous);
        }
        // Freeing the list's inicial pointer
        free(queuePoint->inicial);

        // Making the list receive it's default values
        queuePoint->inicial = NULL;
        queuePoint->final = NULL;
        queuePoint->length = 0;
    }
}

// Function that destroys a list
void destroyPriorityQueue(priorityQueue **queuePointPoint)
{
    // Cleanning up the list
    cleanUpPriorityQueue(*queuePointPoint);

    // Freeing the list's memory
    free(*queuePointPoint);

    // Making the list's pointer points to NULL
    *queuePointPoint = NULL;
}

// Function that shows a list
void showPriorityQueue(priorityQueue *queuePoint)
{
    // Showing the list's length
    printf("Length: %d\n", queuePoint->length);

    // If the list's empty
    if (queuePoint->length == 0)
    {
        // Just print NULL
        printf("NULL\n\n");
    }
    // Else
    else
    {
        // Creating an auxiliar pointer
        nodeDLL *auxPoint = queuePoint->inicial;

        // Showing the first NULL
        printf("NULL <- ");
        // While the auxiliar pointer isn't at the list's final pointer
        while (auxPoint != queuePoint->final)
        {
            // Show the element
            printf("%d <-> ", auxPoint->value);

            // Go to the next element
            auxPoint = auxPoint->next;
        }
        // Showing the last element, and the last NULL
        printf("%d -> NULL\n\n", auxPoint->value);
    }
}

// Function that inserts in the list's end
void insertingNodeEndDLL(priorityQueue *queuePoint, int value)
{
    // Creating a new node
    nodeDLL *new = createNodeDLL(value, queuePoint->final, NULL);

    // If the list's empty
    if (queuePoint->length == 0)
    {
        // Making the list's inicial pointer points to the new node
        queuePoint->inicial = new;
    }
    // Else
    else
    {
        // Making the list's next final pointer points to the new node
        queuePoint->final->next = new;
    }

    // Making the list's final pointer points to the new node
    queuePoint->final = new;

    // Increasing the list's length
    queuePoint->length++;
}

// Function that removes the list's beginning
int removeNodeBeginnigDLL(priorityQueue *queuePoint)
{
    // If the list's empty
    if (queuePoint->length == 0)
    {
        // Informing the user
        printf("The list's empty, there isn't a node to be removed. No changes.\n\n");

        // Return 0
        return 0;
    }
    // Else if, the list has just one element
    else if (queuePoint->length == 1)
    {
        // Freeing the list's inical node
        free(queuePoint->inicial);

        // Making the both list's pointers point to NULL
        queuePoint->inicial = NULL;
        queuePoint->final = NULL;

        // Reducing the list's length
        queuePoint->length--;

        // Return 1
        return 1;
    }
    // Else
    else
    {
        // Moving the list's inicial pointer to the next node
        queuePoint->inicial = queuePoint->inicial->next;

        // Freeing the old inicial node
        free(queuePoint->inicial->previous);

        // Making the new inicial node's previous point to NULL
        queuePoint->inicial->previous = NULL;

        // Reducing the list's length
        queuePoint->length--;

        // Return 1
        return 1;
    }
}

// Function that obtains the list's inicial value
int obtainFinalValueDLL(priorityQueue *queuePoint)
{
    // If the list's empty
    if (queuePoint->length == 0)
    {
        // Informing the user
        printf("The list's empty, there isn't a node to be obtained.\n\n");

        // Return 0
        return 0;
    }
    // Else
    else
    {
        // Return the list's final value
        return queuePoint->final->value;
    }
}
