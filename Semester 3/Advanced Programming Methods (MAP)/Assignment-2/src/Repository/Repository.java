package Repository;

import Model.States.ProgState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Repository implements IRepository{
    List<ProgState> programs;
    String logFilePath;

    public Repository(String logFilePath) {
        programs = new ArrayList<>();
        this.logFilePath = logFilePath;
    }

    public Repository(List<ProgState> programs){
        this.programs = programs;
    }

    @Override
    public List<ProgState> getProgramsList(){
        return this.programs;
    }

    @Override
    public void setProgramsList(List<ProgState> programs){
        this.programs = programs;
    }

    @Override
    public void addProgram(ProgState program){
        this.programs.add(program);
    }

    @Override
    public void logProgramState(ProgState program){
        if(this.logFilePath != null) {
            PrintWriter logFile = null;
            try {
                logFile = new PrintWriter(
                        new BufferedWriter(new FileWriter(logFilePath, true)));
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            logFile.println(program.toString());
            logFile.close();
        }
    }

    @Override
    public void clear(){
        this.programs.clear();
    }
}
