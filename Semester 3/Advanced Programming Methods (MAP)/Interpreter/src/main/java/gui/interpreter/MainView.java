package gui.interpreter;

import Controller.IController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class MainView extends Application {
    static IController controller;

    public static void setController(IController controller) {
        MainView.controller = controller;
    }

    @Override
    public void start(Stage stage) throws IOException {
//        FXMLLoader fxmlLoader = new FXMLLoader(MainView.class.getResource("MainWindow.fxml"));
//        Scene scene = new Scene(fxmlLoader.load());
//        stage.setTitle("Interpreter MAP 2023 - 2024");
//        stage.setScene(scene);
//        stage.show();
//
//        Stage secondaryStage = new Stage();
//        FXMLLoader setProgramLoader = new FXMLLoader(MainView.class.getResource("SelectProgramWindow.fxml"));
//        Scene scene2 = new Scene(setProgramLoader.load());
//        secondaryStage.setTitle("Select program");
//        secondaryStage.setScene(scene2);
//        secondaryStage.show();

//        Main Window Setup
        FXMLLoader mainWindowLoader = new FXMLLoader();

        mainWindowLoader.setLocation(getClass().getResource("MainWindow.fxml"));
        mainWindowLoader.setControllerFactory(c -> new MainWindowController(controller));

        Parent mainWindowRoot = mainWindowLoader.load();
        MainWindowController mainWindowController = mainWindowLoader.getController();

        stage.setTitle("Interpreter MAP 2023 - 2024");
        stage.setScene(new Scene(mainWindowRoot));
        stage.show();

        Stage secondaryStage = new Stage();
        FXMLLoader setProgramLoader = new FXMLLoader();

        setProgramLoader.setControllerFactory(c -> new SelectProgramWindowController(controller, mainWindowController));
        setProgramLoader.setLocation(getClass().getResource("SelectProgramWindow.fxml"));

        Parent setProgramRoot = setProgramLoader.load();
        SelectProgramWindowController setProgramController = setProgramLoader.getController();

        secondaryStage.setTitle("Select program");
        secondaryStage.setScene(new Scene(setProgramRoot));
        secondaryStage.show();
    }

    public void run(String[] args) {
        launch(args);
    }

    public static void main(String[] args) {
        launch();
    }
}