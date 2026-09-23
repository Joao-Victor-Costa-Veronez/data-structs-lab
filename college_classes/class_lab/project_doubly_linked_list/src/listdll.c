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

    /*
    printf("Tamanho = %d, NULL", listPoint->length);
    if (listPoint->length > 0)
    {
        printf(" <- ");
        nodeDLL *aux = listPoint->inicial;
        while (aux != NULL)
        {
            printf("%d", aux->value);
            aux = aux->next;
            if (aux != NULL)
            {
                printf(" <-> ");
            }
        }
        printf(" -> NULL");
    }
    printf("\n");
    */
}

void insertNodeBegginig(listDLL *listPoint, int value)
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
