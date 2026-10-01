/*
DATE: 09/23/2026
*/

// Including libraries
#include "listdll.h"

// Function main
int main()
{
    // Creating a list
    listDLL *list1 = createListDLL();

    // Show the list
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

    /*
    // Test: Inserting in the list's end
    insertingNodeEnd(list1, 4);
    showList(list1);
    showListBackwards(list1);
    insertingNodeEnd(list1, 5);
    showList(list1);
    showListBackwards(list1);
    insertingNodeEnd(list1, 6);
    showList(list1);
    showListBackwards(list1);

    // Test: Cleaning up and destroying a list
    cleanUpListDLL(list1);
    showList(list1);
    showListBackwards(list1);
    destroyListDLL(&list1);
    printf("list1 = %p\n", list1);

    // Test: Removing the first node
    removeNodeBeginnig(list1);
    showList(list1);
    showListBackwards(list1);
    removeNodeBeginnig(list1);
    showList(list1);
    showListBackwards(list1);
    removeNodeBeginnig(list1);
    showList(list1);
    showListBackwards(list1);
    removeNodeBeginnig(list1);
    showList(list1);
    showListBackwards(list1);
    */

    // Test: Obtaining the list's incial, final and (any) value
    showList(list1);
    printf("The list's inicial value is: %d\n\n", obtainInicialValueDLL(list1));
    printf("The list's final value is: %d\n\n", obtainFinalValueDLL(list1));
    int position = 1;
    printf("The list's value in the position %d is: %d\n\n", position, obtainAnyValueDLL(list1, position));

    // Test: Changing the list's incial, final and (any) value
    changeInicialValueDLL(list1, 0);
    changeFinalValueDLL(list1, 4);
    changeAnyValueDLL(list1, 6, position);
    showList(list1);
    showListBackwards(list1);

    printf("----------\n\n");

    // Test: Inserting in any position in the list
    insertingNodeAnyPosition(list1, 10, 0);
    showList(list1);
    insertingNodeAnyPosition(list1, 20, 2);
    showList(list1);
    insertingNodeAnyPosition(list1, 30, 2);
    showList(list1);
    showListBackwards(list1);

    // Return 0
    return 0;
}