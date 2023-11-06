package Model.Expressions;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.States.ProgState;
import Model.Values.IValue;
import Model.Types.IType;

public interface IExpression {
        public IValue evaluate(ProgState state) throws AppException;

        public String toString();

        IType typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException;

        String toJavaHardCode();
}
