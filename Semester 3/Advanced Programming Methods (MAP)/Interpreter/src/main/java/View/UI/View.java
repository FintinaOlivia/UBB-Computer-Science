package View.UI;

import Controller.IController;
import Exceptions.AppException;
import View.UI.ViewCommands.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static Hardcoded.HardcodedPrograms.hardcodedPrograms;

public class View {
    IController controller;
    private Command view;
    private final Command run;
    private final Command exit;

    public View(IController controller) {
        this.controller = controller;
        //this.view = new ViewCommand();
        this.run = new RunCommand(controller);
        this.exit = new ExitCommand();
    }

    private static void printMenu() {
        System.out.println("------------------- MENU ---------------------");
        System.out.println("1. Run hardcoded programs, from the following list:");
        for(int i = 0; i < hardcodedPrograms.size(); i++) {
            System.out.print("  " + (i + 1) + " : " + hardcodedPrograms.get(i).toString() + "\n");
        }
        //System.out.println("2. Step through program");
        System.out.println("* Exit *");
        System.out.println("----------------------------------------------");
    }

    public void run(String[] args) throws AppException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            try{
                printMenu();
                System.out.print("Enter command>");
                String cmd = reader.readLine().strip();
                switch(cmd){
                    case "1": {
                        System.out.print("Enter command>");
                        int subcmd = Integer.parseInt(reader.readLine().strip());

                        if(subcmd > hardcodedPrograms.size() || subcmd < 1) {
                            System.out.println("Couldn't find requested hardcoded program");
                            break;
                        }
                        else{
                            this.controller.setProgram(hardcodedPrograms.get(subcmd - 1));
                            run.execute();
                            break;
                        }
                    }

                    case "exit": {
                        exit.execute();
                        break;
                    }
                    default: {
                        System.out.println("Maybe try again? A valid command this time :)");
                        break;
                    }
                }

            } catch (AppException | IOException exception){
                System.out.println(exception.getMessage());
            }
        }

    }
}
