package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.IExpression;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Values.IValue;
import Model.Values.ReferenceValue;

public class WriteHeapStatement implements IStatement{
    IExpression address;
    IExpression expression;

    public WriteHeapStatement(IExpression address, IExpression expression) {
        this.address = address;
        this.expression = expression;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        IValue addressValue = address.evaluate(state);
        IValue expressionValue = expression.evaluate(state);
        if(!(addressValue.getType() instanceof IType)){
            throw new AppException("Heap should be accessed only using references");
        }
        state.getHeap().write(((ReferenceValue)addressValue).getAddress(), expressionValue);
        return null;
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        IType addressType = address.typecheck(typeDictionary);
        expression.typecheck(typeDictionary);
        if(!(addressType instanceof IType)) {
            throw new AppException("Write heap expression does not evaluate to a RefType");
        }
        return typeDictionary;
    }

    @Override
    public String toString(){
        return "writeHeap(" + address.toString() + ", " + expression.toString() + ")";
    }
}
