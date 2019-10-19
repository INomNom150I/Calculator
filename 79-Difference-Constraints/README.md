### Difference Constraints

#### Problem: Find a feasible solution to a system of difference constraints, i.e. a system of linear inequalities of the form xJ – xi ≤ bk 1 ≤ i, j ≤ n, 1 ≤ k ≤ m

#### Solution: use a shortest-path algorithm which can detect negative weight cycles (e.g. Belman-Ford algorithm).

#### Steps:

1. Convert the system of linear inequalities into a directed weighted graph G. Use the following algorithm:
    a. Inequality xJ – xi ≤ bk is represented as verticesvJand vi connected with an edge of weight bk. The direction of the edge is from i to j, i.e.  w(vi , vJ) = bk
    b. Introduce vertex v0, such that w(v0 , vi) = 0 for all i.

2. Find shortest paths from v0 to all other vertices.

3. If G contains no negative weight cycles, then the shortest path solution, starting from v0, is the feasible solution to the system.

