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

    // Test: Couting odd numbers
    printf("There are %d odd elements in the list.\n\n", count_odd(list_1));

    // Return 0
    return 0;
}
