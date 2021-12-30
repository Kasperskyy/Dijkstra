# Dijkstra
An implementation of Dijkstra's Algorithm for finding the shortest path done for laboratory classes in my studies

# Full instruction and algorith input and output examples:

For a given set of connections between nodes, find the length of the shortest path from the starting point to the destination. Each connection is defined by the 2 nodes it connects and by length (a non-negative integer). Connections are bi-directional (if a is connected with b by a connection of length d, then also b is connected with a with the same length). The recommended way to solve this task is to use the Dijkstra algorithm.

Note that it may be impossible to reach the destination from the starting point (i.e. a graph may not be connected). In this case, you should print an exclamation mark '!' on the screen.

Input\
n: the number of nodes (non-negative integer),\
m: the number of connections (non-negative integer),\
Next m lines in the form: v u d, where:\
v and u are the indices of nodes that are connected (non-negative integers from range [0, n-1]),\
d is the length of the connection between these two nodes (non-negative integer).\
t: the number of tests (non-negative integer),\
Next t lines in the form: a b, where:\
a is the starting point of the path to be found (non-negative integer from range [0, n-1]),\
b is the destination of the path to be found (non-negative integer from range [0, n-1]).\
Output\
For each test: one line with the length of the shortest path for nodes given in this test, or '!' if these vertices are not connected.\
Example\
Input\
4\
3\
0 1 1\
0 2 3\
1 2 1\
2\
0 2\
0 3\
Output\
2\
!
