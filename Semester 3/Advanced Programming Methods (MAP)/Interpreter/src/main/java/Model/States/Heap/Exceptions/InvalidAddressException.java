package Model.States.Heap.Exceptions;

import Exceptions.AppException;

public class InvalidAddressException extends AppException {
    public InvalidAddressException(String message) {
        super(message);
    }
}
