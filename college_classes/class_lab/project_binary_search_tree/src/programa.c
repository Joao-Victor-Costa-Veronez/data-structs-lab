/*
DATE: 11/11/2026
*/

#include "treeBST.h"

int main()
{
    BST *tree1 = createTreeBST();

    insertBST(45, tree1);
    insertBST(25, tree1);
    insertBST(65, tree1);

    return 0;
}