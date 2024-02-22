module gui.interpreter {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires org.kordamp.bootstrapfx.core;

    opens gui.interpreter to javafx.fxml;
    exports gui.interpreter;
}