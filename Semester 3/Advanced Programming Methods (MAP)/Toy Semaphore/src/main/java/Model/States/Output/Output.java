package Model.States.Output;

import Model.ADTs.List.ADT_I_List;
import Model.ADTs.List.ADT_List;

import java.util.List;

public class Output implements IOutput{
    ADT_I_List<String> data;

    public Output() {
        this.data = new ADT_List<>();
    }

    @Override
    public List<String> getOutputAsList() {
        return this.data.getAll();
    }

    @Override
    public String getOutput() {
        StringBuilder answer = new StringBuilder();
        for(String elem:this.data.getAll()){
            answer.append(elem);
        }
        return answer.toString();
    }

    @Override
    public void appendToOutput(String string) {
        this.data.add(string);
    }

    @Override
    public void setOutput(String string) {
        this.data.clear();
        this.data.add(string);
    }

    @Override
    public String toString() {
        return "Output: " + this.getOutput();
    }
}


