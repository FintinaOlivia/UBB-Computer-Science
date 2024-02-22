package Model.States.FileTable.Exceptions;

import Exceptions.AppException;

public class CouldNotOpenFileException extends AppException {
    public CouldNotOpenFileException(String message) {
        super(message);
    }
}
