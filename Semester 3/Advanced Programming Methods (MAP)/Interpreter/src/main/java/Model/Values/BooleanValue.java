package Model.Values;

import Model.Values.Exceptions.InvalidOperationException;
import Model.Types.BooleanType;
import Model.Types.IType;

public class BooleanValue implements IValue{
    boolean value;

    public BooleanValue(boolean value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return String.valueOf(value);
    }

    @Override
    public IValue compose(IValue other, String operation) throws InvalidOperationException {
        if(other instanceof BooleanValue){
            BooleanValue otherBooleanValue = (BooleanValue) other;
            switch(operation){
                case "and": return new BooleanValue(this.value && otherBooleanValue.value);
                case "or":  return new BooleanValue(this.value || otherBooleanValue.value);
                case "==":  return new BooleanValue(this.value == otherBooleanValue.value);
                case "!=":  return new BooleanValue(this.value != otherBooleanValue.value);
            }
        }
        throw new InvalidOperationException("Invalid Operation: Cannot compose two BooleanValue type values using operation " + operation);
    }

    @Override
    public IType getType() {
        return new BooleanType();
    }

    @Override
    public boolean equals(IValue other) {
        if(other instanceof BooleanValue){
            BooleanValue otherBooleanValue = (BooleanValue) other;
            return this.value == otherBooleanValue.value;
        }
        return false;
    }

    @Override
    public IValue clone() {
        return new BooleanValue(this.value);
    }

    @Override
    public String toJavaHardCode() {
        return "new BooleanValue(" + this.value + ")";
    }

    public boolean getValue() {
        return this.value;
    }
}
