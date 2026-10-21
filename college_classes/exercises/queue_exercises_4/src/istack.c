#include "istack.h"

// Function that creats an int pile
iStack *createIStack()
{
    // Getting a space in the memory for the pile
    iStack *new = (iStack *)malloc(sizeof(iStack));

    // If there wasn't enough memory
    if (new == NULL)
    {
        // Inform the user
        printf("Fatal error: Failed to allocate memory for iStack.\n");

        // Exit the function
        exit(1);
    }

    // Adding the incial length and top pointer
    new->length = 0;
    new->top = NULL;

    // Returning the struct's address of pile
    return new;
}

// Function that shows the current pile
void showIStack(iStack *stackPoint)
{
    // Showing the size
    printf("Length = %d\n", stackPoint->length);

    // If the list isn't empty
    if (stackPoint->length != 0)
    {
        // Declaring a auxiliar pointer of the list
        nodeSLL *auxPoint = stackPoint->top;

        // While the auxiliar pointer is different than NULL
        while (auxPoint != NULL)
        {
            // Show the value of the node
            printf("%d -> ", auxPoint->value);

            // The pointer goes to the next position
            auxPoint = auxPoint->next;
        }
    }

    // Showing the end of the list
    printf("NULL\n\n");
}

// Function that returns the top value of the pile
int showTopIStack(iStack *stackPoint)
{
    // If the pile is empty
    if (stackPoint->length == 0)
    {
        // Advise that the pile is empty
        printf("The pile is empty, so there isn't a top value.\n\n");

        // Return 0
        return 0;
    }
    // Else
    else
    {
        // Showing the value
        printf("The top value of the pile is: ");

        // Return the pile's top node value
        return stackPoint->top->value;
    }
}

// Function that inserts a value in the top of the pile
void stackIStack(int value, iStack *stackPoint)
{
    // Creating a new node
    nodeSLL *new = create_node_SLL(value, NULL);

    // The next node of the new node, become the current piles's top node
    new->next = stackPoint->top;

    // The piles's incial node become the new node
    stackPoint->top = new;

    // Incrementing the length of the pile
    stackPoint->length++;
}

// Function that remove the pile's begging node
int unstackIStack(iStack *stackPoint)
{
    // If the pile is empty
    if (stackPoint->length == 0)
    {
        // Advise that the pile is empty
        printf("The pile is empty, so there isn't a node to be removed.\n");

        // Return 0
        return 0;
    }
    // Else
    else
    {
        // Declaring an auxiliar pointer of the pile first node
        nodeSLL *auxPoint = stackPoint->top;

        // The pile's top node become the second node
        stackPoint->top = auxPoint->next;

        // Getting free the first node's memory
        free(auxPoint);

        // Showing the message of success
        printf("The first node was removed.\n");

        // Decreasing the length of the pile
        stackPoint->length--;

        // When the auxiliar pointer is pointing to the last node,
        // return the value of this node
        return 1;
    }
}

// Function that cleans up a pile
void cleanUpIStack(iStack *stackPoint)
{
    // If the pile's empty
    if (stackPoint->length == 0)
    {
        // Inform that the pile is already clean
        printf("The pile is alredy clean. Nothing modified.\n");
    }
    // Else
    else
    {
        // Declaring variables
        nodeSLL *deletePoint = stackPoint->top, *deleteNextPoint = deletePoint->next;

        // While the point next delete is different of NULL
        while (deleteNextPoint != NULL)
        {
            // Deleting the current point delete
            free(deletePoint);

            // The point delete goes to the point delete next
            deletePoint = deleteNextPoint;

            // The point delete next goes to the next node
            deleteNextPoint = deleteNextPoint->next;
        }

        // Cleaning the last node
        free(deletePoint);

        // Updating the length of the pile
        stackPoint->length = 0;

        // Updating the pile's inicial pointer
        stackPoint->top = NULL;

        // Informing that the pile cleaned up
        printf("The pile is cleaned up.\n");
    }
}

// Function that deletes a pile
void deleteIStack(iStack **stackPointPoint)
{
    // Cleaning the list first
    cleanUpIStack(*stackPointPoint);

    // Freeing the memory of the pile using the pointer of the pointer of the pile
    free(*stackPointPoint);

    // Making the pointer of the pointer of the pile points to NULL
    *stackPointPoint = NULL;

    // Informing that the deletion was complete
    printf("The pile was deleted successfully.\n\n");
}