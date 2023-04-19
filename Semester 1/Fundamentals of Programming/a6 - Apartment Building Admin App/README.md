# :computer: Assignment 06

## Requirements
- You will be given one of the problems below to solve
- In addition to **procedural programming**, also use **modular programming** by having a **UI** module, a **Functions** module and a **Start** module
- The **UI** module provides a command-based console user interface that accepts given commands **exactly** as stated
- Handle the case of incorrect user input by displaying error messages. The program must not crash regardless of user input.
- Use the built-in `list` or `dict` compound types to represent entities in the problem domain and access/modify them using *getter* and *setter* functions
- Use Python's [exception mechanism](https://docs.python.org/3/tutorial/errors.html) so that functions can signal that an exceptional situation, or error, has happened.
- Provide **specifications** for all non-UI functions (except getters and setters), and tests for all non-UI functions related to functionalities **(A)** and **(B)**
- Have at least 10 randomly generated items in your application at program startup
- Deadline for maximum grade is **week 8**, hard deadline is **week 11**.

## Problem Statements
### 1. Numerical List
A math teacher needs a program to help students test different properties of complex numbers, provided in the `a+bi` form (we assume `a` and `b` are integers for simplicity). Write a program that implements the functionalities exemplified below:

**(A) Add a number**\
`add <number>`\
`insert <number> at <position>`\
e.g.\
`add 4+2i` – appends `4+2i` to the list\
`insert 1+1i at 1` – insert number `1+i` at position `1` in the list (positions are numbered starting from `0`)

**(B) Modify numbers**\
`remove <position>`\
`remove <start position> to <end position>`\
`replace <old number> with <new number>`\
e.g.\
`remove 1` – removes the number at position `1`\
`remove 1 to 3` – removes the numbers at positions `1`,`2`, and `3`\
`replace 1+3i with 5-3i` – replaces all occurrences of number `1+3i` with the number `5-3i`

**(C) Display numbers having different properties**\
`list`\
`list real <start position> to <end position>`\
`list modulo [ < | = | > ] <number>`\
e.g.\
`list` – display all numbers\
`list real 1 to 5` – display the real numbers (imaginary part `=0`) between positions `1` and `5`\
`list modulo < 10` – display all numbers with modulo `<10`\
`list modulo = 5` – display all numbers with modulo `=5`

**(D) Filter the list**\
`filter real`\
`filter modulo [ < | = | > ] <number>`\
e.g.\
`filter real` – keep only numbers having imaginary part `=0`\
`filter modulo < 10` – keep only numbers having modulo `<10`\
`filter modulo > 6` – keep only those numbers having modulo `>6`

**(E) Undo**\
`undo` – the last operation that modified program data is reversed. The user can undo all operations performed since program start by repeatedly calling this function.

---
### 2. Contest
During a programming contest, each contestant had to solve 3 problems (named `P1`, `P2` and `P3`). Afterwards, an evaluation committee graded the solutions to each of the problems using integers between `0` and `10`. The committee needs a program that will allow managing the list of scores and establishing the winners. Write a program that implements the functionalities exemplified below:

**(A) Add the result of a new participant**\
`add <P1 score> <P2 score> <P3 score>`\
`insert <P1 score> <P2 score> <P3 score> at <position>`\
e.g.\
`add 3 8 10` – add a new participant with scores `3`,`8` and `10` (scores for `P1`, `P2`, `P3` respectively)\
`insert 10 10 9 at 5` – insert scores `10`, `10` and `9` at position `5` in the list (positions numbered from `0`)

**(B) Modify scores**\
`remove <position>`\
`remove <start position> to <end position>`\
`replace <old score> <P1 | P2 | P3> with <new score>`\
e.g.\
`remove 1` – set the scores of the participant at position `1` to `0`\
`remove 1 to 3` – set the scores of participants at positions `1`, `2` and `3` to `0`\
`replace 4 P2 with 5` – replace the score obtained by participant `4` at `P2` with `5`

**(C) Display participants whose score has different properties.**\
`list`\
`list sorted`\
`list [ < | = | > ] <score>`\
e.g.\
`list` – display participants and all their scores\
`list < 4` – display participants with an average score `<4`\
`list = 6` – display participants with an average score `=6`\
`list sorted` – display participants sorted in decreasing order of average score

**(D) Establish the podium**\
`top <number>`\
`top <number> <P1 | P2 | P3>`\
`remove [ < | = | > ] <score>`\
e.g.\
`top 3` – display the 3 participants having the highest average score, in descending order of average score\
`top 4 P3` – display the 4 participants who obtained the highest score for P3, sorted descending by that score\
`remove < 70` – set the scores of participants having an average score `<70` to `0`\
`remove > 89` – set the scores of participants having an average score `>89` to `0`

**(E) Undo**\
`undo` – the last operation that modified program data is reversed. The user can undo all operations performed since program start by repeatedly calling this function.

---
### 3. Family Expenses
A family wants to manage their monthly expenses. They need an application to store, for a given month, all their expenses. Each expense will be stored using the following elements: `day` (*of the month in which it was made, between 1 and 30, for simplicity*), `amount of money` (positive integer) and `expense type` (one of: `housekeeping`, `food`, `transport`, `clothing`, `internet`, `others`). Write a program that implements the functionalities exemplified below:

**(A) Add a new expense**\
`add <sum> <category>`\
`insert <day> <sum> <category>`\
e.g.\
`add 10 internet` – add to the current day an expense of `10 RON` for internet\
`insert 25 100 food` – insert to day 25 an expense of `100 RON` for food

**(B) Modify expenses**\
`remove <day>`\
`remove <start day> to <end day>`\
`remove <category>`\
e.g.\
`remove 15` – remove all expenses for day 15\
`remove 2 to 9` – remove all expenses between days 2 and 9\
`remove food` – remove all expenses for food

**(C) Display expenses with different properties**\
`list`\
`list <category>`\
`list <category> [ < | = | > ] <value>`\
e.g.\
`list` – display all expenses\
`list food` – display all the expenses for `food`\
`list food > 5` - display all `food` expenses with an amount of money `>5`\
`list internet = 44` - display all `internet` expenses with an amount of money `=44`

**(D) Filter expenses**\
`filter <category>`\
`filter <category> [ < | = | > ] <value>`\
e.g.\
`filter food` – keep only expenses in category `food`\
`filter books < 100` – keep only expenses in category books with amount of money `<100 RON`\
`filter clothing = 59` – keep only expenses for clothing with amount of money `=59 RON`

**(E) Undo**\
`undo` – the last operation that modified program data is reversed. The user can undo all operations performed since program start by repeatedly calling this function.

---
### 4. Bank Account
John wants to manage his bank account. To do this, he needs an application to store all the bank transactions performed on his account during a month. Each transaction is stored in the application using the following elements: `day` (of the month in which the transaction was made, between 1 and 30 for simplicity), `amount of money` (transferred, positive integer), `type` (`in` - into the account, `out` – from the account), and `description`. Write a program that implements the functionalities exemplified below:

**(A) Add transaction**\
`add <value> <type> <description>`\
`insert <day> <value> <type> <description>`\
e.g.\
`add 100 out pizza` – add to the current day an `out` transaction of `100 RON` with the *"pizza"* description\
`insert 25 100 in salary` – insert to day 25 an `in` transaction of `100 RON` with the *“salary”* description

**(B) Modify transactions**\
`remove <day>`\
`remove <start day> to <end day>`\
`remove <type>`\
`replace <day> <type> <description> with <value>`\
e.g.\
`remove 15` – remove all transactions from day 15\
`remove 5 to 10` – remove all transactions between days 5 and 10\
`remove in` – remove all `in` transactions\
`replace 12 in salary with 2000` – replace the amount for the `in` transaction having the *“salary”* description from day 12 with `2000 RON`

**(C) Display transactions having different properties**\
`list`\
`list <type>`\
`list [ < | = | > ] <value>`\
`list balance <day>`\
e.g.\
`list` – display all transactions\
`list in` – display all `in` transactions\
`list > 100` - display all transactions having an amount of money `>100`\
`list = 67` - display all transactions having an amount of money `=67`\
`list balance 10` – compute the account’s balance at the end of day 10. This is the sum of all `in` transactions, from which we subtract `out` transactions occurring before or on day 10

**(D) Filter**\
`filter <type>`\
`filter <type> <value>`\
e.g.\
`filter in` – keep only `in` transactions\
`filter in 100` – keep only `in` transactions having an amount of money smaller than `100 RON`

**(E) Undo**\
`undo` – the last operation that modified program data is reversed. The user can undo all operations performed since program start by repeatedly calling this function.

---
### 5. Apartment Building Administrator
Jane is the administrator of an apartment building and she wants to manage the monthly expenses for each apartment. Each expense is stored using the following elements: `apartment` (*number of apartment, positive integer*), `amount` (*positive integer*), `type` (*from one of the predefined categories `water`, `heating`, `electricity`, `gas` and `other`*). Write a program that implements the functionalities exemplified below:

**(A) Add new transaction**\
`add <apartment> <type> <amount>`\
e.g.\
`add 25 gas 100` – add to apartment 25 an expense for `gas` in amount of `100 RON`

**(B) Modify expenses**\
`remove <apartment>`\
`remove <start apartment> to <end apartment>`\
`remove <type>`\
`replace <apartment> <type> with <amount>`\
e.g.\
`remove 15` – remove all expenses for apartment 15\
`remove 5 to 10` – remove all expenses for apartments between 5 and 10\
`remove gas` – remove all `gas` expenses from all apartments\
`replace 12 gas with 200` – replace the amount of the expense with type `gas` for apartment 12 with `200 RON`

**(C)	Display expenses having different properties**\
`list`\
`list <apartment>`\
`list [ < | = | > ] <amount>`\
e.g.\
`list` – display all expenses\
`list 15` – display all expenses for apartment 15\
`list > 100` - display all apartments having total expenses `>100 RON`\
`list = 17` - display all apartments having total expenses `=17 RON`

**(D) Filter**\
`filter <type>`\
`filter <value>`\
e.g.\
`filter gas` – keep only expenses for `gas`\
`filter 300` – keep only expenses having an amount of money smaller than 300 RON

**(E) Undo**\
`undo` – the last operation that modified program data is reversed. The user can undo all operations performed since program start by repeatedly calling this function.
