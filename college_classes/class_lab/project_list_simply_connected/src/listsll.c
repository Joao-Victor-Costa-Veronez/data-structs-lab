// Importing libraries
#include "listsll.h"

// Function that create a new list of Simplie Linked List
list_SLL *create_list_SLL()
{
    // Getting a space in the memory for the list
    list_SLL *new = (list_SLL *)malloc(sizeof(list_SLL));

    if (new == NULL)
    {
        printf("Fatal error: Failed to allocate memory for list_SLL.\n");
        exit(1);
    }

    // Adding the incial length and inicial pointer
    new->length = 0;
    new->inicial = NULL;

    // Returnng the struct's address of list
    return new;
}

// Function that shows the current list
void show_list_SLL(list_SLL *point_list)
{
    // Showing the size
    printf("Length = %d\n", point_list->length);

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
        // Declaring an auxiliar pointer of the list
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

// Function that inserts a value in the end of the list
void insert_begin_SLL(int value, list_SLL *point_list)
{
    // Creating a new node
    node_SLL *new = create_node_SLL(value, NULL);

    // The next node of the new node, become the current list's inicial node
    new->next = point_list->inicial;

    // The list's incial node become the new node
    point_list->inicial = new;

    // Incrementing the length of the list
    point_list->length++;
}

// Function that returns the inicial value of the list
int obtain_inicial_value_SLL(list_SLL *point_list)
{
    // If the list is empty
    if (point_list->length == 0)
    {
        // Advise that the list is empty
        printf("The list is empty, so there isn't an inicial value.\n");

        // Return 0
        return 0;
    }
    // Else
    else
    {
        // Showing the value
        printf("The incial value of the list is: ");

        // Return the list's incial node value
        return point_list->inicial->value;
    }
}

// Function that returns the last value of the list
int obtain_last_value_SLL(list_SLL *point_list)
{
    // If the list is empty
    if (point_list->length == 0)
    {
        // Advise that the list is empty
        printf("The list is empty, so there isn't a last value.\n");

        // Return 0
        return 0;
    }
    // Else
    else
    {
        // Declaring an auxiliar pointer of the list
        node_SLL *pont_auxiliar = point_list->inicial;

        // While the next node of the auxiliar pointer is different than NULL
        while (pont_auxiliar->next != NULL)
        {
            // The pointer goes to the next position
            pont_auxiliar = pont_auxiliar->next;
        }

        // Showing the value
        printf("The last value of the list is: ");

        // When the auxiliar pointer is pointing to the last node,
        // return the value of this node
        return pont_auxiliar->value;
    }
}

// Function that remove the list's begging node
int remove_begin_SLL(list_SLL *point_list)
{
    // If the list is empty
    if (point_list->length == 0)
    {
        // Advise that the list is empty
        printf("The list is empty, so there isn't a node to be removed.\n");

        // Return 0
        return 0;
    }
    // Else
    else
    {
        // Declaring an auxiliar pointer of the list first node
        node_SLL *point_auxiliar = point_list->inicial;

        // The list's incial node become the second node
        point_list->inicial = point_auxiliar->next;

        // Getting free the first node's memory
        free(point_auxiliar);

        // Showing the message of success
        printf("The first node was removed.\n");

        // Decreasing the length of the list
        point_list->length--;

        // When the auxiliar pointer is pointing to the last node,
        // return the value of this node
        return 1;
    }
}

// Function that cleans up a list
void clean_up_SLL(list_SLL *point_list)
{
    // If the list's empty
    if (point_list->length == 0)
    {
        // Inform that the list is already clean
        printf("The list is alredy clean. Nothing modified.\n");
    }
    // Else
    else
    {
        // Declaring variables
        node_SLL *point_delete = point_list->inicial, *point_next_delete = point_delete->next;

        // While the point next delete is different of NULL
        while (point_next_delete != NULL)
        {
            // Deleting the current point delete
            free(point_delete);

            // The point delete goes to the point delete next
            point_delete = point_next_delete;

            // The point delete next goes to the next node
            point_next_delete = point_next_delete->next;
        }

        // Cleaning the last node
        free(point_delete);

        // Updating the length of the list
        point_list->length = 0;

        // Informing that the list cleaned up
        printf("The list is cleaned up.\n");
    }
}

// Function that deletes a list
void delete_list_SLL(list_SLL **point_point_list)
{
    // Cleaning the list first
    clean_up_SLL(*point_point_list);

    // Freeing the memory of the list using the pointer of the pointer of the list
    free(*point_point_list);

    // Making the pointer of the pointer of the list points to NULL
    *point_point_list = NULL;

    // Informing that the deletion was complete
    printf("The list was deleted successfully.\n\n");
}

int remove_last_SLL(list_SLL *point_list)
{
    // If the list's empty
    if (point_list->length == 0)
    {
        // Advise that the list is empty
        printf("The list is empty, so there isn't a node to be removed.\n");

        // Return 0
        return 0;
    }
    // Else if, the list has just one element
    else if (point_list->length == 1)
    {
        // Getting free the node's memory
        free(point_list->inicial);

        // Making the pointer to the inical value points to NULL
        point_list->inicial == NULL;
    }
    // Else
    else
    {
        // Declaring an auxiliar pointer of the list first node
        node_SLL *point_auxiliar = point_list->inicial;

        // While the point auxiliar isn't the penultime
        while (point_auxiliar->next->next != NULL)
        {
            // The point auxiliar goes to the next node
            point_auxiliar = point_auxiliar->next;
        }

        // Freeing the point auxiliar node's next memory
        free(point_auxiliar->next);

        // Making the point auxiliar node's points to NULL
        point_auxiliar->next = NULL;
    }

    // Showing the message of success
    printf("The last node was removed.\n");

    // Decreasing the length of the list
    point_list->length--;

    // When the auxiliar pointer is pointing to the last node,
    // return the value of this node
    return 1;
}

// Function that changes the first value of a list
int change_inicial_value_SLL(int value, list_SLL *point_list)
{
    // If the list's empty
    if (point_list->length == 0)
    {
        // Inform that the list's empty
        printf("The list's empty, so it's not possible to chenage it's first value. Nothing modified.\n");

        // Return 0
        return 0;
    }
    // Else
    else
    {
        // Changing the value of the first node
        point_list->inicial->value = value;

        // Inform that the action successed
        printf("The inicial value of the list was changed.\n");

        // Return 1
        return 1;
    }
}

// Function that changes the first value of a list
int change_last_value_SLL(int value, list_SLL *point_list)
{
    // If the list's empty
    if (point_list->length == 0)
    {
        // Inform that the list's empty
        printf("The list's empty, so it's not possible to chenage it's last value. Nothing modified.\n");

        // Return 0
        return 0;
    }
    // Else
    else
    {
        // Decalring an auxiliar pointer that points to the first node
        node_SLL *point_auxiliar = point_list->inicial;

        // While the next node of the pointer auxiliar is not NULL
        while (point_auxiliar->next != NULL)
        {
            // The auxiliar pointer goes to the next node
            point_auxiliar = point_auxiliar->next;
        }

        // Changing the value of the last node
        point_auxiliar->value = value;

        // Inform that the action successed
        printf("The last value of the list was changed.\n");

        // Return 1
        return 1;
    }
}

// Function that inserts a node in any position of the list
int insert_value_any_position(int value, list_SLL *point_list, int position)
{
    // If the list is empty
    if ((point_list->length == 0) && (position != 0))
    {
        // Inform that the list's empty
        printf("The list's empty, you can't insert on the submitted position.\n");

        // Return 0
        return 0;
    }
    // Else if, the position is negative
    else if (position < 0)
    {
        // Inform that the submitted position is invalid
        printf("The submitted position is invalid. There isn't negative positions.\n");

        // Return 0
        return 0;
    }
    // Else if, the position is greater than the list's length
    else if (position > point_list->length)
    {
        // Inform that the submitted position is invalid
        printf("The submitted position is invalid. The list has just %d elements.\n", point_list->length);

        // Return 0
        return 0;
    }
    // Else
    else
    {
        // Declaring a new node
        node_SLL *new = create_node_SLL(value, NULL);

        // If the position is 0
        if (position == 0)
        {
            // Inserting in the begging of the list
            insert_begin_SLL(value, point_list);

            // Inform that the action was successed
            printf("The new node was insert on the first position.\n");

            // Return 1
            return 1;
        }
        // Else if the position is equals the list's length
        else if (position == point_list->length)
        {
            // Inserting in the end of the list
            insert_end_SLL(value, point_list);

            // Inform that the action was successed
            printf("The new node was insert on the last position.\n");

            // Return 1
            return 1;
        }
        // Else
        else
        {
            // Declaring an auxiliar point that points to the first node
            node_SLL *point_auxiliar = point_list->inicial;

            // For the auxiliar pointer is not pointing to the before before the wanted position
            for (int i = 0; i < (point_list->length - 1); i++)
            {
            }
        }
    }
}
