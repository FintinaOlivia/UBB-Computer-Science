package Model.States.ExecutionStack;

import Model.ADTs.Stack.Exceptions.StackEmptyException;
import Model.Statements.IStatement;

import java.util.List;

public interface IExecutionStack {
    public IStatement pop() throws StackEmptyException;
    public void push(IStatement statement);
    public boolean empty();
    public int size();
    public String toString();
    public List<IStatement> toList();
}
