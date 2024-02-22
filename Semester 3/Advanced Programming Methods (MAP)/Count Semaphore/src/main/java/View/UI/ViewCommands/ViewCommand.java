//package View.CLI.ViewCommands;
//
//import Exceptions.AppException;
//import View.CLI.ViewCommands.Exceptions.ViewException;
//
//import java.util.HashMap;
//import java.util.Map;
//
//public class ViewCommand extends Command{
//    private Map<String, Command> commands;
//
//    public ViewCommand(){
//        this.commands = new HashMap<>();
//    }
//
//    @Override
//    public void execute(String command) throws AppException {
//        if(command == null){
//            throw new AppException("Please insert a command name!");
//        } else {
//            String[] args = command.trim().split(" ", 2);
//            if(this.commands.containsKey(args[0])){
//                String remaining = null;
//                if(args.length > 1){
//                    remaining = args[1];
//                }
//                this.commands.get(args[0]).execute(remaining);
//                return ;
//            }
//            throw new ViewException("No such command exists");
//        }
//
//    }
//}
