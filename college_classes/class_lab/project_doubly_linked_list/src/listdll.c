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