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
void showListDLL(listDLL *listDLL);
void showListBackwardsDLL(listDLL *listPoint);
void insertNodeBeginnigDLL(listDLL *listPoint, int value);
void insertingNodeEndDLL(listDLL *listPoint, int value);
int insertingNodeAnyPositionDLL(listDLL *listPoint, int value, int position);
void cleanUpListDLL(listDLL *listPoint);
void destroyListDLL(listDLL **listPointPoint);
int removeNodeBeginnigDLL(listDLL *listPoint);
int removeNodeEndDLL(listDLL *listPoint);
int removeNodeAnyPositionDLL(listDLL *listPoint, int position);
int obtainInicialValueDLL(listDLL *listPoint);
int obtainFinalValueDLL(listDLL *listPoint);
int obtainAnyValueDLL(listDLL *listPoint, int position);
int changeInicialValueDLL(listDLL *listPoint, int value);
int changeFinalValueDLL(listDLL *listPoint, int value);
int changeAnyValueDLL(listDLL *listPoint, int value, int position);

#endif