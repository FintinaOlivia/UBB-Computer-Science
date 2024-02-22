package Model.Statements.FileStatements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.Expressions.IExpression;
import Model.Statements.IStatement;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Types.IntegerType;
import Model.Types.StringType;
import Model.Values.IValue;
import Model.Values.IntegerValue;
import Model.Values.StringValue;

public class ReadFileStatement implements IStatement {
    IExpression expression;
    String name;

    public ReadFileStatement(IExpression expression, String name){
        this.expression = expression;
        this.name = name;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        IValue value = this.expression.evaluate(state);
        if(!(value.getType() instanceof StringType)) {
            throw new AppException("Filename did not evaluate to string");
        }
        state.getSymTable().setValue(name,
                new IntegerValue(state.getFileTable().readFile(((StringValue)value).getValue())));
        return null;
    }

    @Override
    public String toString(){
        return "readFile(" + this.expression.toString() + "," + this.name + ")";
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        if(!(new StringType()).equals(expression.typecheck(typeDictionary))){
            throw new AppException("Read file expression does not evaluate to a string");
        }
        if(!typeDictionary.getValueForKey(name).equals(new IntegerType())){
            throw new AppException("Read file value is not of IntegerType type(ReadFileStatement)");
        }
        return typeDictionary;
    }

}
