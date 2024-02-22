package Model.Statements.SemaphoreStatements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.IExpression;
import Model.Statements.IStatement;
import Model.States.ProgState;
import Model.States.SymTable.ISymTable;
import Model.States.ToySemaphore.ISemaphoreTable;
import Model.States.ToySemaphore.Tuple;
import Model.Types.IType;
import Model.Types.IntegerType;
import Model.Values.IntegerValue;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewSemaphoreStatement implements IStatement {
    private final String var;
    private final IExpression expression1;
    private final IExpression expression2;
    private static final Lock lock = new ReentrantLock();

    public NewSemaphoreStatement(String var, IExpression expression1, IExpression expression2) {
        this.var = var;
        this.expression1 = expression1;
        this.expression2 = expression2;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        lock.lock();
        ISymTable symTable = state.getSymTable();
        ISemaphoreTable semaphoreTable = state.getSemaphoreTable();
        IntegerValue nr1 = (IntegerValue) (expression1.evaluate(state));
        IntegerValue nr2 = (IntegerValue) (expression2.evaluate(state));
        int number1 = nr1.getValue();
        int number2 = nr2.getValue();
        int freeAddress = semaphoreTable.getFreeAddress();
        semaphoreTable.put(freeAddress, new Tuple<>(number1, number2, new ArrayList<>()));
        if (symTable.isDefined(var) && symTable.getValue(var).getType().equals(new IntegerType()))
            symTable.setValue(var, new IntegerValue(freeAddress));
        else
            throw new AppException(String.format("%s in not defined in the symbol table!", var));
        lock.unlock();
        return null;
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        return typeDictionary;
    }

    @Override
    public String toString() {
        return "NewSemaphore(" + var + "," + expression1.toString() + "," + expression2 + ")";
    }
}
