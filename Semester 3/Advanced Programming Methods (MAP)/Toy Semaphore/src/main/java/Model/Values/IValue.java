package Model.Values;

import Exceptions.AppException;
import Model.Types.IType;
public interface IValue {

    public IValue compose(IValue other, String operation) throws AppException;

    IType getType();

    public boolean equals(IValue other);

    public IValue clone();

    public String toString();

    public String toJavaHardCode();
}
