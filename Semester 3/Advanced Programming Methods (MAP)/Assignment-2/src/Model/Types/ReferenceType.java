package Model.Types;

import Exceptions.AppException;
import Model.Values.IValue;
import Model.Values.ReferenceValue;

public class ReferenceType implements IType{
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
        return null;
    }

    @Override
    public boolean equals(IType other) {
        return (other instanceof ReferenceType)
                && ((ReferenceType)other).innerType != null
                && ((ReferenceType) other).innerType.equals(this.innerType);
    }

    @Override
    public String toJavaHardCode() {
        return "new RefType(" + this.innerType.toJavaHardCode() + ")";
    }

}
