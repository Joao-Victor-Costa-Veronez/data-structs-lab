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
    list_SLL *list_1 = create_list_SLL();

    show_list_SLL(list_1);

    insert_end_SLL(10, list_1);
    show_list_SLL(list_1);

    insert_end_SLL(20, list_1);
    show_list_SLL(list_1);
    
    insert_end_SLL(30, list_1);
    show_list_SLL(list_1);

    return 0;
}