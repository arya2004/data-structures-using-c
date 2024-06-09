# Tree Traversal in C

This repository contains an implementation of an iterative postorder tree traversal algorithm using a stack.

## Files

- `tree_traversal.h`: Header file containing the definitions of the Node structure, Stack structure, and the functions.
- `tree_traversal.c`: Source file containing the implementation of the functions.
- `main.c`: Main program file to demonstrate the usage of the postorder traversal function.

## Postorder Traversal

Postorder traversal is a tree traversal technique where the nodes are recursively visited in the following order: left subtree, right subtree, root node. The provided implementation uses an iterative approach with a stack.

## Usage

Compile the code using a C compiler (e.g., `gcc`):

```bash
gcc main.c tree_traversal.c -o tree_traversal
