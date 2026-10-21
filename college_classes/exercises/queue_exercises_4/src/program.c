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

    showIQueue(queue1);

    invertIQueue(queue1);

    showIQueue(queue1);

    return 0;
}

// Function that inverts a queue
void invertIQueue(IQueue *queuePoint)
{
    // Declaring variables
    iStack *stack = createIStack();

    // For each element
    for (int i = 0; i < queuePoint->length; i++)
    {
        // Get the element in the queue, and put in the stack
        stackIStack(unqueueIQueue(queuePoint), stack);
    }

    // For each element
    for (int i = 0; i < stack->length; i++)
    {
        // Get the element in the stack, and put in the queue
        queueIQueue(unStackIStack(stack), queuePoint);
    }

    // Delete stack
    deleteIStack(stack);
}