#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    int array[10] = { 5, 3, 8, 1, 4, 7, 10, 2, 6, 9 };

    Tree myTree;
    myTree = initTree(myTree);

    // Adding elements to the tree
    myTree = insertMany(myTree, array);

    // Inorder traversal
    printf("Inorder traversal of the tree:\n");
    inorderTree(myTree.Root);

    return 0;
}
