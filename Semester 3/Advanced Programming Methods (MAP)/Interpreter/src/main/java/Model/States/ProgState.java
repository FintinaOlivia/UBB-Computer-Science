package Model.States;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Statements.IStatement;
import Model.States.ExecutionStack.IExecutionStack;
import Model.States.FileTable.IFileTable;
import Model.States.Heap.IHeap;
import Model.States.Output.IOutput;
import Model.States.SymTable.ISymTable;

public class ProgState {
    int id;
    static int nextId = 0;
    IExecutionStack executionStack;
    ISymTable symTable;
    IOutput output;
    IFileTable fileTable;
    IHeap heap;

    public ProgState(IExecutionStack executionStack,
                     ISymTable symTable,
                     IOutput output,
                     IFileTable fileTable,
                     IHeap heap,
                     IStatement statement){

        synchronized (ProgState.class){
            this.id = nextId;
            nextId++;
        }

        this.executionStack = executionStack;
        this.symTable = symTable;
        this.output = output;
        this.fileTable = fileTable;
        this.heap = heap;
        this.executionStack.push(statement);
    }

    public IExecutionStack getExecutionStack() {
        return executionStack;
    }

    public void setExecutionStack(IExecutionStack executionStack) {
        this.executionStack = executionStack;
    }

    public ISymTable getSymTable() {
        return symTable;
    }

    public IOutput getOutput() {
        return output;
    }

    public IFileTable getFileTable() {
        return fileTable;
    }

    public IHeap getHeap() {
        return heap;
    }

    public int getId() {
        return id;
    }

    public boolean isNotCompletedYet(){
        return this.executionStack.size() > 0;
    }

    public ProgState executeOneStep() throws AppException {
        IStatement statement = executionStack.pop();
        return statement.execute(this);
    }

    @Override
    public String toString() {
        return "ID: " + Integer.toString(this.id)
                + "\n"
                + this.executionStack.toString().strip()
                + "\n" + this.symTable.toString().strip()
                + "\n" + this.output.toString().strip()
                + "\n" + this.fileTable.toString().strip()
                + "\n" + this.heap.toString().strip();
    }
}
