package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.IExpression;
import Model.States.ProgState;
import Model.Types.BooleanType;
import Model.Types.IType;
import Model.Values.BooleanValue;
import Model.Values.IValue;

public class WhileStatement implements IStatement{
    IExpression expression;
    IStatement statement;

    public WhileStatement(IExpression expression, IStatement statement) {
        this.expression = expression;
        this.statement = statement;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        IValue value = expression.evaluate(state);
        if(!(value.getType() instanceof BooleanType)){
            throw new AppException("The while condition should evaluate to a Boolean Type");
        }
        if(((BooleanValue)value).getValue()){
            state.getExecutionStack().push(this);
            state.getExecutionStack().push(statement);
        }
        return null;
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        if((new BooleanType()).equals(expression.typecheck(typeDictionary))){
            return statement.typecheck(typeDictionary);
        }
        throw new AppException("The while condition does not evaluate to a Boolean Type");
    }

    @Override
    public String toString() {
        return "While(" + this.expression.toString()
                + "){" + this.statement.toString() + "}";
    }
}
