package Model.Values.Exceptions;

import Exceptions.AppException;

public class DivisionByZeroException extends AppException {
    public DivisionByZeroException(String message) {
        super(message);
    }
}
