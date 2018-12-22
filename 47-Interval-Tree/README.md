
## Tree Camp

    During last tree camp, we reviewed BST, AVL.  We also learned splay tree and red-black tree.  We introduce the skip list, which use randomization to alleviate the balance issue with BST.  Treap(Tree +heap) is another data structure with the similar purpose, but balance is not guranteed as RB or AVL tree.
    This time, we will rewrite the RB tree.  We also complete the skip list (remove or deletion) case.  Search or traversal is not changed.  In addition, we learn interval tree and k-d tree this time.

## Interval tree (Range Query: RQ)

    1. augmented tree to hold intervals. Specifically, it allows one to efficiently find all intervals that overlap with any given interval or point.
    2. key is interval: It can be start of any interval. [low, high] [start, end]

#### Why augmented tree? Balance.

#### Compare with
    1. interval array 
    2. segment tree
    3. range tree (alternative solution, k-d tree)
    4. interval graph (Intersection Graph, perfect graph)

https://www.geeksforgeeks.org/interval-tree/
https://en.wikipedia.org/wiki/Interval_tree
http://www.dgp.toronto.edu/people/JamesStewart/378notes/22intervals/

## Application

Interval tree is mainly a geometric data structure and often used for windowing queries, for instance, to find all roads on a computerized map inside a rectangular viewport, or to find all visible elements inside a three-dimensional scene

## Operation

    1. insert
    2. remove
    3. query
    4. how to construct the interval tree
