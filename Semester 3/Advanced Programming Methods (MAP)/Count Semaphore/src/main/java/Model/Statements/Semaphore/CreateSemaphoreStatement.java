package Model.Statements.Semaphore;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.IExpression;
import Model.Statements.IStatement;
import Model.States.CountSemaphore.ISemaphoreTable;
import Model.States.Heap.IHeap;
import Model.States.ProgState;
import Model.States.SymTable.ISymTable;
import Model.States.SymTable.SymTable;
import Model.Types.IType;
import Model.Types.IntegerType;
import Model.Values.IValue;
import Model.Values.IntegerValue;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class CreateSemaphoreStatement implements IStatement {
    private final String var;
    private final IExpression expression;
    private static final Lock lock = new ReentrantLock();

    public CreateSemaphoreStatement(String var, IExpression expression) {
        this.var = var;
        this.expression = expression;
    }
    @Override
    public ProgState execute(ProgState state) throws AppException {
        lock.lock();
        ISymTable symTable = state.getSymTable();
        IHeap heap = state.getHeap();
        ISemaphoreTable semaphoreTable = state.getSemaphoreTable();
        IntegerValue nr = (IntegerValue) (expression.evaluate(state));
        int number = nr.getValue();
        int freeAddress = semaphoreTable.getFreeAddress();
        semaphoreTable.put(freeAddress, new Pair<>(number, new ArrayList<>()));
        if (symTable.isDefined(var) && symTable.getValue(var).getType().equals(new IntegerType()))
            symTable.setValue(var, new IntegerValue(freeAddress));
        else
            throw new AppException("Error for variable: not defined/does not have int type!");
        lock.unlock();
        return null;
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        if (typeDictionary.getValueForKey(var).equals(new IntegerType())) {
            if (expression.typecheck(typeDictionary).equals(new IntegerType()))
                return typeDictionary;
            else
                throw new AppException("Expression is not of int type!");
        } else {
            throw new AppException(var + "is not of type int!");
        }
    }

    @Override
    public String toString() {
        return "CreateSemaphore (" + var + "," + expression +")";
    }
}
