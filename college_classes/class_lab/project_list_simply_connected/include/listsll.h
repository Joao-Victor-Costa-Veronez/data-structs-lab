#ifndef LISTSLL_H
#define LISTSLL_H 1

// Importing libraries
#include "nodesll.h"
#include <stdio.h>

// Declaring structs
typedef struct simple_list_int
{
    // Declaring variables
    node_SLL *inicial;
    int length;
} list_SLL;

// Declaring functions
list_SLL *create_list_SLL();
void show_list_SLL(list_SLL *point_list);
void insert_end_SLL(int value, list_SLL *point_list);
void insert_begin_SLL(int value, list_SLL *point_list);
int obtain_inicial_value_SLL(list_SLL *pont_list);
int obtain_last_value_SLL(list_SLL *pont_list);

#endif