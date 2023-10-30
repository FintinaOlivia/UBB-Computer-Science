public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}

/*
* MVC : model view controller
* Model:
*  - states
*  - expressions
*  - types
*  - values
*
* Program State (after executing a statement)
*
* Repository:
* - store program states
*
* Controller:
* - manipulate program state
* - repo
* - garbage collector: one step, all steps
*
* View:
* PROGRAMS ARE HARDCODED
*
* Program states:
* - original program
* - Execution stack
* - symbol table: all variables and their values
* - output list
*
* Exe Stack:
* Symbol Table: String(ID) | Value
*
* Output List:
* Compound statements (Statement 1, Statement 2)
* Compound statements (Statement 1, Compound statements (Statement 2, Statement 3))
* Compound statements(int v, Compound statements(v=3, print(v)))
*
* On the stack: first s2, then s1
*
* Harcode the type of expressions
* class ArithmeticExpression, with methods:
* - evaluate
* - add
* - subtract, etc.
*
* */