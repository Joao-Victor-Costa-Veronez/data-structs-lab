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

    // Test: Obtaining the list's incial and final value
    printf("The list's inicial value is: %d\n\n", obtainInicialValueDLL(list1));
    printf("The list's final value is: %d\n\n", obtainFinalValueDLL(list1));

    // Test: Changing the list's incial and final value
    changeInicialValueDLL(list1, 0);
    changeFinalValueDLL(list1, 4);
    showList(list1);
    showListBackwards(list1);

    // Return 0
    return 0;
}