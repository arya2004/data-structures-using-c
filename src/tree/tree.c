#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

Node* initNode(int _data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = _data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Tree initTree(Tree _tree) {
    _tree.Root = NULL;
    return _tree;
}

Tree addTree(Tree _tree, int _data) {
    if (_tree.Root == NULL) {
        _tree.Root = initNode(_data);
        return _tree;
    } else {
        Node* _traverse = _tree.Root;
        while (true) {
            if (_data > _traverse->data) {
                if (_traverse->right == NULL) {
                    _traverse->right = initNode(_data);
                    return _tree;
                }
                _traverse = _traverse->right;
            }
            if (_data < _traverse->data) {
                if (_traverse->left == NULL) {
                    _traverse->left = initNode(_data);
                    return _tree;
                }
                _traverse = _traverse->left;
            }
        }
    }
    return _tree;
}

void lul(Node* _node, int _data) {
    if (_node == NULL) {
        _node = initNode(_data);
    }
    Node* traverse = _node;
    while (true) {
        if (_data > traverse->data) {
            if (traverse->right == NULL) {
                traverse->right = initNode(_data);
                break;
            } else {
                traverse = traverse->right;
            }
        }
        if (_data < traverse->data) {
            if (traverse->left == NULL) {
                traverse->left = initNode(_data);
                break;
            } else {
                traverse = traverse->left;
            }
        }
    }
}

void insertLul(Node* _node, int* array) {
    for (int i = 0; i < 10; i++) {
        lul(_node, array[i]);
    }
}

Tree insertMany(Tree _tree, int* array) {
    for (int i = 0; i < sizeof(array); i++) {
        _tree = addTree(_tree, array[i]);
    }
    return _tree;
}

void inorderTree(Node* _node) {
    if (_node == NULL)
        return;
    inorderTree(_node->left);
    printf("\n %i", _node->data);
    inorderTree(_node->right);
}
