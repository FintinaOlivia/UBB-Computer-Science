# :computer: Assignment 01

## Requirements
- Solve one problem statement from each set
- Write the solution to each problem statement in its corresponding Python module (`p1.py`, `p2.py` and `p3.py` respectively).
- Use functions, input parameters and return values
- Each function only does one thing!
- Do not use global variables
- Provide the user relevant messages regarding expected input and the meaning of the program’s output.
- Assignment should be **completed by week 2, hard deadline is week 3**.

## Problem Statements
### First Set
1. Generate the first prime number larger than a given natural number `n`.
2. Given natural number `n`, determine the prime numbers `p1` and `p2` such that `n = p1 + p2` (check the Goldbach hypothesis).
3. For a given natural number `n` find the minimal natural number `m` formed with the same digits. (e.g. `n=3658, m=3568`).
4. For a given natural number `n` find the largest natural number written with the same digits. (e.g. `n=3658, m=8653`).
5. Generate the largest prime number smaller than a given natural number `n`. If such a number does not exist, a message should be displayed.

### Second Set
6. Determine a calendar date (as year, month, day) starting from two integer numbers representing the year and the day number inside that year (e.g. day number 32 is February 1st). Take into account leap years. Do not use Python's inbuilt date/time functions.
7. Determine the twin prime numbers `p1` and `p2` immediately larger than the given non-null natural number `n`. Two prime numbers `p` and `q` are called twin if `q - p = 2`.
8. Find the smallest number `m` from the Fibonacci sequence, defined by `f[0]=f[1]=1`, `f[n]=f[n-1] + f[n-2]`, for `n > 2`, larger than the given natural number `n`. (e.g. `for n = 6, m = 8`).
9. Consider a given natural number `n`. Determine the product `p` of all the proper factors of `n`.
10. The palindrome of a number is the number obtained by reversing the order of its digits (e.g. the `palindrome of 237 is 732`). For a given natural number `n`, determine its palindrome.
11. The numbers `n1` and `n2` have the property `P` if their writing in base 10 uses the same digits (e.g. `2113 and 323121`). Determine whether two given natural numbers have property `P`.

### Third Set
12. Determine the age of a person, in number of days. Take into account leap years, as well as the date of birth and current date `(year, month, day)`. Do not use Python's inbuilt date/time functions.
13. Determine the `n-th`  element of the sequence `1,2,3,2,5,2,3,7,2,3,2,5,...` obtained from the sequence of natural numbers by replacing composed numbers with their prime divisors, without memorizing the elements of the sequence.
14. Determine the `n-th` element of the sequence `1,2,3,2,2,5,2,2,3,3,3,7,2,2,3,3,3,...` obtained from the sequence of natural numbers by replacing composed numbers with their prime divisors, each divisor `d` being written `d` times, without memorizing the elements of the sequence.
15. Generate the largest perfect number smaller than a given natural number `n`. If such a number does not exist, a message should be displayed. A number is perfect if it is equal to the sum of its divisors, except itself. (e.g.  `6 is a perfect number, as 6=1+2+3`).
