package Model.States.FileTable.Exceptions;

import Exceptions.AppException;

public class InvalidFileFormatException extends AppException {
    public InvalidFileFormatException(String message) {
        super(message);
    }
}
