package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Types.IntegerType;
import Model.Values.IValue;

public class ReleaseStatement implements IStatement{
    String name;

    public ReleaseStatement(String name) {
        this.name = name;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        IValue value = state.getSymTable().getValue(this.name);
        if(!(value.getType() instanceof IntegerType)) {
            throw new AppException("Invalid expression value for release statement");
        }
        return null;
    }
    @Override
    public String toString(){
        return "release(\"" + this.name + "\")";
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        if(!typeDictionary.isDefined(this.name) ||
                !typeDictionary.getValueForKey(this.name).equals(new IntegerType())){
            throw new AppException("Invalid expression");
        }
        return typeDictionary;
    }

    @Override
    public String toJavaHardCode() {
        return "new ReleaseStatement(\""
                + this.name
                + "\")";
    }

}
