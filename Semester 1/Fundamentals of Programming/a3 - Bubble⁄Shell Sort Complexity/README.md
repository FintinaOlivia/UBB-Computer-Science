# :computer: Assignment 03 - Algorithm Complexity

## Requirements
- Calculate the complexity of the sorting algorithms you've implemented for the previous assignment. You may use additional resources for help, but you have to understand and be able to explain the complexity for both the **best case** as well as **worst case**. You can show this on screen or written on paper.
- Update the program created for the previous assignment by adding the following three additional menu entries -- one for ***best case***, one for ***average case*** and the last one for ***worst case***. When the user selects one of these, the program will time and illustrate the runtime of the implemented algorithms by sorting 5 data structures, each having twice the number of elements of the previous one. The elements of the data structure must be in accordance with the current case. See the example below.

## Example
- Let's say that as part of **A2** you've implemented BubbleSort and ShellSort. Let's say the user wishes to see the behaviour of these algorithms in the worst case. Your program will generate five lists (e.g., lenghts `500`, `1000`, `2000`, `4000` and `8000` elements) in which elements are in worst case configuration (for bubble sort, this happens if the list is already sorted, but in reverse). Then, you will time how long it takes to sort each list using a module such as [timeit](https://docs.python.org/3/library/timeit.html), and display the results on the console.
- In case the algorithm takes too long/little, you can adjust the list lenghts (e.g., permutation sort)
- Make sure that all calls to the sorting algorithms use the same input lists.
- Make sure the sorting algorithms do not perform additional work (e.g., displaying on the console, as required for **A2**)
- Display the results (list length, sort duration) in a way that allows users to see the progression of the runtime.
