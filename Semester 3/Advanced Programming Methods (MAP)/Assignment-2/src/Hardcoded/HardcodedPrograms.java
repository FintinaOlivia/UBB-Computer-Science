package Hardcoded;

import Model.Expressions.BinaryExpression;
import Model.Expressions.ConstantExpression;
import Model.Expressions.VariableExpression;
import Model.Statements.*;
import Model.Statements.FileStatements.OpenFileStatement;
import Model.Statements.FileStatements.ReadFileStatement;
import Model.Statements.FileStatements.CloseFileStatement;
import Model.Types.BooleanType;
import Model.Types.IntegerType;
import Model.Types.StringType;
import Model.Values.BooleanValue;
import Model.Values.IntegerValue;
import Model.Values.StringValue;

import java.util.ArrayList;
import java.util.List;

public class HardcodedPrograms {
    public static final List<IStatement> hardcodedPrograms = new ArrayList<IStatement>(List.of(
            new CompositeStatement(
                    new VariableDeclarationStatement("v",new IntegerType()),
                    new CompositeStatement(new AssignmentStatement("v",
                            new ConstantExpression(new IntegerValue(2))),
                            new PrintStatement(
                                    new VariableExpression("v")))),

            new CompositeStatement(new VariableDeclarationStatement("a",new IntegerType()),
                    new CompositeStatement(new AssignmentStatement("a",new BinaryExpression(
                            new ConstantExpression(new IntegerValue(2)),
                            new BinaryExpression(
                                    new ConstantExpression(new IntegerValue(3)),
                                    new ConstantExpression(new IntegerValue(5)),"*"),"+")),
                            new CompositeStatement(new VariableDeclarationStatement("b",new IntegerType()),
                                    new CompositeStatement(new AssignmentStatement("b",
                                            new BinaryExpression(new BinaryExpression(new VariableExpression("a"),
                                                    new BinaryExpression(new ConstantExpression(new IntegerValue(4)),
                                                            new ConstantExpression(new IntegerValue(2)),"/"),"-"),
                                                    new ConstantExpression(new IntegerValue(7)),"+")),
                                            new PrintStatement(new VariableExpression("b")))))),

            new CompositeStatement(new VariableDeclarationStatement("a",new BooleanType()),
                    new CompositeStatement(new AssignmentStatement("a",new ConstantExpression(new BooleanValue(false))),
                            new CompositeStatement(new VariableDeclarationStatement("v",new IntegerType()),
                                    new IfStatement(new VariableExpression("a"),
                                            new AssignmentStatement("v",new ConstantExpression(new IntegerValue(2))),
                                            new AssignmentStatement("v",new ConstantExpression(new IntegerValue(3))))))),

            new CompositeStatement(new VariableDeclarationStatement("varf",new StringType()),
                    new CompositeStatement(new AssignmentStatement("varf",
                            new ConstantExpression(new StringValue("test.txt"))),
                            new CompositeStatement(new OpenFileStatement(new VariableExpression("varf")),
                                    new CompositeStatement(new VariableDeclarationStatement("varc",new IntegerType()),
                                            new CompositeStatement(new ReadFileStatement(new VariableExpression("varf"), "varc"),
                                                    new CompositeStatement(new PrintStatement(new VariableExpression("varc")),
                                                            new CompositeStatement(new ReadFileStatement(new VariableExpression("varf"), "varc"),
                                                                    new CompositeStatement(new PrintStatement(new VariableExpression("varc")),
                                                                            new CloseFileStatement(new VariableExpression("varf"))))))))))

            ));

}
