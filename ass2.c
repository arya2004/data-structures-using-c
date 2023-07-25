#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

//ass2 BST create, insert, delete, mirror image, llevel wise display, display leaf nodes

//ass3 threaded binanry tree create and insert
//inorder
//preorder
//posroeder
typedef struct ITreeNode {
    int data;
    struct ITreeNode* left;
    struct ITreeNode* right;
}TreeNode;

typedef struct IStackNode {
     TreeNode* data;
    struct IStackNode* next;
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

int tree_height(TreeNode* root) {
    if (!root)
        return 0;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
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

TreeNode* deleteNode(TreeNode* _root, int _k)
{

    if (_root == NULL)
    {
        return _root;
    }
        

    if (_root->data > _k) 
    {
        _root->left = deleteNode(_root->left, _k);
        return _root;
    }
    else if (_root->data < _k) 
    {
        _root->right = deleteNode(_root->right, _k);
        return _root;
    }
 

    if (_root->left == NULL) 
    {
        TreeNode* temp = _root->right;
        free(_root);
        return temp;
    }
    else if (_root->right == NULL) 
    {
        TreeNode* temp = _root->left;
        free(_root);
        return temp;
    }
 

    else
    {
 
        TreeNode* succParent = _root;
 
   
        TreeNode* successor = _root->right;
        while (successor->left != NULL) {
            succParent = successor;
            successor = successor->left;
        }
 
        if (succParent != _root)
            succParent->left = successor->right;
        else
            succParent->right = successor->right;
 
        _root->data = successor->data;
 
        free(successor);
        return _root;
    }
}

int height(TreeNode * _node) {
  if (_node == NULL)
    return 0;
  else {
    int lheight = height(_node -> left);
    int rheight = height(_node -> right);
    if (lheight > rheight)
      return (lheight + 1);
    else return (rheight + 1);
  }
}

void CurrentLevel(TreeNode* _root, int _level) {
  if (_root == NULL)
  {
    return;
  }
    
  if (_level == 1)
  {
    printf("%d ", _root -> data);
  }
    
  else if (_level > 1) {
    CurrentLevel(_root -> left, _level - 1);
    CurrentLevel(_root -> right, _level - 1);
  }
}


void LevelOrder(TreeNode * _root) {
  int h = height(_root);
  int i;
  for (i = 1; i <= h; i++)
  {
    CurrentLevel(_root, i);
  }
    
}


TreeNode* create(TreeNode* _node)
{
    _node = (TreeNode*)malloc(sizeof(TreeNode));
    _node->data = 0;
    _node->left = NULL;
    _node->right = NULL;
    return _node;
}

int main1() {
    int choice;
    TreeNode* node;
    printf("1. Create \n 2. Insert \n 3. Delete \n 4. Mirror Image \n 5. Level wise Display \n 6. Height of the tree \n 7. Display Leaf Nodes. \n0. Quit ");
    scanf("%d", &choice);
    while (choice != 0)
    {
    switch (choice) {
        case 1:
          node = create(node);
            break;
        case 2:
            printf("Enter no of elements\n");
            unsigned int total;
            scanf("%d", &total);
            for (int i = 0; i < total; i++)
            {   printf("Enter element %i\n", i);
                int one;
                scanf("%d", &one);
                node = AddNode(node, one);
            }
            
            break;
        case 3:
            printf("ENter element to delete\n");
                int one;
                scanf("%d", &one);
                node = deleteNode(node, one);
            break;
        case 4:
            mirror(node);
            break;
        case 5:
            LevelOrder(node);
            break;
        case 6:
            printf("%i",tree_height(node));
            break;
        case 7:
            leafnodes(node);
            break;
        case 0:
            printf("QUitted\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
    }

    return 0;
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

    printf("\n");
    mirror(root);
    printf("\n");
    

printf("%i",tree_height(root));
    printf("\n");


    freeTree(root);
    return 0;
}