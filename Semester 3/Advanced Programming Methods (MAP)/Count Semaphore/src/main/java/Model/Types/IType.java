package Model.Types;

import Exceptions.AppException;
import Model.Values.IValue;

public interface IType {
    public IValue getDefaultValue();

    public IType compose(String operation) throws AppException;

    public boolean equals(IType other);

    public String toString();

    String toJavaHardCode();

}
