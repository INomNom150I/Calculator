### State Space Reduction

https://www.hackerearth.com/practice/algorithms/dynamic-programming/state-space-reduction/tutorial/

#### state

A state is, in general, a point in a K-dimensional space, where  is called the number of dimensions in the solution. This may sound quite formal, but in fact, each person who solved at least one problem using dynamic programming approach used this concept.

#### rotate array

    If new state is only depends on only a few old stats in K-dimensional state space, we could use rotate array to save the old state. 

#### bitmask DP

    For K vertices in TSP problem, bitmask is used.  The total states could be K*(2<<K), which is huge.  For example, with K=32, the space is 128 billion.  We must have a way to do state space reduction.
