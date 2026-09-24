#ifndef LISTDLL_H
#define LISTDLL_H 1

// Including libraries
#include "nodedll.h"

// Declaring structs
// Interger Doubly Linked List Struct
typedef struct intDoublyList
{
    // Declaring variables
    nodeDLL *inicial;
    nodeDLL *final;
    int length;
  // Declaring struct's nickname
} listDLL;

// Declaring functions
listDLL *createListDLL();
void showList(listDLL *listDLL);
void showListBackwards(listDLL *listPoint);
void insertNodeBeginnig(listDLL *listPoint, int value);
void insertingNodeEnd(listDLL *listPoint, int value);
void cleanUpListDLL(listDLL *listPoint);
void destroyListDLL(listDLL **listPointPoint);
int removeNodeBeginnigDLL(listDLL *listPoint);
int removeNodeEndDLL(listDLL *listPoint);
int obtainInicialValueDLL(listDLL *listPoint);
int obtainFinalValueDLL(listDLL *listPoint);
int changeInicialValueDLL(listDLL *listPoint, int value);
int changeFinalValueDLL(listDLL *listPoint, int value);

#endif