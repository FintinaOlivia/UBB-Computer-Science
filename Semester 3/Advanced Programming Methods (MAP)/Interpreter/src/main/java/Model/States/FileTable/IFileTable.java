package Model.States.FileTable;

import Exceptions.AppException;

import java.util.List;

public interface IFileTable {
    public void openFile(String name) throws AppException;

    public void closeFile(String name) throws AppException;

    public int readFile(String name) throws AppException;

    public String toString();

    public List<String> getFileList();
}
