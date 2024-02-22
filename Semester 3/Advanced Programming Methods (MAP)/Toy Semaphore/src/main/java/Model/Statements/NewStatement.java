package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.IExpression;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Types.ReferenceType;
import Model.Values.IValue;
import Model.Values.ReferenceValue;

public class NewStatement implements IStatement{
    String name;
    IExpression expression;

    public NewStatement(String name, IExpression expression) {
        this.name = name;
        this.expression = expression;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        IValue value = expression.evaluate(state);
        state.getSymTable().setValue(name,
                new ReferenceValue(state.getHeap().allocate(value),
                        value.getType()));
        return null;
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        IType variableType = typeDictionary.getValueForKey(name);
        IType expressionType = expression.typecheck(typeDictionary);
        if(variableType.equals(new ReferenceType(expressionType))){
            return typeDictionary;
        }
        throw new AppException("Mismatched types for new statement");
    }

    @Override
    public String toString() {
        return "new(" + this.name.toString() + ", " + this.expression.toString() + ")";
    }

}
