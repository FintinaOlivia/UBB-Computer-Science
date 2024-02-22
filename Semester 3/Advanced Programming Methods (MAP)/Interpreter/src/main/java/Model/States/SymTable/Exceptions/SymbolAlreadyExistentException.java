package Model.States.SymTable.Exceptions;

import Exceptions.AppException;

public class SymbolAlreadyExistentException extends AppException {
    public SymbolAlreadyExistentException(String message) {
        super(message);
    }
}
