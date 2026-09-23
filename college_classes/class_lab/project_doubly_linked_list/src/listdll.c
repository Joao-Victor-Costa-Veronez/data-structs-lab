// Including libraries
#include "listdll.h"

listDLL *createListDLL()
{
    listDLL *new = (listDLL *)malloc(sizeof(listDLL));
    if (new == NULL)
    {
        printf("Fatal error: Falied to allocate memory for listDLL.\n");
        exit(1);
    }
    new->length = 0;
    new->inicial = NULL;
    new->final = NULL;

    return new;
}

void showList(listDLL *listPoint)
{
    printf("Length: %d\n", listPoint->length);

    if (listPoint->length == 0)
    {
        printf("NULL\n\n");
    }
    else
    {
        nodeDLL *auxPoint = listPoint->inicial;

        printf("NULL <- ");
        while (auxPoint != listPoint->final)
        {
            printf("%d <-> ", auxPoint->value);

            auxPoint = auxPoint->next;
        }
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
void destroyListDLL(listDLL *lisPoint)
{
    cleanUpListDLL(lisPoint);

    free(lisPoint);
}