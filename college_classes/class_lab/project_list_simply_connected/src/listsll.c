#include "listsll.h"

list_SLL *create_list_SLL()
{
    list_SLL *new = (list_SLL *)malloc(sizeof(list_SLL));
    new->inicial = 0;
    new->inicial = NULL;

    return new;
}

void insert_end_SLL(int value, list_SLL *list)
{
    if (list->length == 0)
    {
        node_SLL *new = (value, NULL);
        list->inicial = new;
        list->length++;
    }
}