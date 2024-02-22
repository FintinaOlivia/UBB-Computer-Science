package Model.States.ExecutionStack;

import Exceptions.AppException;
import Model.ADTs.Stack.ADT_I_Stack;
import Model.ADTs.Stack.ADT_Stack;
import Model.ADTs.Stack.Exceptions.StackEmptyException;
import Model.Statements.IStatement;

import java.util.List;

public class ExecutionStack implements IExecutionStack{
    ADT_I_Stack<IStatement> executionStack;

    public ExecutionStack(ADT_I_Stack<IStatement> executionStack) {
        this.executionStack = executionStack;
    }

    public ExecutionStack() {
        this.executionStack = new ADT_Stack<>();
    }

    @Override
    public void push(IStatement statement) {
        executionStack.push(statement);
    }

    @Override
    public IStatement pop() throws StackEmptyException {
        return executionStack.pop();
    }

    @Override
    public boolean empty() {
        return executionStack.empty();
    }

    @Override
    public int size() {
        return executionStack.size();
    }

    @Override
    public String toString() {
//        return executionStack.toString();
        StringBuilder answer = new StringBuilder("Execution stack:\n");
        ADT_I_Stack<IStatement> tmpStack = new ADT_Stack<>();
        try{
            while(!executionStack.empty()){
                tmpStack.push(executionStack.pop());
                answer.append(tmpStack.top().toString()).append('\n');
            }
            while(!tmpStack.empty()){
                executionStack.push(tmpStack.pop());
            }
        }catch (AppException exception){
            throw new RuntimeException(exception.getMessage());
        }
        return answer.toString();
    }

    @Override
    public List<IStatement> toList() {
        return executionStack.toList();
    }
}
