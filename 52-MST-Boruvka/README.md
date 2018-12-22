
### Boruvka’s algorithm
    Similar to Krusal or Prim, it combine the components with cheapest edge recursively and greedily.
    intially every vertex is one compent or tree.  Find the cheapest edge for every tree.  If two trees has common edge, union them.
    Recursively doing union this way until there is only one component/tree.

### How to represent graph (V, E): adjacent matrix/list, edge list

### How to repesent minimum spanning tree
    use edge list

### How to repesent the component (a forest)
    disjoint set: we can use array to represent set, which contains the set number
