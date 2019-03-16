
### BFPRT(Blum, Floyd, Pratt, Rivest, Tarjan)

    Find the top K smallest/biggest from N elements
    We already talked about Top-K problem as one of Binary Search examples.  The complexity is O(NlogN).  If we use quick select or heap select, it is O(NlogK).  BFPRT is a linear time algorithm in worst case.
    
    https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

### The median of medians problem

    Median of medians finds an approximate median in linear time only, which is limited but an additional overhead for quickselect. When this approximate median is used as an improved pivot, the worst-case complexity of quickselect reduces significantly from quadratic to linear, which is also the asymptotically optimal worst-case complexity of any selection algorithm. In other words, the median of medians is an approximate median-selection algorithm that helps building an asymptotically optimal, exact general selection algorithm (especially in the sense of worst-case complexity), by producing good pivot elements

    Median of medians can also be used as a pivot strategy in quicksort, yielding an optimal algorithm, with worst-case complexity O(n log n). Although this approach optimizes the asymptotic worst-case complexity quite well, it is typically outperformed in practice by instead choosing random pivots for its average O(n) complexity for selection and average O(n log n) complexity for sorting, without any overhead of computing the pivot.

    Similarly, Median of medians is used in the hybrid introselect algorithm as a fallback for pivot selection at each iteration until kth largest is found. This again ensures a worst-case linear performance, in addition to average-case linear performance: introselect starts with quickselect (with random pivot, default), to obtain good average performance, and then falls back to modified quickselect with pivot obtained from median of medians if the progress is too slow. Even though asymptotically similar, such a hybrid algorithm will have a lower complexity than a straightforward introselect up to a constant factor (both in average-case and worst-case), at any finite length.

