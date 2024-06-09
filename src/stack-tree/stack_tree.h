#ifndef STACK_TREE_H
#define STACK_TREE_H

#include "doublelinkedlist.h"

typedef struct tree {
    Node* Root;
    int TotalNodes;
    int Height;
} Tree;

Tree InitNode(Tree _tree);
Tree AddNode(Tree _tree, int _data);
void inorderTree(Node* _node);
void preorderTree(Node* _node);
void lul1(Node* _node);
void postOrder(Node* _node);
Tree BST(Tree _tree, int* arr);
void postOrderNon(Tree _tree);
void postOrderNo(Tree _tree);



typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;


typedef struct StackNode{
    Node* node;
    struct StackNode* link;
}StackNode;

typedef struct {
    StackNode* head;
    int size;
}LinkedListStack;

LinkedListStack newLinkedListStack(LinkedListStack linkedliststack)
{
    linkedliststack.head = NULL;
    linkedliststack.size = 0;
    //linkedliststack.head->link = NULL;
    
    return linkedliststack;
}

int sizeLinkedListStack(LinkedListStack linkedliststack)
{
    return linkedliststack.size;
}

Node* topLinkedListStack(LinkedListStack linkedliststack)
{
    return linkedliststack.head->node;
}

LinkedListStack pushLinkedListStack(LinkedListStack linkedliststack, Node *_node)
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->node = _node;
    temp->link = linkedliststack.head;

    linkedliststack.size = linkedliststack.size + 1;
    linkedliststack.head = temp;
    return linkedliststack;
}

LinkedListStack popLinkedListStack(LinkedListStack linkedliststack)
{
    if (linkedliststack.size == 0)
    {
        printf("\nlinked list queue is empty in pushLinkedListStack");
        exit(1);
    }
    else{
    StackNode* temp = linkedliststack.head;
    linkedliststack.head = linkedliststack.head->link;
    linkedliststack.size = linkedliststack.size - 1;
    free(temp);
    }
    return linkedliststack;
}

LinkedListStack dropLinkedListStack(LinkedListStack linkedliststack)
{
    StackNode * temp = linkedliststack.head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(linkedliststack.head);
        linkedliststack.head = temp;
    }
    linkedliststack.size = 0;
    return linkedliststack;
}

void displayLinkedListStack(LinkedListStack linkedliststack)
{
    printf("\nTOP");
    LinkedListStack temp = linkedliststack;
    for (int i = 0; i < linkedliststack.size; i++)
    {
        printf("->%i", temp.head->node->data);
        temp.head = temp.head->link;
    }
    
}


#endif
