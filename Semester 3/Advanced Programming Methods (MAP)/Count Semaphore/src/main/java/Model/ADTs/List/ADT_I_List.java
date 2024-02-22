package Model.ADTs.List;

import java.util.List;

public interface ADT_I_List<Type> {
    void add(Type element);

    Type get(int index);

    List<Type> getAll();

    void remove(int index);

    int size();

    String toString();

    void clear();
}
