package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.IExpression;
import Model.States.ProgState;
import Model.Types.BooleanType;
import Model.Types.IType;
import Model.Values.BooleanValue;
import Model.Values.IValue;

public class IfStatement implements IStatement{
    IExpression expression;
    IStatement leftHandSide;
    IStatement rightHandSide;

    public IfStatement(IExpression expression,
                       IStatement leftHandSide,
                       IStatement rightHandSide) {
        this.expression = expression;
        this.leftHandSide = leftHandSide;
        this.rightHandSide = rightHandSide;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        IValue value = expression.evaluate(state);
        if(!(value.getType() instanceof BooleanType)) {
            throw new AppException("Invalid expression value for if statement");
        }
        if(((BooleanValue)value).getValue()){
            state.getExecutionStack().push(leftHandSide);
        }else{
            state.getExecutionStack().push(rightHandSide);
        }
        return null;
    }

    @Override
    public String toString(){
        return "if("
                + this.expression.toString()
                + ")"
                + "then {"
                + this.leftHandSide.toString()
                + "} else {"
                + this.rightHandSide.toString()
                + "}";
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        if (!(new BooleanType()).equals(expression.typecheck(typeDictionary))) {
            throw new AppException(" 'If Statement' does not evaluate to a BooleanType");
        }
        leftHandSide.typecheck(typeDictionary.clone());
        rightHandSide.typecheck(typeDictionary.clone());
        return typeDictionary;
    }

//    @Override
//    public String toJavaHardCode() {
//        return "new IfStatement("
//                + this.expression.toJavaHardCode()
//                + ", "
//                + this.leftHandSide.toJavaHardCode()
//                + ", " + this.rightHandSide.toJavaHardCode()
//                + ")";
//    }
}


