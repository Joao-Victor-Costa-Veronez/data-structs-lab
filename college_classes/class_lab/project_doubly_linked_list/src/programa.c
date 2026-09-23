/*
DATE: 09/23/2026
*/

#include "listdll.h"

int main()
{
    listDLL *list1 = createListDLL();
    printf("\n");
    showList(list1);
    showListBackwards(list1);
    
    // Test: Inserting in the begging of the list
    insertNodeBeginnig(list1, 3);
    showList(list1);
    showListBackwards(list1);
    insertNodeBeginnig(list1, 2);
    showList(list1);
    showListBackwards(list1);
    insertNodeBeginnig(list1, 1);
    showList(list1);
    showListBackwards(list1);

    // Test: Inserting in the list's end
    insertingNodeEnd(list1, 4);
    showList(list1);
    insertingNodeEnd(list1, 5);
    showList(list1);
    insertingNodeEnd(list1, 6);
    showList(list1);

    return 0;
}