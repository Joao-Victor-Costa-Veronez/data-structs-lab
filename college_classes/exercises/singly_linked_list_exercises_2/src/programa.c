/*
DATE: 08/30/2026
*/

// Importing libraries
#include <string.h>
#include "listsll.h"

// Main function
int main()
{
    // Declaring variables
    list_SLL *list_1 = create_list_SLL();

    // Test: Inserting elements in the list, by the beggining
    insert_begin_SLL(3, list_1);
    show_list_SLL(list_1);

    insert_begin_SLL(2, list_1);
    show_list_SLL(list_1);

    insert_begin_SLL(1, list_1);
    show_list_SLL(list_1);

    // Test: Copying a list
    list_SLL *list_2 = copy_list(list_1);
    show_list_SLL(list_2);

    // Test: Concatenating a list
     list_SLL *list_3  = concatenate_lists(list_1, list_2);
     show_list_SLL(list_3);

    // Return 0
    return 0;
}
