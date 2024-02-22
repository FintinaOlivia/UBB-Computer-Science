package Hardcoded;

import Model.ADTs.List.ADT_List;
import Model.Expressions.BinaryExpression;
import Model.Expressions.ConstantExpression;
import Model.Expressions.ReadHeapExpression;
import Model.Expressions.VariableExpression;
import Model.Statements.*;
import Model.Statements.SwitchStatement;
import Model.Statements.FileStatements.OpenFileStatement;
import Model.Statements.FileStatements.ReadFileStatement;
import Model.Statements.FileStatements.CloseFileStatement;
import Model.Statements.Semaphore.AcquireStatement;
import Model.Statements.Semaphore.CreateSemaphoreStatement;
import Model.Statements.Semaphore.ReleaseStatement;
import Model.Types.BooleanType;
import Model.Types.IntegerType;
import Model.Types.ReferenceType;
import Model.Types.StringType;
import Model.Values.BooleanValue;
import Model.Values.IntegerValue;
import Model.Values.StringValue;

import java.util.ArrayList;
import java.util.Arrays;
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
                                                                            new CloseFileStatement(new VariableExpression("varf")))))))))),

            new CompositeStatement(new VariableDeclarationStatement("v",new ReferenceType(new IntegerType())),
                    new CompositeStatement(new NewStatement("v", new ConstantExpression(new IntegerValue(20))),
                            new CompositeStatement(new VariableDeclarationStatement("a",new ReferenceType(new ReferenceType(new IntegerType()))),
                                    new CompositeStatement(new NewStatement("a", new VariableExpression("v")),
                                            new CompositeStatement(new PrintStatement(new VariableExpression("v")),
                                                    new PrintStatement(new VariableExpression("a"))))))),

            new CompositeStatement(new VariableDeclarationStatement("v",new ReferenceType(new IntegerType())),
                    new CompositeStatement(new NewStatement("v", new ConstantExpression(new IntegerValue(20))),
                            new CompositeStatement(new VariableDeclarationStatement("a",new ReferenceType(new ReferenceType(new IntegerType()))),
                                    new CompositeStatement(new NewStatement("a", new VariableExpression("v")),
                                            new CompositeStatement(new PrintStatement(new ReadHeapExpression(
                                                    new VariableExpression("v"))), new PrintStatement(new BinaryExpression(
                                                            new ReadHeapExpression(new ReadHeapExpression(new VariableExpression("a"))),
                                                    new ConstantExpression(new IntegerValue(5)),"+"))))))),

            new CompositeStatement(new VariableDeclarationStatement("v",new ReferenceType(new IntegerType())),
                    new CompositeStatement(new NewStatement("v", new ConstantExpression(new IntegerValue(20))),
                            new CompositeStatement(new PrintStatement(new ReadHeapExpression(new VariableExpression("v"))),
                                    new CompositeStatement(new WriteHeapStatement(new VariableExpression("v"),
                                            new ConstantExpression(new IntegerValue(30))), new PrintStatement(new BinaryExpression(
                                                    new ReadHeapExpression(new VariableExpression("v")),
                                            new ConstantExpression(new IntegerValue(5)),"+")))))),

            new CompositeStatement(new VariableDeclarationStatement("v",new ReferenceType(new IntegerType())),
                    new CompositeStatement(new NewStatement("v", new ConstantExpression(new IntegerValue(20))),
                            new CompositeStatement(new VariableDeclarationStatement("a",new ReferenceType(new ReferenceType(new IntegerType()))),
                                    new CompositeStatement(new NewStatement("a", new VariableExpression("v")),
                                            new CompositeStatement(new NewStatement("v", new ConstantExpression(new IntegerValue(30))),
                                                    new PrintStatement(new ReadHeapExpression(new ReadHeapExpression
                                                            (new VariableExpression("a"))))))))),

            new CompositeStatement(new VariableDeclarationStatement("v",new IntegerType()),
                    new CompositeStatement(new AssignmentStatement("v", new ConstantExpression(new IntegerValue(4))),
                            new CompositeStatement(new WhileStatement(new BinaryExpression(new VariableExpression("v"),
                                    new ConstantExpression(new IntegerValue(0)),">"),
                                    new CompositeStatement(new PrintStatement(new VariableExpression("v")),
                                            new AssignmentStatement("v",new BinaryExpression(new VariableExpression("v"),
                                                    new ConstantExpression(new IntegerValue(1)),"-")))),
                                                    new PrintStatement(new VariableExpression("v"))))),

            new CompositeStatement(new VariableDeclarationStatement("v",new IntegerType()),
                    new CompositeStatement(new VariableDeclarationStatement("a",new ReferenceType(new IntegerType())),
                            new CompositeStatement(new AssignmentStatement("v",new ConstantExpression(new IntegerValue(10))),
                                    new CompositeStatement(new NewStatement("a", new ConstantExpression(new IntegerValue(22))),
                                            new CompositeStatement(new ForkStatement(
                                                    new CompositeStatement(new WriteHeapStatement(new VariableExpression("a"),
                                                            new ConstantExpression(new IntegerValue(30))),
                                                            new CompositeStatement(new AssignmentStatement("v",new ConstantExpression(new IntegerValue(32))),
                                                                    new CompositeStatement(new PrintStatement(new VariableExpression("v")),
                                                                            new PrintStatement(new ReadHeapExpression(new VariableExpression("a"))))))),
                                                    new CompositeStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new ReadHeapExpression(new VariableExpression("a")))))))))
            ,
            // ref(String) x; String y = "Hello"; x = new Ref(String) y; print(readHeap(x))
            new CompositeStatement(new VariableDeclarationStatement("x", new ReferenceType(new StringType())),
                    new CompositeStatement(new VariableDeclarationStatement("y", new StringType()),
                            new CompositeStatement(new AssignmentStatement("y", new ConstantExpression(new StringValue("Hello"))),
                            new CompositeStatement(new NewStatement("x", new VariableExpression("y")),
                                    new PrintStatement(new ReadHeapExpression(new VariableExpression("x")))))))

            ,
//            a = 1, b = 2, c = 5,
//            switch(a * 10)
//            (case (b * c) print(a) print(b))
//            (case (10) print(100) print(200))
//            (default print(300))
//            print(300)

            new CompositeStatement(new VariableDeclarationStatement("a",new IntegerType()),
                    new CompositeStatement(new VariableDeclarationStatement("b",new IntegerType()),
                            new CompositeStatement(new VariableDeclarationStatement("c",new IntegerType()),
                                    new CompositeStatement(new AssignmentStatement("a",new ConstantExpression(new IntegerValue(1))),
                                            new CompositeStatement(new AssignmentStatement("b",new ConstantExpression(new IntegerValue(2))),
                                                    new CompositeStatement(new AssignmentStatement("c",new ConstantExpression(new IntegerValue(5))),
                                                            new CompositeStatement(new SwitchStatement(new BinaryExpression(new VariableExpression("a"),
                                                                    new ConstantExpression(new IntegerValue(10)),"*"),new ADT_List<>(Arrays.asList(
                                                                            new BinaryExpression(new VariableExpression("b"),new VariableExpression("c"),"*"),
                                                                    new ConstantExpression(new IntegerValue(10)))), new ADT_List<>(Arrays.asList(
                                                                            new CompositeStatement(new PrintStatement(new VariableExpression("a")),
                                                                                    new PrintStatement(new VariableExpression("b"))),
                                                                    new CompositeStatement(
                                                                            new PrintStatement(new ConstantExpression(new IntegerValue(100))),
                                                                            new PrintStatement(new ConstantExpression(new IntegerValue(200)))),
                                                                            new PrintStatement(new ConstantExpression(new IntegerValue(300)))))),
                                                                    new PrintStatement(new ConstantExpression(new IntegerValue(300))))))))))
            ,

            new CompositeStatement(new VariableDeclarationStatement("v1",new ReferenceType(new IntegerType())),
                    new CompositeStatement(new VariableDeclarationStatement("cnt",new IntegerType()),
                            new CompositeStatement(new NewStatement("v1", new ConstantExpression(new IntegerValue(1))),
                                    new CompositeStatement(new CreateSemaphoreStatement("cnt",
                                            new ReadHeapExpression(new VariableExpression("v1"))),
                                            new CompositeStatement(new ForkStatement(
                                                    new CompositeStatement(new AcquireStatement("cnt"),
                                                            new CompositeStatement(new WriteHeapStatement(new VariableExpression("v1"),
                                                                    new BinaryExpression(new ReadHeapExpression(new VariableExpression("v1")),
                                                                            new ConstantExpression(new IntegerValue(10)),"*")),
                                                                    new CompositeStatement(new PrintStatement(new ReadHeapExpression(new VariableExpression("v1"))),
                                                                            new ReleaseStatement("cnt"))))),
                                                    new CompositeStatement(new ForkStatement(new CompositeStatement(new AcquireStatement("cnt"),
                                                            new CompositeStatement(new WriteHeapStatement(new VariableExpression("v1"),
                                                                    new BinaryExpression(new ReadHeapExpression(new VariableExpression("v1")),
                                                                            new ConstantExpression(new IntegerValue(10)),"*")),
                                                                    new CompositeStatement(new WriteHeapStatement(new VariableExpression("v1"),
                                                                            new BinaryExpression(new ReadHeapExpression(new VariableExpression("v1")),
                                                                                    new ConstantExpression(new IntegerValue(2)),"*")),
                                                                            new CompositeStatement(new PrintStatement(new ReadHeapExpression(
                                                                                    new VariableExpression("v1"))), new ReleaseStatement("cnt")))))),
                                                            new CompositeStatement(new AcquireStatement("cnt"),
                                                                    new CompositeStatement(new PrintStatement(new BinaryExpression(
                                                                            new ReadHeapExpression(new VariableExpression("v1")),
                                                                            new ConstantExpression(new IntegerValue(1)),"-")), new ReleaseStatement("cnt")))))))))

    ));
}
