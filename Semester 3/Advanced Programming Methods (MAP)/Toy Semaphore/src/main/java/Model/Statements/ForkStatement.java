package Model.Statements;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.States.ExecutionStack.ExecutionStack;
import Model.States.ProgState;
import Model.Types.IType;
import Model.Values.IValue;

public class ForkStatement implements IStatement{
    IStatement innerStatement;

    public ForkStatement(IStatement innerStatement) {
        this.innerStatement = innerStatement;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        return new ProgState(new ExecutionStack(),
                state.getSymTable().copy(),
                state.getOutput(),
                state.getFileTable(),
                state.getHeap(),
                state.getSemaphoreTable(),
                innerStatement);
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        return innerStatement.typecheck(typeDictionary);
    }


    @Override
    public String toString(){
        return "fork(" + innerStatement.toString() + ")";
    }
}
