package Model.Expressions;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Values.IValue;

public class BinaryExpression implements IExpression {
    IExpression leftHandSide;
    IExpression rightHandSide;
    String operation;

    public BinaryExpression(IExpression leftHandSide, IExpression rightHandSide, String operation) {
        this.leftHandSide = leftHandSide;
        this.rightHandSide = rightHandSide;
        this.operation = operation;
    }

    @Override
    public IValue evaluate(ProgState state) throws AppException {
        return leftHandSide.evaluate(state).compose(rightHandSide.evaluate(state), operation);
    }

    @Override
    public IType typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        IType firstType = leftHandSide.typecheck(typeDictionary);
        IType secondType = rightHandSide.typecheck(typeDictionary);
        if(!firstType.equals(secondType)) {
            throw new AppException("Different types in binary expression");
        }
        return firstType.compose(operation);
    }

    @Override
    public String toString(){
        return "("
                + leftHandSide.toString()
                + " "
                + operation
                + " "
                + rightHandSide.toString()
                + ")";
    }

    @Override
    public String toJavaHardCode() {
        return "new BinaryExpression("
                + this.leftHandSide.toJavaHardCode()
                + ","
                + this.rightHandSide.toJavaHardCode()
                + ","
                + "\""
                + this.operation
                + "\""
                + ")";
    }
}
