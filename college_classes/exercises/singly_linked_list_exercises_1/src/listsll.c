// Importing libraries
#include "listsll.h"

// Function that create a new list of Singly Linked List
list_sll *create_list_sll()
{
    // Getting a space in the memory for the list
    list_sll *new = (list_sll *)malloc(sizeof(list_sll));

    if (new == NULL)
    {
        printf("Fatal error: Failed to allocate memory for list_sll.\n");
        exit(1);
    }

    // Adding the incial length, inicial and end pointer
    new->length = 0;
    new->inicial = NULL;
    new->final = NULL;

    // Returning the struct's address of list
    return new;
}

// Function that shows the current list
void show_list_sll(list_sll *point_list)
{
    // Showing the size
    printf("Length = %d\n", point_list->length);

    // If the list isn't empty
    if (point_list->length != 0)
    {
        // Declaring an auxiliar pointer of the list
        node_sll *point_auxiliar = point_list->inicial;

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
void insert_begin_sll(int value, list_sll *point_list)
{
    // Creating a new node
    node_sll *new = create_node_sll(value, NULL);

    // If the list's empty
    if (point_list->length == 0)
    {
        // Making the inicial and final pointers of the list point to this node
        point_list->inicial = new;
        point_list->final = new;
    }
    // Else
    else
    {
        // The new node next's pointer points to the existing node
        new->next = point_list->inicial;

        // The list's inicial pointer points to the new node
        point_list->inicial = new;
    }

    // Incrementing the length of the list
    point_list->length++;
}

// Function that inserts a value in the end of the list
void insert_end_sll(int value, list_sll *point_list)
{
    // Creating a new node
    node_sll *new = create_node_sll(value, NULL);

    // If the list's empty
    if (point_list->length == 0)
    {
        // Making the inicial and final pointers of the list point to this node
        point_list->inicial = new;
    }
    // Else
    else
    {
        // Making the old last node points to the new node
        point_list->final->next = new;
    }

    // Making the list's final pointer points to the new node
    point_list->final = new;

    // Incrementing the length of the list
    point_list->length++;
}

// Function that returns the inicial value of the list
int obtain_inicial_value_sll(list_sll *point_list)
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
int obtain_last_value_sll(list_sll *point_list)
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
        // Showing the value
        printf("The last value of the list is: ");

        // Return the list's incial node value
        return point_list->final->value;
    }
}

// Function that remove the list's begging node
int remove_begin_sll(list_sll *point_list)
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
        node_sll *point_auxiliar = point_list->inicial;

        // The list's incial node become the second node
        point_list->inicial = point_auxiliar->next;

        // Getting free the first node's memory
        free(point_auxiliar);

        // Showing the message of success
        printf("The first node was removed.\n");

        // Decreasing the length of the list
        point_list->length--;

        // Return 1
        return 1;
    }
}

// Function that removes the last value of a list
int remove_last_sll(list_sll *point_list)
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
        free(point_list->final);

        // Making the list inicial and last pointer's points to NULL
        point_list->inicial == NULL;
        point_list->final == NULL;
    }
    // Else
    else
    {
        // Declaring an auxiliar pointer
        node_sll *aux_point = point_list->inicial;

        // While the auxiliar pointer isn't in the penultime element
        while (aux_point->next != point_list->final)
        {
            // It goes to the next element
            aux_point = aux_point->next;
        }

        // Getting free the node's memory
        free(point_list->final);

        // Final pointer receive auxiliar pointer
        point_list->final = aux_point;

        // The current final node points to NULL
        aux_point->next = NULL;
    }

    // Showing the message of success
    printf("The last node was removed.\n");

    // Decreasing the length of the list
    point_list->length--;

    // Return 1
    return 1;
}

// Function that cleans up a list
void clean_up_sll(list_sll *point_list)
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
        node_sll *point_delete = point_list->inicial, *point_next_delete = point_delete->next;

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

        // Updating the list's inicial and final pointer
        point_list->inicial = NULL;
        point_list->final = NULL;

        // Informing that the list cleaned up
        printf("The list is cleaned up.\n\n");
    }
}

/*
// Function that deletes a list
void delete_list_sll(list_sll **point_point_list)
{
// Cleaning the list first
clean_up_sll(*point_point_list);

// Freeing the memory of the list using the pointer of the pointer of the list
free(*point_point_list);

// Making the pointer of the pointer of the list points to NULL
*point_point_list = NULL;

// Informing that the deletion was complete
printf("The list was deleted successfully.\n\n");
}

// Function that changes the first value of a list
int change_inicial_value_sll(int value, list_sll *point_list)
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
int change_last_value_sll(int value, list_sll *point_list)
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
node_sll *point_auxiliar = point_list->inicial;

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
int insert_value_any_position_sll(int value, list_sll *point_list, int position)
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
node_sll *new = create_node_sll(value, NULL);

// If the position is 0
if (position == 0)
{
// Inserting in the begging of the list
insert_begin_sll(value, point_list);

// Inform that the action was successed
printf("The new node was insert on the first position.\n");

// Return 1
return 1;
}
// Else if the position is equals the list's length
else if (position == point_list->length)
{
// Inserting in the end of the list
insert_end_sll(value, point_list);

// Inform that the action was successed
printf("The new node was insert on the last position.\n");

// Return 1
return 1;
}
// Else
else
{
// Declaring an auxiliar pointer that points to the first node
node_sll *point_auxiliar = point_list->inicial;

// For the auxiliar pointer is not pointing to the before before the wanted position
for (int i = 0; i < (position - 1); i++)
{
// It goes to the next node
point_auxiliar = point_auxiliar->next;
}

// Inserting the value in the position
new->next = point_auxiliar->next;
point_auxiliar->next = new;
}

// Inserting the valu in the new node
new->value = value;

// Increasing the size of the list
point_list->length++;

// Return 1
return 1;
}
}

// Function that removes any position of the list
int remove_value_any_position_sll(list_sll *point_list, int position)
{
// If the list's empty
if (point_list->length == 0)
{
// Advise that the list is empty
printf("The list is empty, so there isn't a node to be removed.\n");

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

// If the position is 0
if (position == 0)
{
// Remove the begin of the list
remove_begin_sll(point_list);

// Return 1
return 1;
}
// Else if, the position is the length of the list
else if (position == (point_list->length - 1))
{
// Remove the end of the list
remove_last_sll(point_list);

// Return 1
return 1;
}
// Else
else
{
// Declaring an auxiliar pointer of the list first node
node_sll *point_auxiliar = point_list->inicial;

// For the point auxiliar isn't the penultime position that is going to be excluded
for (int i = 0; i < (position - 1); i++)
{
// The point auxiliar goes to the next node
point_auxiliar = point_auxiliar->next;
}

// Declaring a pointer that saves the node that will be excluded
node_sll *point_delete = point_auxiliar->next;

// Making the auxiliar pointer's node points to the next next node
point_auxiliar->next = point_auxiliar->next->next;

// Freeing the delete pointer's node memory
free(point_delete);

// Showing the message of success
printf("The node was removed.\n");

// Decreasing the length of the list
point_list->length--;

// Return 1
return 1;
}
}
}

// Function that changes any list's value in any position
int change_value_any_position_sll(int value, list_sll *point_list, int position)
{
// If the list's empty
if (point_list->length == 0)
{
// Advise that the list is empty
printf("The list is empty, so there isn't a node to be changed.\n");

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
// If the position is 0
if (position == 0)
{
// Change the begin of the list
change_inicial_value_sll(value, point_list);

// Return 1
return 1;
}
// Else if, the position is the length of the list
else if (position == (point_list->length - 1))
{
// Change the end of the list
change_last_value_sll(value, point_list);

// Return 1
return 1;
}
// Else
else
{
// Declaring an auxiliar pointer of the list first node
node_sll *point_auxiliar = point_list->inicial;

// For the point auxiliar isn't the position that will have the value changed
for (int i = 0; i < position; i++)
{
// The point auxiliar goes to the next node
point_auxiliar = point_auxiliar->next;
}

// Changing the value of the node
point_auxiliar->value = value;

// Showing the message of success
printf("The node's value was changed.\n");

// Return 1
return 1;
}
}
}

// Function that obtains any list's value in any position
int obtain_value_any_position_sll(list_sll *point_list, int position)
{
// If the list's empty
if (point_list->length == 0)
{
// Advise that the list is empty
printf("The list is empty, so there isn't a node to be obtained.\n");

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
// If the position is 0
if (position == 0)
{
// Return the begin of the list
return obtain_inicial_value_sll(point_list);
}
// Else if, the position is the length of the list
else if (position == (point_list->length - 1))
{
// Retrun the end of the list
return obtain_last_value_sll(point_list);
}
// Else
else
{
// Declaring an auxiliar pointer of the list first node
node_sll *point_auxiliar = point_list->inicial;

// For the point auxiliar isn't the position that will return the value
for (int i = 0; i < position; i++)
{
// The point auxiliar goes to the next node
point_auxiliar = point_auxiliar->next;
}

// Showing the message of success
printf("The value in the %d index is: ", position);

return point_auxiliar->value;
}
}
}
*/