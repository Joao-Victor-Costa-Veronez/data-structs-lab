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
    showListDLL(list1);
    showListBackwardsDLL(list1);

    // Test: Inserting in the begging of the list
    insertNodeBeginnigDLL(list1, 3);
    showListDLL(list1);
    showListBackwardsDLL(list1);
    insertNodeBeginnigDLL(list1, 2);
    showListDLL(list1);
    showListBackwardsDLL(list1);
    insertNodeBeginnigDLL(list1, 1);
    showListDLL(list1);
    showListBackwardsDLL(list1);

    /*
    // Test: Inserting in the list's end
    insertingNodeEndDLL(list1, 4);
    showListDLL(list1);
    showListBackwardsDLL(list1);
    insertingNodeEndDLL(list1, 5);
    showListDLL(list1);
    showListBackwardsDLL(list1);
    insertingNodeEndDLL(list1, 6);
    showListDLL(list1);
    showListBackwardsDLL(list1);

    // Test: Cleaning up and destroying a list
    cleanUpListDLL(list1);
    showListDLL(list1);
    showListBackwardsDLL(list1);
    destroyListDLL(&list1);
    printf("list1 = %p\n", list1);
    */

    // Test: Removing the any node in the list
    removeNodeAnyPositionDLL(list1, 1);
    showListDLL(list1);
    showListBackwardsDLL(list1);

    /*
    // Test: Obtaining the list's incial, final and (any) value
    showListDLL(list1);
    printf("The list's inicial value is: %d\n\n", obtainInicialValueDLL(list1));
    printf("The list's final value is: %d\n\n", obtainFinalValueDLL(list1));
    int position = 1;
    printf("The list's value in the position %d is: %d\n\n", position, obtainAnyValueDLL(list1, position));

    // Test: Changing the list's incial, final and (any) value
    changeInicialValueDLL(list1, 0);
    changeFinalValueDLL(list1, 4);
    changeAnyValueDLL(list1, 6, position);
    showListDLL(list1);
    showListBackwardsDLL(list1);

    // Test: Inserting in any position in the list
    insertingNodeAnyPositionDLL(list1, 10, 0);
    showListDLL(list1);
    insertingNodeAnyPositionDLL(list1, 20, 2);
    showListDLL(list1);
    insertingNodeAnyPositionDLL(list1, 30, 2);
    showListDLL(list1);
    showListBackwardsDLL(list1);
    */

    // Return 0
    return 0;
}