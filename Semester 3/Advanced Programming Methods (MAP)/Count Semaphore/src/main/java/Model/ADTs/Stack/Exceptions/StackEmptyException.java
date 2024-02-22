package Model.ADTs.Stack.Exceptions;

import Exceptions.AppException;

public class StackEmptyException extends AppException {
    public StackEmptyException(String msg){
        super(msg);
    }
}
