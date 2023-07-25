#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

//ass2 BST create, insert, delete, mirror image, llevel wise display, display leaf nodes

//ass3 threaded binanry tree create and insert
//inorder
//preorder
//posroeder
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct StackNode {
     TreeNode* data;
    struct StackNode* next;
}StackNode;

TreeNode* AddNode(TreeNode* _tree, int _data)
{
    if (_tree == NULL)
    {
       _tree = (TreeNode*)malloc(sizeof(TreeNode));
       _tree->data = _data;
       _tree->left = NULL;
       _tree->right = NULL;
       return _tree;
    }
    else
    {
        TreeNode* _traverse = _tree;
        while (1)
        {
            if (_data < _traverse->data)
            {
                if (_traverse->left == NULL)
                {
                   _traverse->left = (TreeNode*) malloc(sizeof(TreeNode));
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
            if (_data > _traverse->data)
            {
                if (_traverse->right == NULL)
                {
                    _traverse->right = (TreeNode*) malloc(sizeof(TreeNode));
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
void inorderTree(TreeNode* _node)
{
    if(_node != NULL) 
    {
         inorderTree(_node->left);
        printf("\n %i", _node->data);
        inorderTree(_node->right);
    }
}

void postOrder(TreeNode* _node)
{
    if(_node != NULL) 
    {   
            
         postOrder(_node->left);
        postOrder(_node->right);
        printf("\n %i", _node->data);
    }
}

TreeNode* BST(TreeNode* _tree, int* arr, int arrsize)
{
    for (int i = 0; i < arrsize; i++)
    {
        _tree = AddNode(_tree, arr[i]);
    }
    return _tree;
    
}
void freeTree(TreeNode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void mirror(TreeNode* _node)
{
    if (_node == NULL)
    {
        return;
    }   
    else 
    {
        TreeNode* temp;
        mirror(_node->left);
        mirror(_node->right); 
        temp = _node->left;
        _node->left = _node->right;
        _node->right = temp;
    }
}

void printLeafNodes(TreeNode *_root)
{
    if (_root == NULL)
    {
        return;
    }

    
 
    if (_root->left != NULL)
    {
        printLeafNodes(_root->left);
    }

    if(_root->left == NULL && _root->right == NULL)
    {
        printf("%i ", _root->data);
        return;
    }
           
    if (_root->right != NULL)
    {
        printLeafNodes(_root->right);
    }
       
}

void leafnodes(TreeNode* newnode)
{
 
    if(newnode != NULL)
    {
        leafnodes(newnode->left);
        if((newnode->left == NULL) && (newnode->right == NULL))
        {
           printf("%i ", newnode->data);
        }
        leafnodes(newnode->right);
    }
    
 
}

int main() {
     TreeNode* root = NULL;
    int values[] = {33,52,6,96,12,44,10,11,1,9, 19,27};
    int numValues = sizeof(values) / sizeof(values[0]);

     //root = AddNode(root, 44);
     root = BST(root, values, numValues);
    inorderTree(root);
    printf("\n");
    postOrder(root);
     printf("\n");
   printLeafNodes(root);
    printf("\n");
    leafnodes(root);

    freeTree(root);
    return 0;
}