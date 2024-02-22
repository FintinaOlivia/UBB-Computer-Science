package Model.Statements.SemaphoreStatements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Statements.IStatement;
import Model.States.ProgState;
import Model.States.SymTable.ISymTable;
import Model.States.ToySemaphore.ISemaphoreTable;
import Model.States.ToySemaphore.Tuple;
import Model.Types.IType;
import Model.Types.IntegerType;
import Model.Values.IValue;
import Model.Values.IntegerValue;

import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ReleaseStatement implements IStatement {
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public ReleaseStatement(String var) {
        this.var = var;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        lock.lock();
        ISymTable symTable = state.getSymTable();
        ISemaphoreTable semaphoreTable = state.getSemaphoreTable();
        if (symTable.isDefined(var)) {
            if (symTable.getValue(var).getType().equals(new IntegerType())) {
                IntegerValue fi = (IntegerValue) symTable.getValue(var);
                int foundIndex = fi.getValue();
                if (semaphoreTable.containsKey(foundIndex)) {
                    Tuple<Integer, Integer, List<Integer>> foundSemaphore = semaphoreTable.get(foundIndex);
                    if (foundSemaphore.getThird().contains(state.getId())) {
                        foundSemaphore.getThird().remove((Integer) state.getId());
                    }
                    semaphoreTable.update(foundIndex, new Tuple<>(foundSemaphore.getFirst(), foundSemaphore.getSecond(), foundSemaphore.getThird()));
                } else {
                    throw new AppException("Index not found in the semaphore table!");
                }
            } else {
                throw new AppException("Index must be of int type!");
            }
        } else {
            throw new AppException("Index not found in the symbol table!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        return typeDictionary;
    }

    @Override
    public String toString() {
        return "Release(" + var + ")";
    }
}
