// Including libraries
#include "listdll.h"

// Function that creates a new list
listDLL *createListDLL()
{
    // Creating a new list
    listDLL *new = (listDLL *)malloc(sizeof(listDLL));
    // Checking if the list was created
    if (new == NULL)
    {
        // Informing the error and exiting
        printf("Fatal error: Falied to allocate memory for listDLL.\n");
        exit(1);
    }

    // Default configuration of a list
    new->length = 0;
    new->inicial = NULL;
    new->final = NULL;

    // Returning the list's address
    return new;
}

// Function that shows a list
void showList(listDLL *listPoint)
{
    // Showing the list's length
    printf("Length: %d\n", listPoint->length);

    // If the list's empty
    if (listPoint->length == 0)
    {
        // Just print NULL
        printf("NULL\n\n");
    }
    // Else
    else
    {
        // Creating an auxiliar pointer
        nodeDLL *auxPoint = listPoint->inicial;

        // Showing the first NULL
        printf("NULL <- ");
        // While the auxiliar pointer isn't at the list's final pointer
        while (auxPoint != listPoint->final)
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

// Function that shows a list backwards
void showListBackwards(listDLL *listPoint)
{
    // Showing the list's length
    printf("Length: %d\n", listPoint->length);

    // If the list's empty
    if (listPoint->length == 0)
    {
        // Just print NULL
        printf("NULL\n\n");
    }
    // Else
    else
    {
        // Creating an auxiliar pointer
        nodeDLL *auxPoint = listPoint->final;

        // Showing the last NULL
        printf("NULL <- ");
        // While the auxiliar pointer isn't at the list's inicial pointer
        while (auxPoint != listPoint->inicial)
        {
            // Show the element
            printf("%d <-> ", auxPoint->value);

            // Go to the previous element
            auxPoint = auxPoint->previous;
        }
        // Showing the first element, and the first NULL
        printf("%d -> NULL\n\n", auxPoint->value);
    }
}

// Function that inserts in the list's beginnig
void insertNodeBeginnig(listDLL *listPoint, int value)
{
    // Creating a new node
    nodeDLL *new = createNodeDLL(value, NULL, listPoint->inicial);

    // If the list's empty
    if (listPoint->length == 0)
    {
        // Making the list's final pointer points to the new node
        listPoint->final = new;
    }
    // Else
    else
    {
        // Making the old list's previous inicial node points to the new node
        listPoint->inicial->previous = new;
    }

    // Making the list's inicial pointer points to the new node
    listPoint->inicial = new;

    // Increasing the list's length
    listPoint->length++;
}

// Function that inserts in the list's end
void insertingNodeEnd(listDLL *listPoint, int value)
{
    // Creating a new node
    nodeDLL *new = createNodeDLL(value, listPoint->final, NULL);

    // If the list's empty
    if (listPoint->length == 0)
    {
        // Making the list's inicial pointer points to the new node
        listPoint->inicial = new;
    }
    // Else
    else
    {
        // Making the list's next final pointer points to the new node
        listPoint->final->next = new;
    }

    // Making the list's final pointer points to the new node
    listPoint->final = new;

    // Increasing the list's length
    listPoint->length++;
}

// Function that cleans up a list
void cleanUpListDLL(listDLL *listPoint)
{
    // If the list's empty
    if (listPoint->length > 0)
    {
        // While the list's inicial pointer isn't the list's final pointer
        while (listPoint->inicial != listPoint->final)
        {
            // Making th list's inical goes to the next node
            listPoint->inicial = listPoint->inicial->next;

            // Freeing the list's previous inicial node 
            free(listPoint->inicial->previous);
        }
        // Freeing the list's inicial pointer
        free(listPoint->inicial);

        // Making the list receive it's default values
        listPoint->inicial = NULL;
        listPoint->final = NULL;
        listPoint->length = 0;
    }
}

void destroyListDLL(listDLL **listPointPoint)
{
    cleanUpListDLL(*listPointPoint);

    free(*listPointPoint);

    *listPointPoint = NULL;
}

// Function that removes the list's beginning
int removeNodeBeginnig(listDLL *listPoint)
{
    // If the list's empty
    if (listPoint->length == 0)
    {
        // Informing the user
        printf("The list's empty, there isn't a node to be removed. No changes.\n\n");

        // Return 0
        return 0;
    }
    // Else if, the list has just one element
    else if (listPoint->length == 1)
    {
        // Freeing the list's inical node
        free(listPoint->inicial);

        // Making the both list's pointers point to NULL
        listPoint->inicial = NULL;
        listPoint->final = NULL;

        // Reducing the list's length
        listPoint->length--;

        // Return 1
        return 1;
    }
    // Else
    else
    {
        // Moving the list's inicial pointer to the next node
        listPoint->inicial = listPoint->inicial->next;

        // Freeing the old inicial node
        free(listPoint->inicial->previous);

        // Making the new inicial node's previous point to NULL
        listPoint->inicial->previous = NULL;

        // Reducing the list's length
        listPoint->length--;

        // Return 1
        return 1;
    }
}

// Function that removes the list's end
int removeNodeEnd(listDLL *listPoint)
{
    // If the list's empty
    if (listPoint->length == 0)
    {
        // Informing the user
        printf("The list's empty, there isn't a node to be removed. No changes.\n\n");

        // Return 0
        return 0;
    }
    // Else if, the list has just one element
    else if (listPoint->length == 1)
    {
        // Freeing the list's inical node
        free(listPoint->final);

        // Making the both list's pointers point to NULL
        listPoint->inicial = NULL;
        listPoint->final = NULL;

        // Reducing the list's length
        listPoint->length--;

        // Return 1
        return 1;
    }
    // Else
    else
    {
        // Moving the list's final pointer to the previous node
        listPoint->final = listPoint->final->previous;

        // Freeing the old final node
        free(listPoint->final->next);

        // Making the new final node's next point to NULL
        listPoint->final->next = NULL;

        // Reducing the list's length
        listPoint->length--;

        // Return 1
        return 1;
    }
}