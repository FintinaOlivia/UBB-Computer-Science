package Model.Expressions;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Values.IValue;

public class VariableExpression implements IExpression {
    String name;

    public VariableExpression(String name) {
        this.name = name;
    }

    @Override
    public IValue evaluate(ProgState state) throws AppException {
        return state.getSymTable().getValue(this.name);
    }

    @Override
    public String toString(){
        return name;
    }

    @Override
    public IType typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        return typeDictionary.getValueForKey(name);
    }

    @Override
    public String toJavaHardCode() {
        return null;
    }
}
