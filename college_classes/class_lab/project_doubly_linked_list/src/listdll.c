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
        // Showing th last element, and the last NULL 
        printf("%d -> NULL\n\n", auxPoint->value);
    }
}

void showListBackwards(listDLL *listPoint)
{
    printf("Length: %d\n", listPoint->length);

    if (listPoint->length == 0)
    {
        printf("NULL\n\n");
    }
    else
    {
        nodeDLL *auxPoint = listPoint->final;

        printf("NULL <- ");
        while (auxPoint != listPoint->inicial)
        {
            printf("%d <-> ", auxPoint->value);

            auxPoint = auxPoint->previous;
        }
        printf("%d -> NULL\n\n", auxPoint->value);
    }
}

void insertNodeBeginnig(listDLL *listPoint, int value)
{
    nodeDLL *new = createNodeDLL(value, NULL, listPoint->inicial);

    if (listPoint->length == 0)
    {
        listPoint->final = new;
    }
    else
    {
        listPoint->inicial->previous = new;
    }

    listPoint->inicial = new;
    listPoint->length++;
}

void insertingNodeEnd(listDLL *listPoint, int value)
{
    nodeDLL *new = createNodeDLL(value, listPoint->final, NULL);

    if (listPoint->length == 0)
    {
        listPoint->inicial = new;
    }
    else
    {
        listPoint->final->next = new;
    }

    listPoint->final = new;
    listPoint->length++;
}

void cleanUpListDLL(listDLL *listPoint)
{
    if (listPoint->length > 0)
    {
        while (listPoint->inicial != listPoint->final)
        {
            listPoint->inicial = listPoint->inicial->next;
            free(listPoint->inicial->previous);
        }
        free(listPoint->inicial);

        listPoint->inicial = NULL;
        listPoint->final = NULL;
        listPoint->length = 0;
    }
}

void destroyListDLL(listDLL **listPointPoint)
{
    cleanUpListDLL(*listPointPoint);

    free(*listPointPoint);
}
