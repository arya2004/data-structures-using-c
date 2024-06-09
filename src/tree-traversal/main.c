#include <stdio.h>
#include "tree_traversal.h"

/**
 * Main function to demonstrate postorder tree traversal.
 */
int main() {
    Node* root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
