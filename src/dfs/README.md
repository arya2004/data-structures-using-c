
# Graph Traversal Program

This program demonstrates Depth-First Search (DFS) on a graph using an adjacency matrix representation.

## Purpose

The purpose of this program is to perform a depth-first traversal of a graph, starting from a specified vertex, and print the vertices in the order they are visited.

## Compilation

To compile the program, use a C compiler such as `gcc`:

```bash
gcc main.c graph_traversal.c -o graph_traversal
```

## Input

The program prompts the user to input the following:

1. Number of vertices in the graph.
2. Adjacency matrix representing the graph. For each pair of vertices (i, j), the user is asked whether there is an edge from vertex i to vertex j (1 for Yes, 0 for No).

## Usage

Run the compiled program:

```bash
./graph_traversal
```

Follow the prompts to input the graph data and starting vertex for DFS traversal.

## Example

Suppose we have a graph with 5 vertices and the following adjacency matrix:

```
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
```

Starting DFS traversal from vertex 0, the output would be:

```
DFS traversal starting from vertex 0: 0 1 3 2 4
```

## License

This project is licensed under the MIT License.

