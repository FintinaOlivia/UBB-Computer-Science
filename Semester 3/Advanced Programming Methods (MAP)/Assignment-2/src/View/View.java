package View;

import Controller.IController;
import Exceptions.AppException;
import Hardcoded.HardcodedPrograms;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static Hardcoded.HardcodedPrograms.hardcodedPrograms;

public class View {
    IController controller;

    public View(IController controller) {
        this.controller = controller;
    }

    private static void printMenu() {
        System.out.println("1. Run hardcoded programs, from the following list:");
        System.out.println("    1. v=2;Print(v)");
        System.out.println("    2. a=2+3*5;b=a+1;Print(b)");
        System.out.println("    3. a=2-2;(If a Then v=2 Else v=3);Print(v)");
        System.out.println("2. Step through program");
        System.out.println("3. Exit");
    }

    public void run(String[] args) throws AppException {
        printMenu();

        this.controller.setProgram(hardcodedPrograms.get(3));
        //System.out.println("Program set to: " + hardcodedPrograms.get(3).toString());
        this.controller.executeAllSteps();

//        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//
//        while(true){
//            try{
//                System.out.print("Enter command>");
//                String cmd = reader.readLine().strip();
//                //menu command TO DO
//
//            } catch (AppException exception){
//                System.out.println(exception.getMessage());
//            } catch (IOException e) {
//                throw new RuntimeException(e);
//            }
//        }
//    }
    }
}
