

## Array split vs combination set

    Array split: it must be continuous: (n-k)**(k-1)
    combination: C(n, k)


## DP and binary search:

    Given an array which consists of non-negative integers and an integer k, you can split the array into k non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these k subarrays.

    example: nums = [7,2,5], k = 2
        divide them into tow subarrays:
            1. [7,2], [5] ==> largest is 9
            2. [7],[2,5] ==> largest is 7

        so the minmum of largest sum is 7

    Solution:
        1. brute force
        2. DP: top-down, bottom up
        3. binary search


## Summary of binary search
    1. find l and r (floor vs ceiling)
    2. find the mid = (l+r)/2 (sometimes use l+(r-l)/2 to avoid overflow issue)
    3. find one way to update l or r
    4. when i==r or l<r, do we find the solution?

