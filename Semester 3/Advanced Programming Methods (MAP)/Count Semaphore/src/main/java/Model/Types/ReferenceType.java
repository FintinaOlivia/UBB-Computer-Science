package Model.Types;

import Exceptions.AppException;
import Model.Values.IValue;
import Model.Values.ReferenceValue;

public class ReferenceType implements IType {
    IType innerType;

    public ReferenceType(IType innerType) {
        this.innerType = innerType;
    }

    @Override
    public IValue getDefaultValue() {
        return new ReferenceValue(0, innerType);
    }

    @Override
    public IType compose(String operation) throws AppException {
        throw new AppException("Invalid Operation: Cannot compose two RefValue types using operator " + operation);
    }

    @Override
    public boolean equals(IType other) {
        return (other instanceof ReferenceType)
                && ((ReferenceType)other).innerType != null
                && ((ReferenceType) other).innerType.equals(this.innerType);
    }

    @Override
    public String toString(){
        return "Ref(" + innerType.toString() + ")";
    }
    @Override
    public String toJavaHardCode() {
        return "new RefType(" + this.innerType.toJavaHardCode() + ")";
    }

    public IType getInner() {
        return innerType;
    }
}
