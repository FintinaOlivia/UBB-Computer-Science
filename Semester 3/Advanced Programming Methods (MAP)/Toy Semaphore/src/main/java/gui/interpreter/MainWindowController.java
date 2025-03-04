package gui.interpreter;

import Controller.IController;
import Model.Statements.IStatement;
import Model.States.FileTable.IFileTable;
import Model.States.Heap.IHeap;
import Model.States.Output.IOutput;
import Model.States.ProgState;
import Model.States.ToySemaphore.ISemaphoreTable;
import Model.States.ToySemaphore.Tuple;
import Model.Values.IValue;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleObjectProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.util.Pair;

import java.util.*;

public class MainWindowController {
    IController controller;
    IHeap heap;
    IOutput output;
    IFileTable fileTable;
    ISemaphoreTable semaphoreTable;

    public MainWindowController(IController controller) {
        this.controller = controller;
    }

    @FXML
    private Label programStatesLabel;

    @FXML
    private ListView<Integer> programStatesListView;

    @FXML
    private ListView<IStatement> executionStackListView;

    @FXML
    private ListView<String> fileTableListView;

    @FXML
    private ListView<String> outListView;

    @FXML
    private TableView<Pair<Integer, IValue>> heapTableTableView;

    @FXML
    private TableColumn<Pair<Integer, IValue>, Integer> heapAddressesColumn;

    @FXML
    private TableColumn<Pair<Integer, IValue>, String> heapValuesColumn;

    @FXML
    private TableView<Pair<String, IValue>> symbolTableTableView;

    @FXML
    private TableColumn<Pair<String, IValue>, String> symbolNameColumn;

    @FXML
    private TableColumn<Pair<String, IValue>, String> symbolValueColumn;

    @FXML
    private TableView<Pair<Integer, Tuple<Integer, Integer, String>>> semaphoreTableTableView;

    @FXML
    private TableColumn<Pair<Integer, Tuple<Integer, Integer, String>>,Integer> indexSemaphoreColumn;

    @FXML
    private TableColumn<Pair<Integer, Tuple<Integer, Integer, String>>,Integer> valueSemaphoreColumn;

    @FXML
    private TableColumn<Pair<Integer, Tuple<Integer, Integer, String>>, String> listSemaphoreColumn;

    @FXML
    private Button runButton;

    @FXML
    private Button oneStepButton;

    public void refresh() {
        Integer selectedProgramId = this.programStatesListView.getSelectionModel().getSelectedItem();
        this.programStatesListView.getItems().clear();
        this.heapTableTableView.getItems().clear();
        this.outListView.getItems().clear();
        this.fileTableListView.getItems().clear();
        this.symbolTableTableView.getItems().clear();
        this.semaphoreTableTableView.getItems().clear();
        this.executionStackListView.getItems().clear();

        this.programStatesLabel.setText("Program states: " + this.controller.getProgStates().size());
        this.controller.getProgStates().forEach(progState -> this.programStatesListView.getItems().add(progState.getId()));

        if (!this.controller.getProgStates().isEmpty()) {
            this.heap = this.controller.getProgStates().getFirst().getHeap();
            this.output = this.controller.getProgStates().getFirst().getOutput();
            this.fileTable = this.controller.getProgStates().getFirst().getFileTable();
            this.semaphoreTable = this.controller.getProgStates().getFirst().getSemaphoreTable();

        }

        if (this.heap != null) {
            this.heap.toMap().forEach((key, value) ->
                    this.heapTableTableView.getItems().add(new Pair<>(key, value)));
        }

        if (this.output != null) {
            this.output.getOutputAsList().forEach(output
                    -> this.outListView.getItems().add(output.toString()));
        }

        if (this.fileTable != null) {
            this.fileTable.getFileList().forEach(key
                    -> this.fileTableListView.getItems().add(key.toString()));
        }

        if (this.semaphoreTable != null) {
            List<Pair<Integer, Tuple<Integer, Integer, List<Integer>>>> semaphoreList = this.semaphoreTable.getSemaphoreDictionaryAsList();

            semaphoreList.forEach(x -> {
                StringBuilder threadString = new StringBuilder();
                for (Integer elem : x.getValue().getThird()) {
                    if (!threadString.toString().isEmpty()) {
                        threadString.append(",");
                    }
                    threadString.append(elem);
                }
                this.semaphoreTableTableView.getItems().add(new Pair<>(x.getKey(), new Tuple<>(x.getValue().getFirst(), x.getValue().getSecond(), threadString.toString())));

            });
        }

        ProgState current;
        try{
            current = this.controller.getProgStates().stream().filter(x -> Integer.valueOf(x.getId()).equals(selectedProgramId)).findAny().get();
            current.getSymTable().toMap().forEach((x, y) -> this.symbolTableTableView.getItems().add(new Pair<>(x,y)));
            List<IStatement> statementList = current.getExecutionStack().toList();
            for(int i = statementList.size() - 1;i >= 0;i--){
                this.executionStackListView.getItems().add(statementList.get(i));
            }
            this.programStatesListView.getSelectionModel().select(selectedProgramId);
        } catch (NoSuchElementException e) {
            return ;
        } finally {
            this.programStatesListView.refresh();
            this.heapTableTableView.refresh();
            this.outListView.refresh();
            this.fileTableListView.refresh();
            this.symbolTableTableView.refresh();
            this.semaphoreTableTableView.refresh();
            this.executionStackListView.refresh();
        }
    }


    @FXML
    public void initialize() {
        this.heapAddressesColumn.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        this.heapValuesColumn.setCellValueFactory(p -> new SimpleObjectProperty<>(p.getValue().getValue().toString()));
        this.symbolNameColumn.setCellValueFactory(p -> new SimpleObjectProperty<>(p.getValue().getKey()));
        this.symbolValueColumn.setCellValueFactory(p -> new SimpleObjectProperty<>(p.getValue().getValue().toString()));
        this.indexSemaphoreColumn.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue().getFirst()).asObject());
        this.valueSemaphoreColumn.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue().getSecond()).asObject());
        this.listSemaphoreColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getValue().getThird()));

        this.refresh();

        this.oneStepButton.setOnAction(actionEvent -> {
            try {
                this.controller.executeOneStep();
            } catch (Exception e) {
                Alert alert = new Alert(Alert.AlertType.ERROR, e.getMessage());
                alert.show();
            }
            this.refresh();
        });

        this.runButton.setOnAction(actionEvent -> {
            try {
                this.controller.executeAllSteps();
            } catch (Exception e) {
                Alert alert = new Alert(Alert.AlertType.ERROR, e.getMessage());
                alert.show();
            }
            this.refresh();
        });
        this.programStatesListView.setOnMouseClicked(x -> this.refresh());
    }
}
