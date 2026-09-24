#ifndef LISTDLL_H
#define LISTDLL_H 1

#include "nodedll.h"

typedef struct intDoublyList
{
    nodeDLL *inicial;
    nodeDLL *final;
    int length;
} listDLL;

listDLL *createListDLL();
void showList(listDLL *listDLL);
void showListBackwards(listDLL *listPoint);
void insertNodeBeginnig(listDLL *listPoint, int value);
void insertingNodeEnd(listDLL *listPoint, int value);
void cleanUpListDLL(listDLL *listPoint);
void destroyListDLL(listDLL **listPointPoint);
int removeNodeBeginnig(listDLL *listPoint);

#endif