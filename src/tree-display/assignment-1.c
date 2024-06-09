#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode {
    struct TreeNode* data;
    struct StackNode* next;
};


struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void push(struct StackNode** top, struct TreeNode* data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

struct TreeNode* pop(struct StackNode** top) {
    if (*top == NULL)
        return NULL;

    struct TreeNode* data = (*top)->data;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (stack != NULL) {
        struct TreeNode* node = pop(&stack);
        printf("%d ", node->data);

        if (node->right != NULL)
            push(&stack, node->right);

        if (node->left != NULL)
            push(&stack, node->left);
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || stack != NULL) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;
    push(&stack1, root);

    while (stack1 != NULL) {
        struct TreeNode* node = pop(&stack1);
        push(&stack2, node);

        if (node->left != NULL)
            push(&stack1, node->left);

        if (node->right != NULL)
            push(&stack1, node->right);
    }

    while (stack2 != NULL) {
        struct TreeNode* node = pop(&stack2);
        printf("%d ", node->data);
    }
}

void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int main() {
      struct TreeNode* root = NULL;
    int values[] = {15, 53, 7, 92, 24, 46, 58, 10, 14};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; ++i) {
        root = insert(root, values[i]);
    }

    printf("Pre \n ");
    preorderTraversal(root);
    printf("\n");
    printf("in \n ");
     inorderTraversal(root);
    printf("\n");
    printf("post \n ");
     postorderTraversal(root);
    printf("\n");
    freeTree(root);
    return 0;
}