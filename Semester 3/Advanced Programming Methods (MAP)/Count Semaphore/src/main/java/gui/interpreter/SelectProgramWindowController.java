package gui.interpreter;

import Controller.IController;
import Hardcoded.HardcodedPrograms;
import Model.Statements.IStatement;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;

public class SelectProgramWindowController {
    IController controller;
    MainWindowController mainWindowController;

    @FXML
    private ListView<IStatement> programsListView;

    @FXML
    private Button selectProgramButton;

    public SelectProgramWindowController(IController controller, MainWindowController mainWindowController) {
        this.controller = controller;
        this.mainWindowController = mainWindowController;
    }

    @FXML
    public void initialize() {
        programsListView.setItems(FXCollections.observableList(HardcodedPrograms.hardcodedPrograms));
        selectProgramButton.setOnAction(actionEvent -> {
            try{
                int index = programsListView.getSelectionModel().getSelectedIndex();
                if (index < 0) {
                    System.out.println("No index selected");
                } else if (index >= HardcodedPrograms.hardcodedPrograms.size()) {
                    System.out.println("No program at selected index");
                } else {
                    System.out.println("Selected program " + index);
                }
                this.controller.setProgram(HardcodedPrograms.hardcodedPrograms.get(index));
                this.controller.logProgramState();
                this.mainWindowController.refresh();
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        });
        this.mainWindowController.refresh();
    }
}
