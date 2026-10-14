#include "ipile.h"

iPile *createIPile ()
{
    // Getting a space in the memory for the list
    iPile *new = (iPile *)malloc(sizeof(iPile));

    if (new == NULL)
    {
        printf("Fatal error: Failed to allocate memory for iPile.\n");
        exit(1);
    }

    // Adding the incial length and top pointer
    new->length = 0;
    new->top = NULL;

    // Returning the struct's address of pile
    return new;
}