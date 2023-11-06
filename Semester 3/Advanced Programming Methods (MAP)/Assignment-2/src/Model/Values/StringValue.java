package Model.Values;

import Exceptions.AppException;
import Model.Values.Exceptions.InvalidOperationException;
import Model.Types.IType;
import Model.Types.StringType;

public class StringValue implements IValue{
    String value;

    public StringValue() {
        this.value = "";
    }

    public StringValue(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }

    private StringValue add(StringValue other) {
        return new StringValue(this.value + other.getValue());
    }

    private StringValue equal(StringValue other) {
        return new StringValue(String.valueOf(this.value.equals(other.getValue())));
    }

    private StringValue notEqual(StringValue other) {
        return new StringValue(String.valueOf(!this.value.equals(other.getValue())));
    }

    private StringValue lessThan(StringValue other) {
        return new StringValue(String.valueOf(this.value.compareTo(other.getValue()) < 0));
    }

    private StringValue lessThanOrEqual(StringValue other) {
        return new StringValue(String.valueOf(this.value.compareTo(other.getValue()) <= 0));
    }

    private StringValue greaterThan(StringValue other) {
        return new StringValue(String.valueOf(this.value.compareTo(other.getValue()) > 0));
    }

    private StringValue greaterThanOrEqual(StringValue other) {
        return new StringValue(String.valueOf(this.value.compareTo(other.getValue()) >= 0));
    }

    @Override
    public IValue compose(IValue other, String operation) throws AppException {
        if(!(other.getType().equals(this.getType()))) {
            throw new InvalidOperationException("InvalidOperationAppException: Cannot compose two different types using operator " + operation);
        }
        switch(operation){
            case "+": return this.add((StringValue)other);
            case "<":   return this.lessThan((StringValue) other);
            case "<=":  return this.lessThanOrEqual((StringValue) other);
            case "==":  return this.equal((StringValue) other);
            case "!=":  return this.notEqual((StringValue) other);
            case ">":   return this.greaterThan((StringValue)other);
            case ">=":  return this.greaterThanOrEqual((StringValue)other);
        }
        throw new InvalidOperationException("InvalidOperationAppException: Cannot compose two StringValue types using operation " + operation);
    }

    public IType getType() {
        return new StringType();
    }

    public boolean equals(IValue other) {
        if (other instanceof StringValue) {
            return this.value.equals(((StringValue) other).getValue());
        }
        return false;
    }

    @Override
    public IValue clone() {
        return new StringValue(this.value);
    }

    @Override
    public String toString() {
        return "StringValue{" +
                "value='" + value + '\'' +
                '}';
    }

    @Override
    public String toJavaHardCode() {
        return "String Value(" + "\"" + this.value + "\"" + ")";
    }


}
