package Model.States.SymTable;

import Exceptions.AppException;
import Model.Types.IType;
import Model.Values.IValue;

import java.util.Map;

public interface ISymTable {
    public void declareValue(String name, IType type) throws AppException;

    public IValue getValue(String name) throws AppException;

    public void setValue(String name, IValue value) throws AppException;

    public ISymTable copy() throws AppException;

    public Map<String, IValue> toMap();

    public String toString();
}
