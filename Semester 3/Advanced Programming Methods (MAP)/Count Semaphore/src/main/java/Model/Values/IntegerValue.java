package Model.Values;

import Exceptions.AppException;
import Model.Values.Exceptions.DivisionByZeroException;
import Model.Values.Exceptions.InvalidOperationException;
import Model.Types.IType;
import Model.Types.IntegerType;

public class IntegerValue implements IValue {
    int value;

    public IntegerValue() {
        this.value = 0;
    }

    public IntegerValue(int value) {
        this.value = value;
    }

    private IntegerValue add(IntegerValue other) {
        return new IntegerValue(this.value + other.value);
    }

    private IntegerValue subtract(IntegerValue other) {
        return new IntegerValue(this.value - other.value);
    }

    private IntegerValue multiply(IntegerValue other) {
        return new IntegerValue(this.value * other.value);
    }

    private IntegerValue divide(IntegerValue other) throws DivisionByZeroException {
        if(other.value == 0) {
            throw new DivisionByZeroException("Division by zero!");
        }
        return new IntegerValue(this.value / other.value);
    }

    private IntegerValue modulo(IntegerValue other) throws DivisionByZeroException {
        if(other.value == 0) {
            throw new DivisionByZeroException("Division by zero!");
        }
        return new IntegerValue(this.value % other.value);
    }

    private BooleanValue lessThan(IntegerValue other) {
        return new BooleanValue(this.value < other.value);
    }

    private BooleanValue lessThanEqual(IntegerValue other) {
        return new BooleanValue(this.value <= other.value);
    }

    private BooleanValue greaterThan(IntegerValue other) {
        return new BooleanValue(this.value > other.value);
    }

    private BooleanValue greaterThanEqual(IntegerValue other) {
        return new BooleanValue(this.value >= other.value);
    }

    private BooleanValue equal(IntegerValue other) {
        return new BooleanValue(this.value == other.value);
    }

    private BooleanValue notEqual(IntegerValue other) {
        return new BooleanValue(this.value != other.value);
    }

    @Override
    public String toString() {
        return Integer.toString(value);
    }

    @Override
    public IValue compose(IValue other, String operation) throws AppException {
        if(!(other.getType().equals(this.getType()))) {
            throw new InvalidOperationException("Invalid Operation: Cannot compose two different types using operator " + operation);
        }
        switch(operation){
            case "+": return this.add((IntegerValue)other);
            case "-": return this.subtract((IntegerValue)other);
            case "*": return this.multiply((IntegerValue)other);
            case "/": return this.divide((IntegerValue)other);
            case "<":   return this.lessThan((IntegerValue) other);
            case "<=":  return this.lessThanEqual((IntegerValue) other);
            case "==":  return this.equal((IntegerValue) other);
            case "!=":  return this.notEqual((IntegerValue) other);
            case ">":   return this.greaterThan((IntegerValue)other);
            case ">=":  return this.greaterThanEqual((IntegerValue)other);
        }
        throw new InvalidOperationException("Invalid Operation: Cannot compose two IntegerValue types using operator " + operation);

    }

    @Override
    public IType getType() {
        return new IntegerType();
    }

    @Override
    public boolean equals(IValue other){
        if(other.getType() instanceof IntegerType){
            return this.getValue() == ((IntegerValue)other).getValue();
        }
        return false;
    }

    @Override
    public IValue clone() {
        return new IntegerValue(this.value);
    }

    @Override
    public String toJavaHardCode() {
        return "new IntegerValue(" + String.valueOf(this.value) + ")";
    }

    public int getValue() {
        return this.value;
    }
}
