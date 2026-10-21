#ifndef ISTACK_H
#define ISTACK_H 1

// Including libraries
#include "nodesll.h"

// Defining structs
typedef struct int_stack
{
    // Declaring variables
    nodeSLL *top;
    int length;
} iStack;

// Declaring functions
iStack *createIStack();
void showIStack(iStack *stackPoint);
int showTopIStack(iStack *stackPoint);
void stackIStack(int value, iStack *stackPoint);
int unstackIStack(iStack *stackPoint);
void cleanUpIStack(iStack *stackPoint);
void deleteIStack(iStack **stackPointPoint);

#endif