package Model.ADTs.Stack;

import Model.ADTs.Stack.Exceptions.StackEmptyException;

import java.util.List;

public interface ADT_I_Stack <Type>{
    void push(Type element);

    Type pop() throws StackEmptyException;

    Type top() throws StackEmptyException;

    boolean empty();

    int size();

    List<Type> toList();

}
