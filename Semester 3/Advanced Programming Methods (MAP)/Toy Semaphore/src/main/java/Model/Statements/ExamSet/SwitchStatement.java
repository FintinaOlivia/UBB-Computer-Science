package Model.Statements.ExamSet;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.ADTs.List.ADT_I_List;
import Model.Expressions.BinaryExpression;
import Model.Expressions.IExpression;
import Model.Statements.IStatement;
import Model.Statements.IfStatement;
import Model.States.ProgState;
import Model.Types.IType;

import java.util.List;

/// statements should have 1 more element, the last one is the default
public class SwitchStatement implements IStatement {
    IExpression expression;
    ADT_I_List<IExpression> expressions;
    ADT_I_List<IStatement> statements;

    public SwitchStatement(IExpression expression,
                           ADT_I_List<IExpression> expressions,
                           ADT_I_List<IStatement> statements) {
        this.expression = expression;
        this.expressions = expressions;
        this.statements = statements;
    }

    @Override
    public ProgState execute(ProgState state) throws AppException {
        List<IExpression> expressions = this.expressions.getAll();
        List<IStatement> statements = this.statements.getAll();
        IStatement statement = statements.get(statements.size() - 1);
        for(int i = expressions.size() - 1;i >= 0;i--){
            statement = new IfStatement(new BinaryExpression(expression, expressions.get(i), "=="),
                    statements.get(i), statement);
        }
        state.getExecutionStack().push(statement);
        return null;
    }

    @Override
    public ADT_I_Dictionary<String, IType> typecheck(ADT_I_Dictionary<String, IType> typeDictionary) throws AppException {
        IType expressionType = expression.typecheck(typeDictionary);
        for(IStatement iter_statement:this.statements.getAll()){
            iter_statement.typecheck(typeDictionary.clone());
        }

        for(IExpression iter_expression:this.expressions.getAll()){
            if(!(iter_expression.typecheck(typeDictionary).equals(expressionType))) {
                throw new AppException("Expression type mismatch in switch");
            }
        }
        return typeDictionary;
    }

    @Override
    public String toString(){
        StringBuilder answer = new StringBuilder("Switch(" + this.expression.toString() + ")");
        List<IExpression> expressions = this.expressions.getAll();
        List<IStatement> statements = this.statements.getAll();
        for(int i = 0;i < expressions.size();i++){
            answer.append("(Case ").append(expressions.get(i).toString()).append(": ").append(statements.get(i).toString()).append(")");
        }
        answer.append("(Default: ").append(statements.get(statements.size() - 1)).append(");");
        return answer.toString();
    }
}

