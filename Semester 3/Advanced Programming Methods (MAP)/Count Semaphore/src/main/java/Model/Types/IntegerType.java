package Model.Types;

import Exceptions.AppException;
import Model.Values.Exceptions.InvalidOperationException;
import Model.Values.IValue;
import Model.Values.IntegerValue;

public class IntegerType implements IType{

    public IntegerType() {}

    @Override
    public IValue getDefaultValue() {
        return new IntegerValue(0);
    }

    @Override
    public boolean equals(IType other) {
        return (other instanceof IntegerType);
    }

    @Override
    public String toString() {
        return "Integer";
    }

    @Override
    public String toJavaHardCode() {
        return "new IntegerType()";
    }

    @Override
    public IType compose(String operation) throws AppException {
       switch(operation) {
           case "+":
               return new IntegerType();
           case "-":
               return new IntegerType();
           case "*":
               return new IntegerType();
           case "/":
               return new IntegerType();
           case "<":
               return new BooleanType();
           case "<=":
               return new BooleanType();
           case "==":
               return new BooleanType();
           case "!=":
               return new BooleanType();
           case ">":
               return new BooleanType();
           case ">=":
               return new BooleanType();
       }
        throw new InvalidOperationException("Invalid Operation: Cannot compose two IntegerType types using operator " + operation);
    }
}
