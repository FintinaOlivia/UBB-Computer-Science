package Model.States.Output;

import java.util.List;

public interface IOutput {

    public List<String> getOutputAsList();

    public String getOutput();

    public void setOutput(String string);

    public void appendToOutput(String string);

    public String toString();

}
