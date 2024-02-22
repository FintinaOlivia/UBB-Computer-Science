package Controller;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_Dictionary;
import Model.Statements.IStatement;
import Model.Statements.NoOperationStatement;
import Model.States.ExecutionStack.ExecutionStack;
import Model.States.FileTable.FileTable;
import Model.States.Heap.Heap;
import Model.States.Output.Output;
import Model.States.ProgState;
import Model.States.SymTable.SymTable;
import Model.States.ToySemaphore.SemaphoreTable;
import Repository.IRepository;

import java.util.List;
import java.util.Objects;
import java.util.concurrent.*;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller implements IController {
    IRepository repository;
    boolean displayFlag;
    ExecutorService executor;

    public Controller(IRepository repository, ExecutorService executor, boolean displayFlag) {
        this.repository = repository;
        this.executor = executor;
        this.displayFlag = displayFlag;
    }

    public Controller(IRepository repository){
        this.repository = repository;
        this.executor = Executors.newSingleThreadExecutor();
        this.displayFlag = true;
    }

    @Override
    public void removeCompletedPrograms(){
        this.repository.setProgramsList(
                this.repository.getProgramsList().stream()
                        .filter(ProgState::isNotCompletedYet)
                        .collect(Collectors.toList()));
    }


    public boolean getDisplayFlag() {
        return displayFlag;
    }

    @Override
    public List<ProgState> getProgStates() {
        return this.repository.getProgramsList();
    }

    @Override
    public void setDisplayFlag(boolean displayFlag) {
        this.displayFlag = displayFlag;
    }

    @Override
    public void executeOneStep() throws AppException{
        this.removeCompletedPrograms();
        List<Callable<ProgState>> stepList = repository.getProgramsList().stream()
                .map(program -> (Callable<ProgState>) (() -> {
                    return program.executeOneStep();
                }))
                .toList();

        List<ProgState> newPrograms = null;
        try {
            newPrograms = executor.invokeAll(stepList).stream()
                    .map(future -> {
                        try {
                            return future.get();
                        } catch (InterruptedException e) {
                            throw new RuntimeException(e);
                        } catch (ExecutionException e) {
                            System.out.println(e);
                            try {
                                this.setProgram(new NoOperationStatement());
                            } catch (AppException ex) {
                                throw new RuntimeException(ex);
                            }
                        }
                        return null;
                    })
                    .filter(Objects::nonNull)
                    .toList();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        newPrograms.forEach(e -> this.repository.addProgram(e));

        GarbageCollector.runGarbageCollector(this.repository.getProgramsList());

        if(this.displayFlag){
            this.displayCurrentState();
        }
        this.repository.getProgramsList().forEach(e -> this.repository.logProgramState(e));
    }

    @Override
    public void executeAllSteps() throws AppException{
        while(true){
            this.removeCompletedPrograms();
            if(this.repository.getProgramsList().isEmpty()){
                break;
            }
            this.executeOneStep();
        }
    }

    @Override
    public void displayCurrentState() throws AppException {
        this.repository.getProgramsList().forEach(program ->
                System.out.println(program.toString() + "\n"));
    }

    @Override
    public ProgState getCurrentProgramState() {
        return this.repository.getProgramsList().getFirst();
    }

    @Override
    public void setProgram(IStatement statement) throws AppException {
        statement.typecheck(new ADT_Dictionary<>());

        this.repository.clear();
        this.repository.addProgram(new ProgState(
                new ExecutionStack(),
                new SymTable(),
                new Output(),
                new FileTable(),
                new Heap(),
                new SemaphoreTable(),
                statement));

        this.repository.logProgramState(this.repository.getProgramsList().get(0));

        if(this.displayFlag){
            this.displayCurrentState();
        }
    }
}
