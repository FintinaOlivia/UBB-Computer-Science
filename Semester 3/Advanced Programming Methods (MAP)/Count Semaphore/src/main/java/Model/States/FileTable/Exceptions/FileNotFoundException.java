package Model.States.FileTable.Exceptions;

import Exceptions.AppException;

public class FileNotFoundException extends AppException {
    public FileNotFoundException(String message) {
        super(message);
    }
}
