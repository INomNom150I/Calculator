### Dynamic Programming and Probability

https://en.wikipedia.org/wiki/Stochastic_dynamic_programming

A certain species of fern thrives in lush rainy regions, where it typically rains almost every day. However, a drought is expected over the next n days, and a team of botanists is concerned about the survival of the species through the drought. Specifically, the team is convinced of the following hypothesis: the fern population will survive if and only if it rains on at least n/2 days during the n-day drought. In other words, for the species to survive there must be at least as many rainy days as non-rainy days. Local weather experts predict that the probability that it rains on a day i ∈ {1, . . . , n} is pi ∈ [0, 1], and that these n random events are independent. Assuming both the botanists and weather experts are correct, show how to compute the probability that the ferns survive the drought. Your algorithm should run in time O(n2).


 an (n + 1)×n matrix such that C[i][j] denotes the probability that after ith day there will have been j rainy days (i runs from 1 to n, j runs from 0 to n). Initialize:

C[1][0] = 1 - p[1]
C[1][1] = p[1]
C[1][j] = 0 for j > 1
Now loop over the days and set the values of the matrix like this:

C[i][0] = (1 - p[i]) * C[i-1][0]
C[i][j] = (1 - p[i]) * C[i-1][j] + p[i] * C[i - 1][j - 1] for j > 0
Finally, sum the values from C[n][n/2] to C[n][n] to get the probability of fern survival.


def prob_survival(daily_probabilities):
    days = len(daily_probabilities)
    days_needed = days / 2

    # An inner function to do the calculation.
    cached_odds = {}
    def prob_survival(day, rained):
        if days_needed <= rained:
            return 1.0
        elif days <= day:
            return 0.0
        elif (day, rained) not in cached_odds:
            p = daily_probabilities[day]
            p_a = p * prob_survival(day+1, rained+1)
            p_b = (1- p) * prob_survival(day+1, rained)
            cached_odds[(day, rained)] = p_a + p_b
        return cached_odds[(day, rained)]

    return prob_survival(0, 0)
And then you would call it as follows:

print(prob_survival([0.2, 0.4, 0.6, 0.8])

