# Assignment 02

## Requirements
Implement a menu-driven console application to help visualize the way sorting algorithms work. You will be given two of the algorithms from the list below to implement (one from each set). When started, the program will print a menu with the following options:
- Generate a list of `n` random natural numbers. Generated numbers must be between `0` and `100`.
- Sort the list using the first algorithm. (see **NB!** below)
- Sort the list using the second algorithm. (see **NB!** below)
- Exit the program

## NB!
Before starting each sort, the program will ask for the value of parameter `step`. During sorting, the program will display the partially sorted list on the console each time it makes `step` operations or passes, depending on the algorithm (e.g., if `step=2`, display the partially sorted list after each 2 element swaps in bubble sort, after each 2 element insertions in insert sort, after every 2nd generation of a permutation in permutation sort etc.).

## Implementation requirements
- Write a function for each sorting algorithm; each function should take as parameter the list to be sorted and the value of parameter `step` that was read from the console.
- Functions communicate using input parameter(s) and return values (**DO NOT use global, or module-level variables**)
- Provide the user with a menu-driven console-based user interface. Input data should be read from the console and the results printed to the console. At each step, the program must provide the user the context of the operation (never display an empty prompt).
- You may use Internet resources to research the sorting algorithm, but you must be able to explain **how** and **why** they work in detail

## Sorting algorithms 
### Basic set
- Bubble Sort
- Cocktail Sort
- Insert Sort
- Permutation Sort
- Selection Sort

### Advanced set
- Shell Sort
- Comb Sort
- Gnome Sort
- Stooge Sort
- Strand Sort

