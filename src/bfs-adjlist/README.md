# Breadth-First Search (BFS) in C Using Adjacency List

This repository contains an implementation of the Breadth-First Search (BFS) algorithm for graph traversal using an adjacency list representation.

## Files

- `bfs_adjlist.h`: Header file containing the definition of the BFS function and the Node structure.
- `bfs_adjlist.c`: Source file containing the implementation of the BFS function.
- `main.c`: Main program file to demonstrate the usage of the BFS function.

## BFS Algorithm

The Breadth-First Search (BFS) algorithm traverses the graph level by level starting from a given node. It uses a queue to keep track of nodes to visit next.

## Usage

Compile the code using a C compiler (e.g., `gcc`):

```bash
gcc main.c bfs_adjlist.c -o bfs_adjlist
