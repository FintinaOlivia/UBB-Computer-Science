# Assignment 02-03

## Requirements
- Each student will be given one of the problems below.
- The solution must use the **C language**.
- The problem should be solved over 2 iterations, due `Week 3` and `Week 4`:

### Week 3
- Solve at least requirements **a** and **b**.
- The vector used in the repository can be statically allocated.

### Week 4
- Solve all problem requirements.
- Define a vector structure with specific operations using a dynamically allocated array.
- Use modular programming.
- Source code must be specified and include tests for all non-UI functions
- The program must not leak memory!
- Use a layered architecture for your application (domain, repository, controller, UI). User interface, domain and data access elements will be stored in different modules. The user interface module will only contain the user interface part.
- Have at least 10 entries available at application startup.
- Handle user input errors gracefully (replace program crashes with nice error messages :blush:).

## Bonus possibilities
1. Implement the following requirements using function pointers **[deadline: week 4, bonus: 0.1p]**:
    - For requirement **b**, add a different type of filtering (of your choice).
    - For requirement **c**, add descending sorting. The user should choose the type of sort and the program will show the list of entities accordingly.
2. Provide 2 different implementations for the undo/redo functionality: one using a list of operations (this approach is a precursor of the [Command design pattern](https://en.wikipedia.org/wiki/Command_pattern)) and one where each state of the repository is recorded (this approach is not unlike the [Memento design pattern](https://en.wikipedia.org/wiki/Memento_pattern)). Implement your dynamic array generically, such that it can contain any type of elements (use void*). Use this structure for your repository, as well as to implement both undo/redo functionalities **[deadline: week 5, bonus: 0.1p]**.

## Problem Statements

### Pharmacy
John is the administrator of the *“Smiles”* Pharmacy. He needs a software application to help him manage his pharmacy's medicine stocks. Each **Medicine** has the following attributes: `name`, `concentration`, `quantity` and `price`. John wants the application to help him in the following ways:\
**(a)** Add, delete or update a medicine. A medicine is uniquely identified by its name and concentration. If a product that already exists is added, its quantity will be updated (the new quantity is added to the existing one).\
**(b)** See all available medicines containing a given string (if the string is empty, all the available medicines will be considered), sorted ascending by medicine name.\
**(c)** See only those medicines that are in short supply (quantity less than `X` items, where the value of `X` is user-provided).\
**(d)** Provide multiple undo and redo functionality. Each step will undo/redo the previous operation performed by the user.

### Bakery
Mary runs her family's bakery, *“Bread'n Bagel”*. Every day she struggles with keeping up to date with available stocks of raw materials and would like a program to help her manage the business more effectively. Each **Material** used in the bakery must have: a `name`, a `supplier`, a `quantity` and the `expiration date`. Mary wants a software application that helps her in the following ways:\
**(a)** Add, delete and update a material. A raw material is uniquely identified by its name, supplier and expiration date. If a material that already exists is added, its quantity will be modified (the new quantity is added to the existing one).\
**(b)** See all available materials past their expiration date, containing a given string (if the string is empty, all materials past their expiration date will be considered).\
**(c)** Display all materials from a given supplier, which are in short supply (quantity less than a user-provided value), sorted ascending by their quantities.\
**(d)** Provide multiple undo and redo functionality. Each step will undo/redo the previous operation performed by the user.

### Tourism Agency
The employees of *“Happy Holidays”* need an application to manage the offers that the agency has. Each **Offer** has a `type` (one of `seaside, mountain or city break`), a `destination`, a `departure date` and a `price`. The employees need the application to help them in the following ways:\
**(a)** Add, delete and update an offer. An offer is uniquely identified by its destination and departure dates.\
**(b)** Display all tourism offers whose destinations contain a given string (if the string is empty, all destinations are considered), and show them sorted ascending by price.\
**(c)** Display all offers of a given type, having their departure after a given date.\
**(d)** Provide multiple undo and redo functionality. Each step will undo/redo the previous operation performed by the user.

### Real Estate Agency
Evelyn owns a real estate agency. Being also the only employee, she needs an application to help her manage all the real estates of her clients. Each **Estate** has a type (one of `house, apartment or penthouse`), an `address`, a `surface` and a `price`. Evelyn needs the application to help her in the following ways:\
**(a)** Add, delete or update an estate. An estate is uniquely identified by its address.\
**(b)** Display all estates whose address contains a given string (if the string is empty, all estates will be considered), sorted ascending by their price.\
**(c)** See all estates of a given type, having the surface greater than a user provided value.\
**(d)** Provide multiple undo and redo functionality. Each step will undo/redo the previous operation performed by the user.

### Intelligent Refrigerator
The company *“Home SmartApps”* have decided to design a new intelligent refrigerator. Besides the hardware, they need a software application to manage the refrigerator. Each **Product** that the fridge can store has a `name`, a `category` (one of `dairy, sweets, meat or fruit`), a `quantity` and an `expiration date`. The software application will provide the following functionalities:\
**(a)** Add, delete or update a product. A product is uniquely identified by name and category. If a product that already exists is added, its quantity will be updated (the new quantity is added to the existing one).\
**(b)** Display all products whose name contains a given string (if the string is empty, all products from the refrigerator are considered), and show them sorted ascending by the existing quantity.\
**(c)** Display all products of a given category (if the category is empty, all types of food will be considered) whose expiration dates are close (expire in the following `X` days, where the value of `X` is user-provided).\
**(d)** Provide multiple undo and redo functionality. Each step will undo/redo the previous operation performed by the user.

### World Population Monitoring
The World Population Monitoring Organisation needs an application to help keep track of countries’ populations. Each **Country** has a unique `name`, the `continent` it belongs to (one of `Europe, America, Africa, Australia or Asia`), and a population (stored in millions).  The employees of the organisation need the application to help them in the following ways:\
**(a)** Add, delete or update a country. Updating must also consider the case of migration: a given number of people leave one country to migrate to another.\
**(b)** Display all countries whose name contains a given string (if the string is empty, all the countries should be considered).\
**(c)** Display all countries on a given continent (if the continent is empty, all countries will be considered), whose populations are greater than a given value, sorted ascending by population.\
**(d)** Provide multiple undo and redo functionality. Each step will undo/redo the previous operation performed by the user.
