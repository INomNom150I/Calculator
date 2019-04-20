
### Knapsack problem

    The knapsack problem or rucksack problem is a problem in combinatorial optimization.  We learned subset sum, which is also combination problem.  

    Given a universe U of n elements, a collection of subsets of U say S = {S1, S2…,Sm} where every subset Si has an associated cost. Find a minimum cost subcollection of S that covers all elements of U.

    https://en.wikipedia.org/wiki/Knapsack_problem


### Method to be used
    brute force
    greedy algorithm
    DP
    backtracking
    branch-and-bound
    divide and conquer

### Fractional Knapsack Problem

    Greedy based on sorting.

### 0-1 Knapsack Problem

    Given a set of n items numbered from 1 up to n, each with a weight w[i] and a value v[i], along with a maximum weight capacity W, what is the the maximum total value in the knapsack?

    initial state: dp[0] = 0;
    state transition: dp[c] = max(dp[c-w[i]]+v[i]) for all items if(w[i] <= c)
                   or dp[c, i] = max(cp[c,i], dp[c-w[i]] +v[i])

### Bounded Knapsack (Knapsack with Limited Repetitions)

    Multi-objective knapsack problem: Given a set of n items numbered from 1 up to n, each with a weight w[i], a value v[i] and a upper bound b[i], along with a maximum weight capacity W, what is the the maximum total value in the knapsack?

    0-1 knapsack ==> 0-m knapsack where m>=1 ? if b[i] = 1, it is 0-1 knapsack.
    dp[c] = max(dp[c-j*w[i]]+j*v[i]) for all items if(j*w[i] <= c) where j in [0, b[i])

    1. Translate it into 0-1 knapsack problem.
    2. Dijstra shortest path
    3. Multiple constraints: Related to packing problem?


### Unbounded Knapsack (Knapsack with Unlimited Repetitions)

    0-1 knapsack ==> 0-infinite knapsack ?

    Unlike 0-1 knapsack problem, the repetition of items is allowed.
    https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

### Multi-dimensional Knapsack

    The weight w[i] is a N-way vector, instead of scaler variable.  The Capacity is also N-way vector.  For example, 2-D vector for packing squres.

    Increasing height shelf algorithm:

### Multiple Knapsack

    It is also multi-dimensioanl in typical implementation. But it is different from Multi-dimensional Knapsack in that a subset of items can be selected.  For Bin Packing Problem (2-D knapsack), all items have to be packed to certain bins.

### Coin Change and Subset Sum problem

    1. minimum coins to represent one value
    2. number of ways to represent one value
    3. The sum of one sumset = one given value (one special case of 0-1 knapsack)

    All are relevant.

