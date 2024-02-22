package Model.Values.Exceptions;

import Exceptions.AppException;

public class InvalidOperationException extends AppException {
    public InvalidOperationException(String message) {
        super(message);
    }
}
