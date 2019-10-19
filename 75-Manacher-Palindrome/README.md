### Manacher's Algorithm

    The longest palindromic substring or longest symmetric factor problem is the problem of finding a maximum-length contiguous substring of a given string that is also a palindrome. 

    Naive algorithm: generate all substring and do the check O(n**3)
                    or check if the longest substring is a palindrome (from longest to shortest)
    find longest palindrome for each character as the center
    DP algorithm: O(n**2)
    Manacher's algorithm: O(n)

    https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/

