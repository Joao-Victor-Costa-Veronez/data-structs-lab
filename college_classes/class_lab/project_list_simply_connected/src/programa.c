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
    list_SLL *list = create_list_SLL();

    list->inicial = create_node_LSC(10, NULL); 
    list->length++;

    list->inicial->next = create_node_LSC(20, NULL);
    list->length++;

    list->inicial->next->next = create_node_LSC(30, NULL);
    list->length++;

    return 0;
}