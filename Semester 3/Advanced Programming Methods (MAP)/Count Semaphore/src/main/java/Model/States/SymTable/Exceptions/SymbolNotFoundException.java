package Model.States.SymTable.Exceptions;

import Exceptions.AppException;

public class SymbolNotFoundException extends AppException {
    public SymbolNotFoundException(String message) {
        super(message);
    }
}
