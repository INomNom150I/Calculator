
## Memorization Search

    Memoization or memoisation is an optimization technique used primarily to speed up computer programs by storing the results of expensive function calls and returning the cached result when the same inputs occur again. Memoization has also been used in other contexts (and for purposes other than speed gains), such as in simple mutually recursive descent parsing. Although related to caching, memoization refers to a specific case of this optimization, distinguishing it from forms of caching such as buffering or page replacement.

## Problem

    Given an integer matrix, find the length of the longest increasing path.
    From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

        Example 1:

        nums = [
          [9,9,4],
          [6,6,8],
          [2,1,1]
        ]

    Return 4
    The longest increasing path is [1, 2, 6, 9].


