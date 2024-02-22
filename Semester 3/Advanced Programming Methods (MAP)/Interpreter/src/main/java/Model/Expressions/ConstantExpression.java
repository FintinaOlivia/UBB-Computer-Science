package Model.Expressions;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Values.IValue;

public class ConstantExpression implements IExpression{
    IValue value;

    public ConstantExpression(IValue value) {
        this.value = value;
    }

    @Override
    public IValue evaluate(ProgState state) throws AppException {
        return value;
    }

    @Override
    public String toString() {
        return value.toString();
    }

    @Override
    public IType typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        return value.getType();
    }

}
