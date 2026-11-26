// Importing libraries
#include "treeBST.h"
#include "queueBST.h"

// Function that creates a new BST
BST *createTreeBST()
{
    // Allocing the memory
    BST *new = (BST *)malloc(sizeof(BST));

    // If there was an error
    if (new == NULL)
    {
        // Inform and exit
        printf("Fatal error: Failed to allocate memory to BST.\n");
        exit(1);
    }
    // Putting default values in the variables
    new->root = NULL;
    new->nodesQuantity = 0;

    // Returning the new tree created
    return new;
}

// Function that inserts a value in the BST
void insertBST(int key, BST *BSTPoint)
{
    // Creating a new node
    nodeBST *new = createNodeBST(key, NULL, NULL);

    // If the BST it's empty
    if (BSTPoint->nodesQuantity == 0)
    {
        // Make the new node the BST's root
        BSTPoint->root = new;
    }
    // Else
    else
    {
        // Declaring auxiliar pointers
        nodeBST *aux = BSTPoint->root;
        nodeBST *auxFather = NULL;

        // While aux is different NULL
        while (aux != NULL)
        {
            // Aux father goes to aux
            auxFather = aux;

            // If the key is lower than the node
            if (key < aux->key)
            {
                // Go to the left child
                aux = aux->leftChild;
            }
            // Else if, the key is greater than the node
            else if (key > aux->key)
            {
                // Go to the right child
                aux = aux->rightChild;
            }
            // Else
            else
            {
                // Inform that the user can't use a key that is already in the BST
                printf("It's not allowed to insert values that are already in the tree.\n");
                exit(1);
            }
        }

        // If the key is lower than the node
        if (key < auxFather->key)
        {
            // The new node goes to the left
            auxFather->leftChild = new;
        }
        // Else
        else
        {
            // The new node goes to the right
            auxFather->rightChild = new;
        }
    }

    // Increasing the quantity
    BSTPoint->nodesQuantity++;
}

// Function that visits a node in the BST
void visitBST(nodeBST *node)
{
    // Show the node
    printf("%d, ", node->key);
}

// Function that shows a BST in the Pre-Order way
void preRecOrderBST(BST *BSTPoint)
{
    // Recursive
    preAuxRecOrderBST(BSTPoint->root);
}

void preAuxRecOrderBST(nodeBST *nodePoint)
{
    if (nodePoint != NULL)
    {
        visitBST(nodePoint);
        preAuxRecOrderBST(nodePoint->leftChild);
        preAuxRecOrderBST(nodePoint->rightChild);
    }
}

void inRecOrderBST(BST *BSTPoint)
{
    inAuxRecOrderBST(BSTPoint->root);
}

void inAuxRecOrderBST(nodeBST *nodePoint)
{
    if (nodePoint != NULL)
    {
        inAuxRecOrderBST(nodePoint->leftChild);
        visitBST(nodePoint);
        inAuxRecOrderBST(nodePoint->rightChild);
    }
}

void posRecOrderBST(BST *BSTPoint)
{
    posAuxRecOrderBST(BSTPoint->root);
}

void posAuxRecOrderBST(nodeBST *nodePoint)
{
    if (nodePoint != NULL)
    {
        posAuxRecOrderBST(nodePoint->leftChild);
        posAuxRecOrderBST(nodePoint->rightChild);
        visitBST(nodePoint);
    }
}

void widthBST(BST *nodePoint)
{
    if (nodePoint->nodesQuantity == 0)
    {
        printf("Empty BST");
    }
    else
    {
        QueueBST *queue = createQueueBST();
        enqueueQueueBST(nodePoint->root, queue);
        while (queue->size > 0)
        {
            nodeBST *node = peekQueueBST(queue);
            dequeueQueueBST(queue);
            visitBST(node);
            if (node->leftChild != NULL)
            {
                enqueueQueueBST(node->leftChild, queue);
            }
            if (node->rightChild != NULL)
            {
                enqueueQueueBST(node->rightChild, queue);
            }
        }
        destroyQueueBST(&queue);
    }
}

nodeBST *searchBST(int key, BST *BSTPoint)
{
    if (BSTPoint->nodesQuantity == 0)
    {
        printf("It's impossible to search a key in an empty BST\n");
        return NULL;
    }

    nodeBST *auxPoint = BSTPoint->root;

    while (auxPoint != NULL && auxPoint->key != key)
    {
        if (key < auxPoint->key)
        {
            auxPoint = auxPoint->leftChild;
        }
        else
        {
            auxPoint = auxPoint->rightChild;
        }
    }

    return auxPoint;
}

nodeBST *searchWithFatherBST(int key, BST *BSTPoint, nodeBST **fatherPointPoint)
{
    *fatherPointPoint = NULL;

    if (BSTPoint->nodesQuantity == 0)
    {
        printf("It's impossible to search a key in an empty BST\n");
        return NULL;
    }

    nodeBST *auxPoint = BSTPoint->root;

    while (auxPoint != NULL && auxPoint->key != key)
    {
        if (key < auxPoint->key)
        {
            *fatherPointPoint = auxPoint;
            auxPoint = auxPoint->leftChild;
        }
        else
        {
            *fatherPointPoint = auxPoint;
            auxPoint = auxPoint->rightChild;
        }
    }

    return auxPoint;
}

void cleansUpBST(BST *BSTPoint)
{
    if (BSTPoint->nodesQuantity != 0)
    {
        cleansUpRecBST(BSTPoint->root);

        BSTPoint->nodesQuantity = 0;
        BSTPoint->root = NULL;
    }
}

void cleansUpRecBST(nodeBST *nodePoint)
{
    if (nodePoint != NULL)
    {
        cleansUpRecBST(nodePoint->leftChild);
        cleansUpRecBST(nodePoint->rightChild);
        free(nodePoint);
    }
}

void destroyBST(BST **BSTPointPoint)
{
    cleansUpBST(*BSTPointPoint);
    free(*BSTPointPoint);
    *BSTPointPoint = NULL;
}

nodeBST *predecessorBST(nodeBST *nodeBSTPoint)
{
    nodeBST *auxPoint = nodeBSTPoint;

    auxPoint = auxPoint->leftChild;

    while (auxPoint->rightChild != NULL)
    {
        auxPoint = auxPoint->rightChild;
    }

    return auxPoint;
}

nodeBST *successorBST(nodeBST *nodeBSTPoint)
{
    nodeBST *auxPoint = nodeBSTPoint;

    auxPoint = auxPoint->rightChild;

    while (auxPoint->leftChild != NULL)
    {
        auxPoint = auxPoint->leftChild;
    }

    return auxPoint;
}

int removeFusionBST(int key, BST *BSTPoint)
{
    if (BSTPoint->nodesQuantity == 0)
    {
        printf("It's impossible to remove a node from an empty BST\n");
        return 0;
    }

    nodeBST *father;
    nodeBST *auxPoint = searchWithFatherBST(key, BSTPoint, &father);

    if (auxPoint == NULL)
    {
        printf("Key wasn't found in BST\n");
        return 0;
    }

    if (auxPoint->leftChild == NULL && auxPoint->rightChild == NULL)
    {
        if (father->leftChild == auxPoint)
        {
            father->leftChild = NULL;
        }
        else
        {
            father->rightChild = NULL;
        }
    }
    else if (auxPoint->leftChild != NULL && auxPoint->rightChild == NULL)
    {
        father->rightChild = auxPoint->leftChild;
    }
    else if (auxPoint->leftChild == NULL && auxPoint->rightChild != NULL)
    {
        father->leftChild = auxPoint->rightChild;
    }
    else
    {
        nodeBST *predecessor = predecessorBST(auxPoint);

        if (father->leftChild == auxPoint)
        {
            father->leftChild = auxPoint->leftChild;
        }
        else
        {
            father->rightChild = auxPoint->leftChild;
        }

        predecessor->rightChild = auxPoint->rightChild;
        auxPoint->rightChild = NULL;
    }

    if (key == BSTPoint->root->key)
    {
        nodeBST *auxPoint = BSTPoint->root;

        if (BSTPoint->root->leftChild != NULL)
        {
            auxPoint = predecessorBST(BSTPoint->root);

            auxPoint->rightChild = BSTPoint->root->rightChild;

            auxPoint = BSTPoint->root;

            BSTPoint->root = BSTPoint->root->leftChild;

            free(auxPoint);
        }
    }

    free(auxPoint);

    BSTPoint->nodesQuantity--;

    return 1;
}

int removeCopyBST(int key, BST *BSTPoint)
{
}

void _writeDotNodes(nodeBST *node, FILE *file, int *nullCount)
{
    if (node == NULL)
    {
        return;
    }

    // If there is a left child
    if (node->leftChild != NULL)
    {
        fprintf(file, "    %d -> %d;\n", node->key, node->leftChild->key);
        _writeDotNodes(node->leftChild, file, nullCount);
    }
    else if (node->rightChild != NULL)
    {
        // If there is no left child but there is a right child, create an invisible
        // null node to keep the Graphviz alignment correct.
        fprintf(file, "    null%d [shape=point];\n", *nullCount);
        fprintf(file, "    %d -> null%d;\n", node->key, *nullCount);
        (*nullCount)++;
    }

    // If there is a right child
    if (node->rightChild != NULL)
    {
        fprintf(file, "    %d -> %d;\n", node->key, node->rightChild->key);
        _writeDotNodes(node->rightChild, file, nullCount);
    }
    else if (node->leftChild != NULL)
    {
        // If there is no right child but there is a left child, create an invisible null node.
        fprintf(file, "    null%d [shape=point];\n", *nullCount);
        fprintf(file, "    %d -> null%d;\n", node->key, *nullCount);
        (*nullCount)++;
    }
}

void drawBST(BST *BSTPoint, const char *outputFileName)
{
    if (BSTPoint == NULL || BSTPoint->root == NULL)
    {
        printf("The BST is empty. No image was generated.\n");
        return;
    }

    FILE *file = fopen("tree_temp.dot", "w");
    if (file == NULL)
    {
        printf("Error: Could not create the temporary .dot file.\n");
        return;
    }

    // Graphviz header
    fprintf(file, "digraph BST {\n");
    fprintf(file, "    node [shape=circle, fontname=\"Arial\"];\n");

    // If the root is the only node
    if (BSTPoint->root->leftChild == NULL && BSTPoint->root->rightChild == NULL)
    {
        fprintf(file, "    %d;\n", BSTPoint->root->key);
    }
    else
    {
        int nullCount = 0;
        _writeDotNodes(BSTPoint->root, file, &nullCount);
    }

    fprintf(file, "}\n");
    fclose(file);

    // Build the terminal command to compile the .dot file into .png
    char command[256];
    sprintf(command, "dot -Tpng tree_temp.dot -o %s", outputFileName);

    // Execute the command
    int result = system(command);

    if (result == 0)
    {
        printf("Image generated successfully: %s\n", outputFileName);
    }
    else
    {
        printf("Error generating image. Is Graphviz installed?\n");
    }

    // Optional: remove the temporary text file
    // remove("tree_temp.dot");
}