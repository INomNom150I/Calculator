
## KD-tree (K-dimensional range tree)

    1. make a set (what data structure: vector, list or set?)
    2. find: find the parent?
    3. union: union the parent?

#### Compare with
    1. K-tree

## Application

    Disjoint set data structure is used to track a set of elements partitioned into non-overlapping (or disjoint) subset.
        1. add to new subset
        2. merge existing subsets.
        3. Check whether two elements are in the same subset (we already used in Kruskal MST)

## Optimization

    1. path compression (update the parent after return, so everybody points to the parent along the search path) 
    2. union by rank (or others): Why do we use rank?  What is the benefit?
