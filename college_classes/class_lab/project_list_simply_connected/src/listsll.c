#include "listsll.h"

list_SLL *create_list_SLL()
{
    list_SLL *new = (list_SLL *)malloc(sizeof(list_SLL));
    new->inicial = 0;
    new->inicial = NULL;

    return new;
}

// Function that inserts a value in the end of the list
void insert_end_SLL(int value, list_SLL *point_list)
{
    // Creating a new node
    node_SLL *new = create_node_LSC(value, NULL);

    // If there is just one element
    if (point_list->length == 0)
    {
        point_list->inicial = new;
    }
    // Else
    else
    {
        node_SLL *pont_auxiliar = point_list->inicial;

        while (pont_auxiliar->next != NULL)
        {
            pont_auxiliar = pont_auxiliar->next;
        }

        pont_auxiliar->next = new;
    }

    // Incrementing the length of the list
    point_list->length++;
}

// Function that shows the current list
void show_list_SLL(list_SLL *point_list)
{
    // Showing the size
    printf("\nLength = %d\n", point_list->length);

    // If the list isn't empty
    if (point_list->length != 0)
    {
        node_SLL *point_auxiliar = point_list->inicial;

        while (point_auxiliar != NULL)
        {
            printf("%d -> ", point_auxiliar->value);
            point_auxiliar = point_auxiliar->next;
        }
    }

    // Showing the end of the list
    printf("NULL\n\n");
}

// Function that inserts a value in the end of the list
void insert_begin_SLL(int value, list_SLL *point_list)
{
    // Creating a new node
    node_SLL *new = create_node_LSC(value, NULL);

    // If there is just one element
    if (point_list->length == 0)
    {
        point_list->inicial = new;
    }
    // Else
    else
    {        
        new->next = point_list->inicial;
        point_list->inicial = new;
    }

    // Incrementing the length of the list
    point_list->length++;
}