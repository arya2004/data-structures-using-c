# Data Structures in C

This repository contains implementations of various data structures and algorithms in C, including Breadth-First Search (BFS) and Depth-First Search (DFS) for graph traversal.

## Files

- `bfs_dfs.h`: Header file containing declarations for BFS and DFS functions.
- `bfs_dfs.c`: Source file containing implementations of BFS and DFS functions.
- `main.c`: Main program file to demonstrate the usage of BFS and DFS functions.
- `queue_array.h` and `stack_array.h`: Header files for queue and stack implementations (not provided in the code snippet).

## BFS Algorithm

The Breadth-First Search (BFS) algorithm traverses the graph level by level starting from a given node. It uses a queue to keep track of nodes to visit next.

## DFS Algorithm

The Depth-First Search (DFS) algorithm traverses the graph depth by depth starting from a given node. It uses a stack to keep track of nodes to visit next.

## Usage

Compile the code using a C compiler (e.g., `gcc`):

```bash
gcc main.c bfs_dfs.c queue_array.c stack_array.c -o graph_traversal
