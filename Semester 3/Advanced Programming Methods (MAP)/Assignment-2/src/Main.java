import Controller.IController;
import Controller.Controller;
import Exceptions.AppException;
import Repository.IRepository;
import Repository.Repository;
import View.View;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.concurrent.Executors;
public class Main {
    public static void main(String[] args) throws IOException, AppException {
//        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//        System.out.print("Select logfilePath:");
//        String line = reader.readLine().trim();
//        if (line.isEmpty()) {
//            line = null;
//        }
        IRepository repository = new Repository("log.txt");
        IController controller = new Controller(repository, Executors.newFixedThreadPool(2), true);

        View view = new View(controller);
        view.run(args);
    }
}

/*
Checklist:
- [x] ADTs
- [x] States
- [x] Statements
- [x] Expressions
- [x] Types
- [x] Values
- [x] Program State
- [x] Repository
- [x] Controller
- [ ] View (50%)

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
* Hardcode the type of expressions
* class ArithmeticExpression, with methods: (Binary Expressions?
* Along with logical expressions)
* - evaluate
* - add
* - subtract, etc.
*
* */