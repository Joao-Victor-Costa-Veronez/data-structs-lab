/*
DATE: 09/23/2026
*/

#include "listdll.h"

int main()
{
    listDLL *list1 = createListDLL();
    printf("\n");
    showList(list1);

    // Test: Inserting in the begging of the list
    insertNodeBegginig(list1, 3);
    showList(list1);
    insertNodeBegginig(list1, 2);
    showList(list1);
    insertNodeBegginig(list1, 1);
    showList(list1);

    return 0;
}