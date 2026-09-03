// Importing libraries
#include "listsll.h"

// Function that create a new list of Simplie Linked List
list_SLL *create_list_SLL()
{
    // Getting a space in the memory for the node
    list_SLL *new = (list_SLL *)malloc(sizeof(list_SLL));

    // Adding the incial length and inicial pointer
    new->length = 0;
    new->inicial = NULL;

    // Returnng the struct's address of list
    return new;
}

// Function that inserts a value in the end of the list
void insert_end_SLL(int value, list_SLL *point_list)
{
    // Creating a new node
    node_SLL *new = create_node_SLL(value, NULL);

    // If there is just one element
    if (point_list->length == 0)
    {
        // Make the inicial pointer of the list point to the node
        point_list->inicial = new;
    }
    // Else
    else
    {
        // Declaring a auxiliar pointer of the list
        node_SLL *pont_auxiliar = point_list->inicial;

        // While the next node of the auxiliar pointer is different than NULL
        while (pont_auxiliar->next != NULL)
        {
            // The pointer goes to the next position
            pont_auxiliar = pont_auxiliar->next;
        }

        // When the auxiliar pointer is pointing to the last node,
        // make the next node address be the address of the new node
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
        // Declaring a auxiliar pointer of the list
        node_SLL *point_auxiliar = point_list->inicial;

        // While the auxiliar pointer is different than NULL
        while (point_auxiliar != NULL)
        {
            // Show the value of the node
            printf("%d -> ", point_auxiliar->value);

            // The pointer goes to the next position
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
    node_SLL *new = create_node_SLL(value, NULL);

    // If there is just one element
    if (point_list->length == 0)
    {
        // Make the inicial pointer of the list point to the node
        point_list->inicial = new;
    }
    // Else
    else
    {
        // The next node of the new node, become the current list's inicial node
        new->next = point_list->inicial;

        // The list's incial node become the new node
        point_list->inicial = new;
    }

    // Incrementing the length of the list
    point_list->length++;
}