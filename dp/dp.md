# MIND MAP FOR DP PROBLEMS

## MINDSET:
1.  Break a problem into smaller subproblems.
2.  How to get the answer for a bigger problem using smaller subproblems.
3.  What is the smallest subproblem which is trivial to solve.
4.  What is the biggest subproblem.

---

### HOW TO SOLVE A DP PROBLEM?
1.  **Think about subproblems or states/parameters.**
    * Define the subproblem, e.g., `dp[k]` = the k-th state of the Fibonacci series.
2.  **Think about the relationship between smaller subproblems to compute the bigger problem (transition/relation).**
    * Establish the recurrence relation, e.g., `dp[k] = dp[k-1] + dp[k-2]`.
3.  **Identify where the above relation does not work (trivial/base case).**
    * Define the initial conditions, e.g., `dp[0] = 0`, `dp[1] = 1`.
4.  **Determine the final state or the bigger subproblem to solve.**
    * This is the target you want to compute, e.g., `dp[n]`.