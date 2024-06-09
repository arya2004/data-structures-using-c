# Prim's Algorithm for Minimum Spanning Tree (MST)

This program implements Prim's algorithm to find the minimum spanning tree (MST) of a weighted undirected graph.

## File Structure

- `prim_mst.c`: Contains the main implementation of Prim's algorithm.
- `prim_mst.h`: Header file containing function prototypes and necessary definitions.
- `README.md`: This README file providing an overview of the program and its usage.

## Function Descriptions

- `findMinKey(int key[], bool mstSet[])`: Finds the minimum key value from the set of vertices not yet included in the MST.
- `printMST(int parent[], int graph[V][V])`: Prints the edges and their corresponding weights in the MST.
- `primMST(int graph[V][V])`: Main function to calculate and print the MST using Prim's algorithm.

## Usage

1. Compile the program using a C compiler (e.g., gcc).
2. Run the executable and provide the adjacency matrix for the graph.
3. The program will output the edges and weights of the minimum spanning tree.
