#### `To teach is to learn twice.`
            -- Joseph Joubert

The Seven Bridges of Königsberg is a historically notable problem in mathematics. Its negative resolution by Leonhard Euler in 1736 laid the foundations of graph theory and prefigured the idea of topology.

### Eulerian Cycle (Eulerian circuit, closed eulerian trail/path)

Eulerian trail (or Eulerian path) is a trail in a finite graph which visits every edge exactly once. 
An Eulerian circuit or Eulerian cycle is an Eulerian trail which starts and ends on the same vertex.

A eulerian cycle exists on an undirected graph if and only if the graph is connected and every vertex has an even degree.
A eulerian cycle exists on a directed graph if and only if the graph is connected and the in-degree of every vertex is equal to its out-degree. (Chinese postman problem)

### Eulerian Path

An undirected graph has Eulerian Path if following two conditions are true.
a) the graph is connected
b) If zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)

A graph is called Eulerian if it has an Eulerian Cycle and called Semi-Eulerian if it has an Eulerian Path.

https://www.geeksforgeeks.org/eulerian-path-and-circuit/

### Bridges in a graph

Concept: 
1. path, trail, walk, cycle, circuit
2. connected component (or component), bridge, articulation point (AP or cut vertex)

An edge in an undirected connected graph is a bridge iff removing it disconnects the graph.
A connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.

https://www.geeksforgeeks.org/bridge-in-a-graph/


### Fleury’s Algorithm for printing Eulerian trail or cycle:

The main idea: do not delete the bridge:

1. Make sure the graph has either 0 or 2 odd vertices.
2. If there are 0 odd vertices, start anywhere. Otherwise start at one of odd vertices.
3. From current vertex, move across the edge to the next vertex (DFS).  Delete the edge if it does not disconnect the graph.  i.e. If you have a choice between a bridge and a non-bridge, always choose the non-bridge.  If there is no no-bridge, just choose this one.
4. Stop when you run out of edges.

https://www.geeksforgeeks.org/fleurys-algorithm-for-printing-eulerian-path/

ConstructEulerTrail () {
    circuitpos = 0
    EulerTrail ( start ) // The starting vertex
}

EulerTrail ( u ) {
    for ( each vertex v adjacent to u ) {
        DeleteEdge (u , v )
        EulerTrail ( v )
    }
    circuit [ circuitpos ++] = u
}

### The Handshaking Theorem

    In every graph, the sum of the degrees of all vertices equals twice the number of edges.

    Every graph has an even number of odd vertices!

### Hierholzer’s Algorithm

  Complexity:
    Fleury’s Algorithm: O(E*E)
    Heirholzer’s Algorithm: O(E), i.e., linear time.

### Eulerian path in Directed Graph

    1. A directed graph has an eulerian circuit if and only if it is connected and each vertex has the same in-degree as out-degree.
    2. A directed graph has an eulerian path if and only if it is connected and each vertex except 2 have the same in-degree as out-degree, and one of those 2 vertices has out-degree with one greater than in-degree (this is the start vertex), and the other vertex has in-degree with one greater than out-degree (this is the end vertex).

    http://www.graph-magics.com/articles/euler.php

### USACO eulerian tour (Section 3.3)

use stack and DFS;
Why cannot you use queue and BFS?  
Can you use queue and DFS.

### DP review:



### Further Study:

Bridges in a graph
https://www.geeksforgeeks.org/bridge-in-a-graph/

Articulation Points (or Cut Vertices) in a Graph
https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/

Paths to travel each nodes using each edge (Seven Bridges of Königsberg)
https://www.geeksforgeeks.org/paths-travel-nodes-using-edgeseven-bridges-konigsberg/

