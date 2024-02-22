package Model.Statements.ExamSet;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.ConstantExpression;
import Model.Statements.CompositeStatement;
import Model.Statements.IStatement;
import Model.Statements.PrintStatement;
import Model.States.ExecutionStack.IExecutionStack;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Values.IntegerValue;

public class SleepStatement implements IStatement {
    private final int number;

    public SleepStatement(int number) {
        this.number = number;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        if (number > 0) {
            IExecutionStack stack = state.getExecutionStack();
            stack.push(new SleepStatement(number - 1));
            state.setExecutionStack(stack);
        }
        return null;
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        return typeDictionary;
    }

    @Override
    public String toString() {
        return "Sleep(" + number + ")" ;
    }
}
