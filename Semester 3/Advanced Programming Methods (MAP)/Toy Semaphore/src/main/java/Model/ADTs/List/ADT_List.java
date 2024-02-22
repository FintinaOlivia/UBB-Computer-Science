package Model.ADTs.List;

import java.util.ArrayList;
import java.util.List;

public class ADT_List<Type> implements ADT_I_List<Type>{
    List<Type> list;

    public ADT_List() {
        this.list = new ArrayList<>();
    }

    public ADT_List(List<Type> list) {
        this.list = list;
    }

    @Override
    public void add(Type element) {
        list.add(element);
    }

    @Override
    public Type get(int index) {
        return list.get(index);
    }

    @Override
    public List<Type> getAll() {
        return list;
    }

    @Override
    public void remove(int index) {
        list.remove(index);
    }

    @Override
    public int size() {
        return list.size();
    }

    @Override
    public String toString() {
        return "ADT_List{" +
                "list=" + list +
                '}';
    }

    @Override
    public boolean contains(Type element) {
        return list.contains(element);
    }

    @Override
    public void clear() {
        list.clear();
    }
}
