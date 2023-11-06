package View.Options;

import Exceptions.AppException;

public interface IViewOption {
    public void execute(String command) throws AppException;
}
