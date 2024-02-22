package Model.Statements.FileStatements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.IExpression;
import Model.Statements.IStatement;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Types.StringType;
import Model.Values.IValue;
import Model.Values.StringValue;

public class CloseFileStatement implements IStatement {
    IExpression expression;

    public CloseFileStatement(IExpression expression){
        this.expression = expression;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        IValue value = this.expression.evaluate(state);
        if(!(value.getType() instanceof StringType)){
            throw new AppException("Filename did not evaluate to string");
        }
        state.getFileTable().closeFile(((StringValue)value).getValue());
        return null;
    }

    @Override
    public String toString(){
        return "closeReadFile(" + this.expression.toString() + ")";
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        if((new StringType()).equals(expression.typecheck(typeDictionary))){
            return typeDictionary;
        }
        throw new AppException(" 'Close File' Expression doesn't evaluate to a StringType");
    }

}
