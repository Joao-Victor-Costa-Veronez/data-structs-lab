/*
DATE: 09/30/2026
*/
// Importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listsll.h"

// Main function
int main()
{
    // Declaring variables
    list_SLL *list_1 = create_list_SLL();

    // Showing the empty list
    show_list_SLL(list_1);

    // Test: Inserting elements in the list, by the end
    insert_end_SLL(30, list_1);
    show_list_SLL(list_1);

    insert_end_SLL(40, list_1);
    show_list_SLL(list_1);
    
    insert_end_SLL(50, list_1);
    show_list_SLL(list_1);

    // Test: Inserting elements in the list, by the beggining
    insert_begin_SLL(30, list_1);
    show_list_SLL(list_1);

    insert_begin_SLL(20, list_1);
    show_list_SLL(list_1);
    
    insert_begin_SLL(10, list_1);
    show_list_SLL(list_1);

    return 0;
}