package main;

import Controller.Controller;
import Controller.IController;
import Exceptions.AppException;
import Repository.IRepository;
import Repository.Repository;
import View.UI.View;
import gui.interpreter.MainView;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.concurrent.Executors;

public class Main {
    public static void main(String[] args) throws AppException, IOException {
        //IRepository repository = new Repository("log.txt");
        System.out.print("Select logfilePath:");
        BufferedReader reader = new BufferedReader(new java.io.InputStreamReader(System.in));
        IRepository repository = new Repository(reader.readLine().trim());
        IController controller = new Controller(repository, Executors.newFixedThreadPool(2), true);
        MainView.setController(controller);
        MainView view = new MainView();
//        View view = new View(controller);
        view.run(args);

    }
}
