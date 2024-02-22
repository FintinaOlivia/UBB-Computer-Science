package Model.States.FileTable;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_Dictionary;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.ADTs.Dictionary.Exceptions.KeyNotFoundException;
import Model.States.FileTable.Exceptions.CouldNotOpenFileException;
import Model.States.FileTable.Exceptions.FileNotFoundException;
import Model.States.FileTable.Exceptions.InvalidFileFormatException;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;

public class FileTable implements IFileTable{
    ADT_I_Dictionary<String, BufferedReader> data;

    public FileTable() {
        this.data = new ADT_Dictionary<>();
    }

    @Override
    public void openFile(String name) throws AppException {
        if(data.isDefined(name)){
            throw new AppException("File already opened!");
        }
        try{
            BufferedReader reader = new BufferedReader(new FileReader(name));
            data.update(name, reader);
        }catch(Exception ex){
            throw new AppException("Error opening file!");
        }
    }

    @Override
    public void closeFile(String name) throws AppException {
        try {
            data.remove(name);
        } catch (KeyNotFoundException ex) {
            throw new FileNotFoundException("File not found, and therefore could not be closed!");
        }
    }

    @Override
    public int readFile(String name) throws AppException{
        BufferedReader reader = null;
        try{
            reader = data.getValueForKey(name);
        }catch(KeyNotFoundException exception){
            throw new CouldNotOpenFileException("Cannot read from file " + name);
        }

        String data;
        try {
            data = reader.readLine();
        } catch (IOException e) {
            throw new InvalidFileFormatException("Invalid line in file");
        }

        if(data == null){
            data = "0";
        }

        int answer = 0;
        try {
            answer = Integer.parseInt(data);
        } catch (NumberFormatException exception) {
            throw new InvalidFileFormatException("Invalid line in file");
        }
        return answer;
    }

    @Override
    public String toString(){
        StringBuilder answer = new StringBuilder();
        answer.append("File Table:\n");
        for(String name: data.getAllKeys()){
            answer.append(name).append("\n");
        }
        return answer.toString();
    }

    @Override
    public List<String> getFileList() {
        return this.data.getAllKeys();
    }
}
