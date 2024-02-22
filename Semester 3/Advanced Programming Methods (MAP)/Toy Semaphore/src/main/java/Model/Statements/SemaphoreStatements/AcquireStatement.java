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
import Model.Values.IntegerValue;

import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class AcquireStatement implements IStatement {
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public AcquireStatement(String var) {
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
                    int NL = foundSemaphore.getThird().size();
                    int N1 = foundSemaphore.getFirst();
                    int N2 = foundSemaphore.getSecond();
                    if ((N1 - N2) > NL) {
                        if (!foundSemaphore.getThird().contains(state.getId())) {
                            foundSemaphore.getThird().add(state.getId());
                            semaphoreTable.update(foundIndex, new Tuple<>(N1, N2, foundSemaphore.getThird()));
                        }
                    } else {
                        state.getExecutionStack().push(this);
                    }
                } else {
                    throw new AppException("Index is not in the semaphore table!");
                }
            } else {
                throw new AppException("Index does not have the int type!");
            }
        } else
            throw new AppException("Index not in the symbol table!");
        lock.unlock();
        return null;
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        return typeDictionary;
    }


    @Override
    public String toString() {
        return "Acquire(" + var + ")";
    }
}
