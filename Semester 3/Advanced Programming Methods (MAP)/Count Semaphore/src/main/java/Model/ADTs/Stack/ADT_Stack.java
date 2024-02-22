package Model.ADTs.Stack;

import Model.ADTs.Stack.Exceptions.StackEmptyException;

import java.util.List;
import java.util.Stack;

public class ADT_Stack<Type> implements ADT_I_Stack<Type> {
    Stack<Type> stack;

    public ADT_Stack(){
        this.stack = new Stack<>();
    }

    @Override
    public void push(Type element){
        stack.push(element);
    }

    @Override
    public Type pop() throws StackEmptyException {
        if(stack.isEmpty()){
            throw new StackEmptyException("Cannot pop from an empty stack");
        }
        return stack.pop();
    }

    @Override
    public Type top() throws StackEmptyException {
        if(stack.isEmpty()){
            throw new StackEmptyException("Cannot pop from an empty stack");
        }
        return stack.peek();
    }

    @Override
    public boolean empty(){
        return stack.empty();
    }

    @Override
    public int size(){
        return stack.size();
    }

    @Override
    public List<Type> toList() {
        return this.stack.stream().toList();
    }

}
