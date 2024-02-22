package Model.Statements.ExamSet;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.ADTs.Stack.ADT_I_Stack;
import Model.ADTs.Stack.ADT_Stack;
import Model.Expressions.BinaryExpression;
import Model.Expressions.ConstantExpression;
import Model.Statements.CompositeStatement;
import Model.Statements.IStatement;
import Model.Statements.PrintStatement;
import Model.States.ExecutionStack.IExecutionStack;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Values.IntegerValue;

public class WaitStatement implements IStatement {
    private final Integer number;

    public WaitStatement(int number) {
        this.number = number;
    }

    @Override
    public ProgState execute(ProgState state) {
        if (number > 0) {
            IExecutionStack stack = state.getExecutionStack();
            IStatement newStatement = new CompositeStatement(
                    new PrintStatement(new ConstantExpression(new IntegerValue(number))),
                    new WaitStatement(number - 1)
            );
            stack.push(newStatement);
            state.setExecutionStack(stack);
        }
        return null;
    }

    @Override
    public String toString() {
        return "wait(" + number + ")";
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        return typeDictionary;
    }

    public IStatement deepCopy() {
        return new WaitStatement(number);
    }

}
