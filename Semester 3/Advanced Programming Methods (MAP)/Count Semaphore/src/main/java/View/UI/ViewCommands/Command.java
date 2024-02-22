package View.UI.ViewCommands;

import Exceptions.AppException;

public abstract class Command{
    private final String key;
    private final String description;

    public Command(String key, String description){
        this.key = key;
        this.description = description;
    }

    public Command(){
        this.key = "";
        this.description = "";
    }

    public abstract void execute() throws AppException;

    public String getKey() {
        return key;
    }

    public String getDescription() {
        return description;
    }
}
