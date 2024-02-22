package Model.Expressions;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Types.ReferenceType;
import Model.Values.IValue;
import Model.Values.ReferenceValue;

public class ReadHeapExpression implements IExpression{
    IExpression expression;

    public ReadHeapExpression(IExpression expression) {
        this.expression = expression;
    }

    @Override
    public IValue evaluate(ProgState state) throws AppException {
        IValue value = expression.evaluate(state);
        if(!(value.getType() instanceof ReferenceType)){
            throw new AppException("Heap should only be accessed through references");
        }
        return state.getHeap().read(((ReferenceValue)value).getAddress());
//        PUSESEM PARANTEZA GRESIT AUIFHLAIDFSALFH
    }

    @Override
    public IType typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        IType exprType = expression.typecheck(typeDictionary);
        if(!(exprType instanceof ReferenceType)) {
            throw new AppException("Read Heap expression evaluates to a non RefType");
        }
        return ((ReferenceType)exprType).getInner();
    }

    @Override
    public String toString(){
        return "ReadHeap(" + expression.toString() + ")";
    }

}
