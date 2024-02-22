package View.UI.ViewCommands;

public class ExitCommand extends Command{

    @Override
    public void execute() {
        System.out.println("Bye Bye!");
        System.exit(0);
    }

    @Override
    public String getDescription(){
        return " - Exits the program.";
    }
}
