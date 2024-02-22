package Repository;

import Model.States.ProgState;

import java.util.List;

public interface IRepository {
    public List<ProgState> getProgramsList();

    public void setProgramsList(List<ProgState> programs);

    public void addProgram(ProgState program);

    public void logProgramState(ProgState program);

    public void clear();
}
