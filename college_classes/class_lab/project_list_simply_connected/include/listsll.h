#ifndef LISTSLL_H
#define LISTSLL_H 1

#include "nodesll.h"

typedef struct simple_list_int
{
    node_SLL *inicial;
    int length;
} list_SLL;

list_SLL *create_list_SLL();
void insert_end_SLL(int value, list_SLL *list);

#endif