package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.IExpression;
import Model.States.ProgState;
import Model.Types.IType;

public class PrintStatement implements IStatement{
    IExpression expression;

    public PrintStatement(IExpression expression) {
        this.expression = expression;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        state.getOutput().appendToOutput(expression.evaluate(state).toString());
        return null;
    }

    @Override
    public String toString(){
        return "print("
                + expression.toString()
                + ")";
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        expression.typecheck(typeDictionary);
        return typeDictionary;
    }

    @Override
    public String toJavaHardCode() {
        return "new PrintStatement("
                + this.expression.toJavaHardCode()
                + ")";
    }

}
