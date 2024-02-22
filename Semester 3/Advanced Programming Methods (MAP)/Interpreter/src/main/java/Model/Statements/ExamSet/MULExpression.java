package Model.Statements.ExamSet;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.BinaryExpression;
import Model.Expressions.IExpression;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Values.IValue;

public class MULExpression implements IExpression {
    IExpression expression1;
    IExpression expression2;

    public MULExpression(IExpression expression1, IExpression expression2) {
        this.expression1 = expression1;
        this.expression2 = expression2;
    }


    @Override
    public IValue evaluate(ProgState state) throws AppException {
        IExpression converted = new BinaryExpression(
                new BinaryExpression(expression1, expression2, "*"),
                new BinaryExpression(expression1, expression2, "+"),
                "-");
        return converted.evaluate(state);
    }

    @Override
    public IType typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        IType type1 = expression1.typecheck(typeDictionary);
        IType type2 = expression2.typecheck(typeDictionary);
        if(!(type1.equals(type2)) || !(type1.equals(new Model.Types.IntegerType()))){
            throw new AppException("MUL expression: type mismatch, the type of the operands should be Integer");
        }
        return type1;
    }

    @Override
    public String toString() {
        return "MUL(" + expression1.toString() + ", " + expression2.toString() + ")";
    }

}
