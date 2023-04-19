# 💻 Assignment 07
## Requirements

- You will be given one of the problems below to solve
- The program must provide a menu-driven console user interface.
- Use classes to represent the following:
    - The `UI` class which implements the user interface
    - A `Services` class that implements the required functionalities
    - The domain entity (`complex`,  `expense`,  `student`, `book`) class
    - A `Repository` class whose job it is to store the domain entity instances. This class will have three implementations: (1) a `MemoryRepository`, which stores domain instances in memory (just like in previous assignments); (2) a `TextFileRepository`, which persists domain entities to a text file, and (3) a `BinaryFileRepository`, which persists domain entities using object serialization with [Pickle](https://docs.python.org/3.10/library/pickle.html). You should be able to switch between which repository is in use by changing the instantiated class. When using a file-backed repository, changes made while running the program must be persisted across runs.  
- Have 10 programmatically generated entries in the application at start-up. Save these to the text/binary input files.
- Unit tests and specifications for non-UI functions related to the first functionality.

## Problem Statements
### 1. Complex numbers
Manage a list of complex numbers in `a+bi` form and provide the user the following features:
1. Add a number. The number is read from the console.
2. Display the list of numbers.
3. Filter the list so that it contains only the numbers between indices `start` and `end`, where these values are read from the console.
4. Undo the last operation that modified program data. This step can be repeated. The user can undo only those operations made during the current run of the program.

---
### 2. Expenses
Manage a list of expenses. Each expense has a `day` (integer between 1 and 30), `amount` of money (positive integer) and expense `type` (string). Provide the following features:
1. Add an expense. Expense data is read from the console.
2. Display the list of expenses.
3. Filter the list so that it contains only expenses above a certain value read from the console.
4. Undo the last operation that modified program data. This step can be repeated. The user can undo only those operations made during the current run of the program.

---
### 3. Students
Manage a list of students. Each student has an `id` (integer, unique), a `name` (string) and a `group` (positive integer). Provide the following features:
1. Add a student. Student data is read from the console.
2. Display the list of students.
3. Filter the list so that students in a given group (read from the console) are deleted from the list.
4. Undo the last operation that modified program data. This step can be repeated. The user can undo only those operations made during the current run of the program.

---
### 4. Books
Manage a list of books. Each book has an `isbn` (string, unique), an `author` and a `title` (strings). Provide the following features:
1. Add a book. Book data is read from the console.
2. Display the list of books.
3. Filter the list so that book titles starting with a given word are deleted from the list.
4. Undo the last operation that modified program data. This step can be repeated. The user can undo only those operations made during the current run of the program.

## Bonus possibility (0.1p, deadline week 11)
- In addition to the file-based implementations above, implement a repository that uses either a JSON or an XML file for storage (at your choice).

## Bonus possibility (0.1p, deadline week 11)
- Use a `settings.properties` file to decide which of the repository implementations to use. At startup, the program reads this input file and instantiates the correct repository. This allows changing the program's input file format without changing its source code.

## Bonus possibility (0.1p, deadline week 11)
- Implement a database-backed (SQL or NoSQL) repository. Use the database system’s update functionalities properly (don’t rewrite the entire database at each operation).
