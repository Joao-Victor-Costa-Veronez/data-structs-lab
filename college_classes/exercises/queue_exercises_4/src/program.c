/*
DATE: 10/21/2026
*/

// Importing libraries
#include <string.h>
#include "listsll.h"
#include "istack.h"
#include "iqueue.h"

// Declaring functions
void invertIQueue(IQueue *queuePoint);

// Main function
int main()
{
    IQueue *queue1 = createIQueue();

    queueIQueue(1, queue1);
    queueIQueue(2, queue1);
    queueIQueue(3, queue1);

    showIQueue(queue1);

    invertIQueue(queue1);

    showIQueue(queue1);

    deleteIQueue(&queue1);

    return 0;
}

// Function that inverts a queue
void invertIQueue(IQueue *queuePoint)
{
    // Declaring variables
    iStack *stack = createIStack();

    // For each element
    while (queuePoint->length > 0)
    {
        // Get the element in the queue, and put in the stack
        stackIStack(nextIQueue(queuePoint), stack);
        unqueueIQueue(queuePoint);
    }

    // For each element
    while (stack->length > 0)
    {
        // Get the element in the stack, and put in the queue
        queueIQueue(showTopIStack(stack), queuePoint);
        unstackIStack(stack);
    }

    // Delete stack
    deleteIStack(&stack);
}