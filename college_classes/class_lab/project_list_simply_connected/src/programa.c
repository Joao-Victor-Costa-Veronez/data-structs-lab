/*
DATE: 09/30/2026
*/

// Importing libraries
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
    insert_end_SLL(40, list_1);
    show_list_SLL(list_1);

    insert_end_SLL(50, list_1);
    show_list_SLL(list_1);

    insert_end_SLL(60, list_1);
    show_list_SLL(list_1);

    // Test: Inserting elements in the list, by the beggining
    insert_begin_SLL(30, list_1);
    show_list_SLL(list_1);

    insert_begin_SLL(20, list_1);
    show_list_SLL(list_1);

    insert_begin_SLL(10, list_1);
    show_list_SLL(list_1);

    // Test: Gettimg the inicial and last value of the list
    printf("%d\n\n", obtain_inicial_value_SLL(list_1));

    printf("%d\n\n", obtain_last_value_SLL(list_1));

    // Test: Removing from the begging of the list
    printf("%d\n\n", remove_begin_SLL(list_1));
    show_list_SLL(list_1);
    /*
    // Test: Deleting a list
    delete_list_SLL(&list_1);
    */

    // Test: Removing from the end of the list
    printf("%d\n\n", remove_last_SLL(list_1));
    show_list_SLL(list_1);

    return 0;
}