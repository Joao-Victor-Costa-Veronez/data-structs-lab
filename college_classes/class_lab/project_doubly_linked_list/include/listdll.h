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
void insertNodeBegginig(listDLL *listPoint, int value);

#endif