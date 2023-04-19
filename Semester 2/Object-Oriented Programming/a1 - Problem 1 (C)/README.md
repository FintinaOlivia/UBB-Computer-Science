# Assignment 01

## Lab 1 activity

You should set up a C++ compiler and an IDE. Choose any IDE and compiler you prefer. Later on in the semester we will also work with the Qt framework. Microsoft Visual Studio 2022 can be integrated with Qt development tools.

If you choose Microsoft Visual Studio, the *Community* version is free.

Create a new C project and a simple “Hello, World!” C application.

**Assignment 1 consists of the following requirements and is due in week 2.**

## Requirements
- Write a **C application** (not C++!) with a menu based console interface which solves one of the problems below. 
- Menu entries are expected for: 
    - reading a vector of numbers from the console,
    - solving each of the 2 required functionalities,
    - exiting the program. 
- Each requirement must be resolved using at least one function. Functions communicate via input/output parameters and the return statement.
- Provide specifications for all functions.

## Problem Statements
1.  **a.** Generate all the prime numbers smaller than a given natural number `n`.\
**b.** Given a vector of numbers, find the longest increasing contiguous subsequence, such the sum of that any 2 consecutive elements is a prime number.

2.  **a.** Generate the first `n` prime numbers (`n` is a given natural number).\
**b.** Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.

3.	**a.** Print the Pascal triangle of dimension `n` of all combinations `C(m,k)` of m objects taken by `k, k = 0, 1, ..., m`, for line `m, where m = 1, 2, ..., n`.\
**b.** Given a vector of numbers, find the longest contiguous subsequence of prime numbers.

4.	**a.** Compute the approximated value of square root of a positive real number. The precision is provided by the user.\
**b.** Given a vector of numbers, find the longest contiguous subsequence such that the difference of any two consecutive elements is a prime number.

5.	**a.** Print the exponent of a prime number `p` from the decomposition in prime factors of a given number `n` (n is a non-null natural number).\
**b.** Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.

6.	**a.** Read a sequence of natural numbers (sequence ended by `0`) and determine the number of `0` digits of the product of the read numbers.\
**b.** Given a vector of numbers, find the longest contiguous subsequence such that the sum of any two consecutive elements is a prime number.

7.	**a.** Read sequences of positive integer numbers (reading of each sequence ends by `0`, reading of all the sequences ends by `-1`) and determine the maximum element of each sequence and the maxim element of the global sequence.\
**b.** Given a vector of numbers, find the longest contiguous subsequence such that all elements are in a given interval.

8.	**a.** Determine the value `x^n`, where `x` is a real number and `n` is a natural number, by using multiplication and squared operations.\
**b.** Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements have contrary signs.

9.	**a.** Decompose a given natural number in its prime factors.\
**b.** Given a vector of numbers, find the longest contiguous subsequence such that any consecutive elements contain the same digits.

10.	**a.** Decompose a given even natural number, greater than 2, as a sum of two prime numbers (Goldbach’s conjecture).\
**b.** Given a vector of numbers, find the longest contiguous subsequence such that any consecutive elements have at least 2 distinct digits in common.

11.	**a.** Determine the first `n` pairs of twin numbers, where n is a given natural and non-null number. Two prime numbers p and q are called twin if `q – p = 2`.\
**b.** Given a vector of numbers, find the longest decreasing contiguous subsequence.

12.	**a.** Determine all the numbers smaller than a given natural and non-null number `n` and that are relatively prime to n.\
**b.** Given a vector of numbers, find the longest contiguous subsequence with the maximum sum.

13.	**a.** Determine the first (and only) 8 natural numbers `(x1, x2,  …,  x8)` greater than 2 with the following property: all the natural numbers smaller than `xi` and that are relatively prime with `xi` (except for the number 1) are prime, `i =1,2, …, n`.\
**b.** Given a vector of numbers, find the longest contiguous subsequence such that any consecutive elements contain the same digits.
