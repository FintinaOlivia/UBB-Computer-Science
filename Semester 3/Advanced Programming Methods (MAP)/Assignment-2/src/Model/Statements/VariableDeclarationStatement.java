package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.States.ProgState;
import Model.Types.IType;

public class VariableDeclarationStatement implements IStatement{
    String name;
    IType type;

    public VariableDeclarationStatement(String name, IType type) {
        this.name = name;
        this.type = type;
    }
    @Override
    public ProgState execute(ProgState state) throws AppException {
        state.getSymTable().declareValue(name, type);
        return null;
    }

    @Override
    public String toString(){
        return type.toString() + " " + name;
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        typeDictionary.update(name, type);
        return typeDictionary;
    }

    @Override
    public String toJavaHardCode() {
        return "new VariableDeclarationStatement(" + "\"" + name + "\"" + "," + this.type.toJavaHardCode() + ")";
    }
}
