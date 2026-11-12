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

    printf("\n");
    printf("Pre-Order:\n");
    preRecOrderBST(tree1);
    printf("\n\n");

    printf("In-Order:\n");
    inRecOrderBST(tree1);
    printf("\n\n");

    printf("Pos-Order:\n");
    posRecOrderBST(tree1);
    printf("\n\n");

    return 0;
}