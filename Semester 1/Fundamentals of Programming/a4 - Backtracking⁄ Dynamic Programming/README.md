# :computer: Assignment 04 - Problem Solving Methods

## Requirements
- You will have to solve two problem statements from the list below, one using the **backtracking** programming method and one using the **dynamic programming** method.
- For the backtracking problem, implement both an iterative as well as a recursive algorithm (**deadline is week 5**).
- For the dynamic programming problem, implement both the naive, non-optimized version as well as the dynamic programming version (**deadline is week 6**). 
- For the dynamic programming implementation, display the data structure used to memorize the intermediate results and be able to explain how it works. 
- For all implementations understand and be able to explain the computational complexity with regards to runtime.

## Problem Statements
### Backtracking
1. A number of `n` coins are given, with values of a<sub>1</sub>, ..., a<sub>n</sub>  and a value `s`. Display all payment modalities for the sum `s`. If no payment modality exists print a message.
2. Consider a positive number `n`. Determine all its decompositions as sums of prime numbers.
3. The sequence a = a<sub>1</sub>, ..., a<sub>n</sub> with integer elements is given. Determine all strictly increasing subsequences of sequence `a` (conserve the order of elements in the original sequence).
4. A player at `PRONOSPORT` wants to choose score options for four games. The options may be `1`, `X`, `2`. Generate all possible alternatives, knowing that:
- The last score option may not be `X`
- There should be no more than two score options of `1`
5. The sequence a = a<sub>1</sub>, ..., a<sub>n</sub> with distinct integer numbers is given. Determine all subsets of elements having the sum divisible by a given `n`.
6. Generate all sequences of `n` parentheses that close correctly. Example: for `n=4` there are two solutions: `(())` and `()()`
7. Generate all subsequences of length `2n+1`, formed only by `0`, `-1` or `1`, such that a<sub>1</sub> = 0, ..., a<sub>2n+1</sub>= 0 and |a<sub>i+1</sub> - a<sub>i</sub>| = 1 or 2, for any 1 ≤ i ≤ 2n.
8. Consider `n` points in a plane, given by their coordinates. Determine all subsets with at least three elements formed by collinear points. If the problem has no solution, give a message.
9. The sequence a = a<sub>1</sub>, ..., a<sub>n</sub> with distinct integer elements is given. Determine all subsets of at least two elements with the property:
- The elements in the subset are in increasing order
- Any two consecutive elements in the subsequence have at least one common digit
10. A group of `n` (n<=10) persons, numbered from `1` to `n` are placed on a row of chairs, but between every two neighbor persons (e.g. persons 3 and 4, or persons 7 and 8) some conflicts appeared. Display all the possible modalities to replace the persons, such that between any two persons in conflict stay one or at most two other persons.
11. Two natural numbers `m` and `n` are given. Display in all possible modalities the numbers from `1` to `n`, such that between any two numbers on consecutive positions, the difference in absolute value is at least `m`. If there is no solution, display a message.
12. Consider the natural number `n` (n<=10) and the natural numbers a<sub>1</sub>, ..., a<sub>n</sub>. Determine all the possibilities to insert between all numbers a<sub>1</sub>, ..., a<sub>n</sub> the operators `+` and `–` such that by evaluating the expression the result is positive.
13. The sequence a<sub>1</sub>, ..., a<sub>n</sub> of distinct integer numbers is given. Display all subsets with a mountain aspect. A set has a mountain aspect if the elements increase up to a point and then they decrease. E.g. `10, 16, 27, 18, 14, 7`.
14. Generate all numbers of `n` digits with the property that no number has two identical neighboring subsequences. For example, for `n=6`, `121312` is correct, and `121313` and `132132` are not correct.

### Dynamic Programming
1. Determine the longest common subsequence of two given sequences. Subsequence elements are not required to occupy consecutive positions. For example, if `X = "MNPNQMN"` and `Y = "NQPMNM"`, the longest common subsequence has length `4`, and can be one of `"NQMN"`, `"NPMN"` or `"NPNM"`. Determine and display both the length of the longest common subsequence as well as at least one such subsequence.
2. Given the set of positive integers `S` and the natural number `k`, display one of the subsets of `S` which sum to `k`. For example, if `S = { 2, 3, 5, 7, 8 }` and `k = 14`, subset `{ 2, 5, 7 }` sums to `14`.
3. Given the set of positive integers `S`, partition this set into two subsets `S1` and `S2` so that the difference between the sum of the elements in `S1` and `S2` is minimal. For example, for set `S = { 1, 2, 3, 4, 5 }`, the two subsets could be `S1 = { 1, 2, 4 }` and `S2 = { 3, 5 }`. Display at least one of the solutions.
4. Given an `n * n` square matrix with integer values, find the maximum length of a snake sequence. A snake sequence begins on the matrix's top row (coordinate `(0, i), 0 <= i < n`). Each element of the sequence, except the first one, must have a value `±1` from the previous one and be located directly below, or directly to the right of the previous element. For example, element `(i, j)` can be succeded by one of the `(i, j + 1)` or `(i + 1, j)` elements. Display the length as well as the sequence of coordinates for one sequence of maximum length. 
5. Maximize the profit when selling a rod of length `n`. The rod can be cut into pieces of integer lengths and pieces can be sold individually. The prices are known for each possible length. For example, if rod length `n = 7`, and the price array is `price = [1, 5, 8, 9, 10, 17, 17]` (the price of a piece of length `3` is `8`), the maximum profit is `18`, and is obtained by cutting the rod into 3 pieces, two of length two and one of length 3. Display the profit and the length of rod sections sold to obtain it.
6. Given an array of integers `A`, maximize the value of the expression `A[m] - A[n] + A[p] - A[q]`, where `m, n, p, q` are array indices with `m > n > p > q`. For `A = [30, 5, 15, 18, 30, 40]`, the maximum value is `32`, obtained as `40 - 18 + 15 - 5`. Display both the maximum value as well as the expression used to calculate it.
7. Given a set of integers `A`, determine if it can be partitioned into two subsets with equal sum. For example, set `A = { 1, 1, 1, 1, 2, 3, 5 }` can be partitioned into sets `A1 = { 1, 1, 2, 3 }` and `A2 = { 1, 1, 5 }`, each of them having sum `7`. Display one such possibility.
