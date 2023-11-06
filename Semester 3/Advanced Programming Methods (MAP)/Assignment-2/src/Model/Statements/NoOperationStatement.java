package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.States.ProgState;
import Model.Types.IType;

public class NoOperationStatement implements IStatement{
    public NoOperationStatement() {
        ;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        return null;
    }

    @Override
    public String toString(){
        return "NOP";
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        return typeDictionary;
    }

    @Override
    public String toJavaHardCode() {
        return "new NoOperationStatement()";
    }
}
