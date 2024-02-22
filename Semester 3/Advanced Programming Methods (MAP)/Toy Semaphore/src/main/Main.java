package main;

import Controller.Controller;
import Controller.IController;
import Exceptions.AppException;
import Repository.IRepository;
import Repository.Repository;
import View.UI.View;
import gui.interpreter.MainView;

import java.util.concurrent.Executors;

public class Main {
    public static void main(String[] args) throws AppException {
        IRepository repository = new Repository("log.txt");
        IController controller = new Controller(repository, Executors.newFixedThreadPool(2), true);
        MainView.setController(controller);
        MainView view = new MainView();
//        View view = new View(controller);
        view.run(args);

    }
}
