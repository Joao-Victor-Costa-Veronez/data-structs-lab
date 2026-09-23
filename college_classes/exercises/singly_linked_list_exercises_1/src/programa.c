/*
DATE: 09/17/2026
*/

// Importing libraries
#include <string.h>
#include "listsll.h"

// Main function
int main()
{
    // Declaring variables
    list_sll *list_1 = create_list_sll();
    printf("\n");

    // Showing the empty list
    show_list_sll(list_1);

    // Test: Inserting elements in the list, by the beggining
    insert_begin_sll(30, list_1);
    show_list_sll(list_1);

    insert_begin_sll(20, list_1);
    show_list_sll(list_1);

    insert_begin_sll(10, list_1);
    show_list_sll(list_1);

    // Test: Inserting elements in the list, by the end
    insert_end_sll(40, list_1);
    show_list_sll(list_1);

    insert_end_sll(50, list_1);
    show_list_sll(list_1);

    insert_end_sll(60, list_1);
    show_list_sll(list_1);

    // Test: Getting the inicial value of the list
    printf("%d\n\n", obtain_inicial_value_sll(list_1));

    // Test: Getting the last value of the list
    printf("%d\n\n", obtain_last_value_sll(list_1));

    // Test: Removing from the begging of the list
    printf("%d\n\n", remove_begin_sll(list_1));
    show_list_sll(list_1);

    // Test: Removing from the end of the list
    printf("%d\n\n", remove_last_sll(list_1));
    show_list_sll(list_1);

    /*
    //Test: Cleaning up the list
    clean_up_sll(list_1);
    
    // Test: Deleting a list
    delete_list_sll(&list_1);
    */
    
    // Test: Changing the list's first value
    printf("%d\n\n", change_inicial_value_sll(0, list_1));
    show_list_sll(list_1);
    
    // Test: Changing the list's last value
    printf("%d\n\n", change_last_value_sll(100, list_1));
    show_list_sll(list_1);
    
    // Test: Inserting a value in any position
    printf("%d\n\n", insert_value_any_position_sll(18, list_1, 1));
    show_list_sll(list_1);
    
    /*
    // Test: Removing a value in any position
    printf("%d\n\n", remove_value_any_position_sll(list_1, 3));
    show_list_sll(list_1);

    // Test: Changing the value of any position
    printf("%d\n\n", change_value_any_position_sll(19, list_1, 3));
    show_list_sll(list_1);

    // Test: Obtaining a value from any position
    printf("%d\n\n", obtain_value_any_position_sll(list_1, 3));
    show_list_sll(list_1);
    */

    return 0;
}
