package Model.Types;

import Exceptions.AppException;
import Model.Values.Exceptions.InvalidOperationException;
import Model.Values.IValue;
import Model.Values.StringValue;

public class StringType implements IType{

    public StringType() {}

    @Override
    public IValue getDefaultValue() {
        return new StringValue("");
    }

    @Override
    public IType compose(String operation) throws AppException {
        switch(operation){
            case "+":   return new StringType();
            case "<":   return new BooleanType();
            case "<=":  return new BooleanType();
            case "==":  return new BooleanType();
            case "!=":  return new BooleanType();
            case ">":   return new BooleanType();
            case ">=":  return new BooleanType();
        }
        throw new InvalidOperationException("Invalid Operation: Cannot compose two StringValue entities using operation " + operation);
    }


    @Override
    public boolean equals(IType other) {
        return (other instanceof StringType);
    }

    @Override
    public String toString() {
        return "String";
    }

    @Override
    public String toJavaHardCode() {
        return "new StringType()";
    }
}
