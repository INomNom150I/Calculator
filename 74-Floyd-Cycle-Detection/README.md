### Detect loop in a linked list

    1. use hash table
    2. mark visited node, like graph traversal
    3. Floyd Cycle Detection Algorithm

    https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
    https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

### Detect and Remove Loop in a Linked List

    Write a function that checks whether a given Linked List contains loop and then removes the loop and returns trueif loop is present.

    1. Check one by one
    2. Floyd’s Cycle-Finding Algorithm

### The key point of Cycle detection

    Double pointers:  They can be used in linked list, in graph, or even in array.

### How to detect cycle faster?

    Just like DP, it is time–space tradeoffs!  Use more memory 
    A simple one: Use hash table to record the node visited.

