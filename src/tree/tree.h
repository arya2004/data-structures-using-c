#ifndef TREE_H
#define TREE_H

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

typedef struct tree {
    Node* Root;
} Tree;

Node* initNode(int _data);
Tree initTree(Tree _tree);
Tree addTree(Tree _tree, int _data);
void insertLul(Node* _node, int* array);
Tree insertMany(Tree _tree, int* array);
void inorderTree(Node* _node);

#endif
