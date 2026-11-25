/*
DATE: 11/11/2026
*/

#include "treeBST.h"

int main()
{
    BST *tree1 = createTreeBST();

    nodeBST *response = searchBST(25, tree1);
    if (response == NULL)
    {
        printf("Didn't find %d or the BST is empty\n", 25);
    }
    else
    {
        printf("Found %d in BST\n", response->key);
    }

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

    printf("Width:\n");
    widthBST(tree1);
    printf("\n\n");

    response = searchBST(25, tree1);
    if (response == NULL)
    {
        printf("Didn't find %d or the BST is empty\n", 25);
    }
    else
    {
        printf("Found %d in BST\n", response->key);
    }

    cleansUpBST(tree1);

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

    printf("Width:\n");
    widthBST(tree1);
    printf("\n\n");

    destroyBST(&tree1);
    printf("%p\n", tree1);

    return 0;
}