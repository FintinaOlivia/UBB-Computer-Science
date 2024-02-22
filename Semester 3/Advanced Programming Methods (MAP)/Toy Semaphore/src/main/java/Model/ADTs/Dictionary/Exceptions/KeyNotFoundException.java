package Model.ADTs.Dictionary.Exceptions;

import Exceptions.AppException;

public class KeyNotFoundException extends AppException {
    public KeyNotFoundException(String msg){
        super(msg);
    }
}
