#ifndef LISTSLL_H
#define LISTSLL_H 1

// Importing libraries
#include "nodesll.h"

// Declaring structs
typedef struct simple_list_int
{
    // Declaring variables
    node_sll *inicial;
    node_sll *end;
    int length;
} list_sll;

// Declaring functions
list_sll *create_list_SLL();
void show_list_sll(list_sll *point_list);
void insert_begin_sll(int value, list_sll *point_list);
void insert_end_SLL(int value, list_sll *point_list);
int obtain_inicial_value_SLL(list_sll *point_list);
int obtain_last_value_SLL(list_sll *point_list);
int remove_begin_SLL(list_sll *point_list);
void clean_up_SLL(list_sll *point_list);
void delete_list_SLL(list_sll **point_point_list);
int remove_last_SLL(list_sll *point_list);
int change_inicial_value_SLL(int value, list_sll *point_list);
int change_last_value_SLL(int value, list_sll *point_list);
int insert_value_any_position_SLL(int value, list_sll *point_list, int position);
int remove_value_any_position_SLL(list_sll *point_list, int position);
int change_value_any_position_SLL(int value, list_sll *point_list, int position);
int obtain_value_any_position_SLL(list_sll *point_list, int position);

#endif