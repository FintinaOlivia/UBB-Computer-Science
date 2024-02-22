package View.UI.ViewCommands;

import Controller.IController;
import Exceptions.AppException;

public class RunCommand extends Command {
    IController controller;

    public RunCommand(IController controller){
        this.controller = controller;
    }

    @Override
    public void execute() throws AppException {
        this.controller.executeAllSteps();
    }

    @Override
    public String getDescription(){
        return " - Runs all the steps of the selected program.";
    }
}
