package View.Options;

public class ViewHardcodedOption implements IViewOption{
    public void execute(String command) {
        System.out.println("Hardcoded option");
    }
}
