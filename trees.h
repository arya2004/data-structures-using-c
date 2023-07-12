#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

#include"stack_tree.h"

// typedef struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// }Node;

typedef struct tree{
    Node* Root;
    int TotalNodes;
    int Height;
}Tree;

Tree InitNode(Tree _tree)
{
    _tree.Root = (Node*)malloc(sizeof(Node));
    _tree.Root->data = -1;
    _tree.Root->left = NULL;
    _tree.Root->right = NULL;
    return _tree;
}

Tree AddNode(Tree _tree, int _data)
{
    if (_tree.Root == NULL)
    {
        _tree.Root = (Node*) malloc(sizeof(Node));
        _tree.Root->data = _data;
        _tree.Root->left = NULL;
        _tree.Root->right = NULL;
        return _tree;
    }
    else
    {
        Node* _traverse = _tree.Root;
        while (true)
        {
            if(_data < _traverse->data)
            {
                if(_traverse->left == NULL)
                {
                    _traverse->left = (Node*) malloc(sizeof(Node));
                    _traverse->left->data = _data;
                    _traverse->left->left = NULL;
                    _traverse->left->right = NULL;
                    return _tree;

                }
                else
                {
                    _traverse = _traverse->left;
                }
            }
            if(_data > _traverse->data)
            {
                if(_traverse->right == NULL)
                {
                    _traverse->right = (Node*) malloc(sizeof(Node));
                    _traverse->right->data = _data;
                    _traverse->right->left = NULL;
                    _traverse->right->right = NULL;
                    return _tree;

                }
                else
                {
                    _traverse = _traverse->right;
                }
            }
        }
        
    }
    return _tree;
}

void inorderTree(Node* _node)
{
    if(_node != NULL) 
    {
         inorderTree(_node->left);
        printf("\n %i", _node->data);
        inorderTree(_node->right);
    }
}

void preorderTree(Node* _node)
{
    if(_node != NULL) 
    {   
            printf("\n %i", _node->data);
         preorderTree(_node->left);
        preorderTree(_node->right);
    }
}

void lul1(Node* _node)
{   printf("\n");
    if(_node != NULL) 
    {   
            printf(" %i", _node->data);
         preorderTree(_node->left);
         
        preorderTree(_node->right);
        
    }
    
}

void postOrder(Node* _node)
{
    if(_node != NULL) 
    {   
            
         postOrder(_node->left);
        postOrder(_node->right);
        printf("\n %i", _node->data);
    }
}

Tree BST(Tree _tree, int* arr)
{
    for (int i = 0; i < 10; i++)
    {
       _tree = AddNode(_tree, arr[i]);
    }
    return _tree;
    
}

void postOrderNon(Tree _tree)
{   Node *temp = _tree.Root;
    LinkedListStack _linkedListStack = newLinkedListStack(_linkedListStack);

    Node* prev = NULL;
    do
    {   while (temp != NULL)
        {
            _linkedListStack = pushLinkedListStack(_linkedListStack, *temp);
            printf("\n %i",temp->data);
            temp = temp->left;
        }
    
        while (temp != NULL)
        {
            if(temp->right == NULL || sizeLinkedListStack(_linkedListStack) != 0)
            {
                printf("\n %i",temp->data);
                prev = _tree.Root;
                _linkedListStack = popLinkedListStack(_linkedListStack);
                temp = NULL;

            }
            else
            {
                temp = temp->right;
            }

        }
        

    } while (sizeLinkedListStack(_linkedListStack)>= 0);
    
}

