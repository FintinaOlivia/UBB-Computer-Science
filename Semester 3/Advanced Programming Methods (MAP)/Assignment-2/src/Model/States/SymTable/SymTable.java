package Model.States.SymTable;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_Dictionary;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.ADTs.Dictionary.Exceptions.KeyNotFoundException;
import Model.States.SymTable.Exceptions.SymbolAlreadyExistentException;
import Model.States.SymTable.Exceptions.SymbolNotFoundException;
import Model.Types.IType;
import Model.Values.IValue;

import java.util.Map;

public class SymTable implements ISymTable {
    ADT_I_Dictionary<String, IValue> symTable;

    public SymTable(){
        this.symTable = new ADT_Dictionary<>();
    }

    @Override
    public void declareValue(String name, IType type) throws SymbolAlreadyExistentException {
        if(symTable.isDefined(name)){
            throw new SymbolAlreadyExistentException("Symbol " + name + " already isDefined.");
        }
        symTable.add(name, type.getDefaultValue());
    }

    @Override
    public IValue getValue(String name) throws SymbolNotFoundException {
        try{
            return symTable.getValueForKey(name);
        }catch(KeyNotFoundException exception){
            throw new SymbolNotFoundException("Symbol " + name + " not found.");
        }
    }

    @Override
    public void setValue(String name, IValue value) throws SymbolNotFoundException, KeyNotFoundException {
        if(!symTable.isDefined(name)){
            throw new SymbolNotFoundException("Symbol " + name + " not found.");
        }
        if(!symTable.getValueForKey(name).getType().equals(value.getType())){
            throw new SymbolNotFoundException("Symbol " + name + " does not have the same type as new value.");
        }
        symTable.update(name, value);
    }

    @Override
    public String toString() {
        StringBuilder answer = new StringBuilder("Sym Table:\n");
        try{
            for(String key: symTable.getAllKeys()){
                answer.append(key).append("(").
                        append(symTable.getValueForKey(key).getType().toString()).
                        append(")").
                        append(":-> ").
                        append(symTable.getValueForKey(key).toString()).
                        append("\n");
            }
        }catch(Exception exception){
            throw new RuntimeException(exception.getMessage());
        }
        return answer.toString();
    }

    @Override
    public ISymTable copy() throws AppException {
        ISymTable newSymTable = new SymTable();

        for(String key:symTable.getAllKeys()){
            newSymTable.declareValue(key, symTable.getValueForKey(key).getType());
            newSymTable.setValue(key, symTable.getValueForKey(key).clone());
        }

        return newSymTable;
    }

    public Map<String, IValue> toMap(){
        return this.symTable.toMap();
    }

}
