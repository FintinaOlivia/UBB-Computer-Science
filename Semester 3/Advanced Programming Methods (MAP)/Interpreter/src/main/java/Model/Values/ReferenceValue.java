package Model.Values;

import Exceptions.AppException;
import Model.Types.IType;
import Model.Types.ReferenceType;
import Model.Values.Exceptions.InvalidOperationException;

public class ReferenceValue implements IValue{
    int address;
    IType innerType;

    public ReferenceValue(int address, IType innerType) {
        this.address = address;
        this.innerType = innerType;
    }

    @Override
    public IValue compose(IValue other, String operation) throws AppException {
        throw new InvalidOperationException("InvalidOperationAppException: Cannot compose two RefValue entities using operator " + operation);
    }

    @Override
    public IType getType() {
        return new ReferenceType(innerType);
    }

    public int getAddress() {
        return address;
    }

    @Override
    public boolean equals(IValue other) {
        return (other instanceof ReferenceValue)
                && ((ReferenceValue)other).innerType != null
                && ((ReferenceValue) other).innerType.equals(this.innerType)
                && ((ReferenceValue) other).address == this.address;
    }

    @Override
    public IValue clone() {
        return new ReferenceValue(this.address, this.innerType);
    }

    @Override
    public String toString() {
        return "Reference("
                + String.valueOf(this.address)
                + ", "
                + this.innerType.toString()
                + ")";
    }

    @Override
    public String toJavaHardCode() {
        return "new ReferenceValue("
                + String.valueOf(this.address)
                + ", "
                + this.innerType.toJavaHardCode()
                + ")";
    }
}
