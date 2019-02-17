### Tournament Tree

Tournament tree is a complete binary tree n external nodes and n-1 internal nodes. The external nodes represent the players and internal nodes represent the winner of the match between the two players.

        Complete binary tree with nexternal nodes and n–1 internal nodes.
        External nodes represent tournament players.
        Each internal node represents a match played between its two children; the winner of the match is stored at the internal node.
        Root has overall winner

    https://www.geeksforgeeks.org/tournament-tree-and-binary-heap/

### Properties of Tournament Tree

    1. It is rooted tree i.e. the links in the tree and directed from parents to children and there is a unique element with no parents.
    2. The key value of the parent node has less than or equal to that node to general any comparison operators can be used as long as the relative values of parent-child are invariant throughout the tree. The tree is a parent ordering of the keys.
    3. Trees with a number of nodes not a power of 2 contain holes which is general may be anywhere in the tree.
    4. Tournament tree is a proper generalization of heaps which restrict a node to at most two children.
    5. The tournament tree is also called selection tree.
    6. The root of the tournament tree represents overall winner of the tournament.

### Types of tournament Tree

    There are mainly two type of tournament tree,

        Winner tree
        Loser tree

#### Winner tree
The complete binary tree in which each node represents the smaller or greater of its two children is called a winner tree. The smallest or greater node in the tree is represented by the root of the tree. The winner of the tournament tree is the smallest or greatest n key in all the sequences. It is easy to see that the winner tree can be computed in O(logn) time.

#### Loser Tree
The complete binary tree for n players in which there are n external nodes and n-1 internal nodes then the tree is called loser tree. The loser of the match is stored in internal nodes of the tree. But in this overall winner of the tournament is stored at tree [0]. The loser is an alternative representation that stores the loser of a match at the corresponding node. An advantage of the loser is that to restructure the tree after a winner tree been output, it is sufficient to examine node on the path from the leaf to the root rather than the sibling of nodes on this path.


### Application of Tournament Tree

    It is used for finding the smallest and largest element in the array.
    It is used for sorting purpose.
    Tournament tree may also be used in M-way merges.
    Tournament replacement algorithm selection sort is used to gather the initial run for external sorting algorithms.

### Tournament sort

    https://en.wikipedia.org/wiki/Tournament_sort

