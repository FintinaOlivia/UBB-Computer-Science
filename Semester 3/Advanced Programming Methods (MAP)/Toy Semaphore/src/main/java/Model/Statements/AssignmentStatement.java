package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.IExpression;
import Model.States.ProgState;
import Model.Types.IType;

public class AssignmentStatement implements IStatement {
    String variableName;
    IExpression expression;

    public AssignmentStatement(String variableName, IExpression expression) {
        this.variableName = variableName;
        this.expression = expression;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        state.getSymTable().setValue(variableName, expression.evaluate(state));
        return null;
    }

    @Override
    public String toString(){
        return variableName + " = " + expression.toString();
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException{
        IType variableType = typeDictionary.getValueForKey(variableName);
        IType expressionType = expression.typecheck(typeDictionary);

        if(!expressionType.equals(variableType)){
            throw new AppException("Mismatched type in assignment");
        }
        return typeDictionary;
    }

//    @Override
//    public String toJavaHardCode() {
//        return "new AssignmentStatement(" + "\"" + this.variableName + "\"" + "," + this.expression.toJavaHardCode() + ")";
//    }
}
