package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.States.ProgState;
import Model.Types.IType;

public class CompositeStatement implements IStatement{
    IStatement firstStatement;
    IStatement secondStatement;

    public CompositeStatement(IStatement firstStatement,
                              IStatement secondStatement) {
        this.firstStatement = firstStatement;
        this.secondStatement = secondStatement;
    }

    @Override
    public ProgState execute(ProgState state) {
        state.getExecutionStack().push(secondStatement);
        state.getExecutionStack().push(firstStatement);
        return null;
    }

    @Override
    public String toString(){
        return firstStatement
                + "; " + secondStatement;
    }

    @Override
    public  ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        return secondStatement.typecheck(
                firstStatement.typecheck(typeDictionary));
    }

//    @Override
//    public String toJavaHardCode() {
//        return "new CompositeStatement("
//                + this.firstStatement.toJavaHardCode()
//                + ", "
//                + this.secondStatement.toJavaHardCode()
//                + ")";
//    }

}
