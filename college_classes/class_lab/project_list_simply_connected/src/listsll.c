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
    // Creating a new node
    node_SLL *new = (value, NULL);

    // If there is justo one element
    if (list->length == 0)
    {
        list->inicial = new;
    }
    // Else
    else
    {
        node_SLL *auxiliar = list->inicial;

        while (auxiliar->next != NULL)
        {
            auxiliar = auxiliar->next = new;
        }

        auxiliar->next = new;
    }

    // Incrementing the length of the list
    list->length++;
}