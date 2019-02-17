### Interval Scheduling Problem

    Given a set {1, 2, …, n} of n requests, where ith request starts at time s(i) and finishes at time f(i), find a maximum-size subset of compatible requests. Two requests i and j are compatible if they do not overlap i.e., either f(i) <= s(j) or f(j) <= s(i).

    Example: Given 3 requests with s(1) = 1, f(1) = 3, s(2) = 2, f(2) = 4, s(3) = 3, f(3) = 5, the maximum-size subset of compatible requests is {1, 3}.

    https://en.wikipedia.org/wiki/Interval_scheduling

    Greedy algorithm: Select intervals one after another using some rule: Earliest start time, Shortest interval, Fewest conflicts, Earliest finish time (EFT algorithm)

        1. Select the interval which starts earliest (but not overlapping the already chosen intervals)
        2. Select the interval which is shortest (but not overlapping the already chosen intervals)
        3. Select the interval with the fewest conflicts with other remaining intervals (but still not overlapping the already chosen intervals)
        4. Select the interval which ends first (but still not overlapping the already chosen intervals)

    EFT Algorithm:
        Let R be the set of all requests
        schedule = {}
        while !R.empty():
            Choose a request i in R that has the smallest finish time
            Add i to schedule
            Delete all requests from R that are incompatible with i
        return schedule

    Implementation:
        Sorting intervals according to the right-most ends
        For every consecutive interval:
            If the left-most end is after the right-most end of the last selected interval then we select this interval
            Otherwise we skip it and go to the next interval

        sort the n requests in order of finish time
        schedule = {}
        last_finish = 0
        for i = 1 to n:
            if s(i) >= last_finish:
            Add i to schedule
            last_finish = f(i)
        return schedule

    Time complexity: O(nlogn + n) = O(nlogn)

### Weighted Interval Scheduling

        Job j starts at sj, finishes at fj, and has weight or value vj .
        Two jobs compatible if they don't overlap.
        Goal: find maximum weight subset of mutually compatible jobs. 

    https://www.geeksforgeeks.org/weighted-job-scheduling/
