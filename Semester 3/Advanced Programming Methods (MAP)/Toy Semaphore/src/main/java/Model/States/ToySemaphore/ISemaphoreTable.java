package Model.States.ToySemaphore;

import Exceptions.AppException;
import javafx.util.Pair;

import java.util.HashMap;
import java.util.List;

public interface ISemaphoreTable {
    void put(int key, Tuple<Integer, Integer, List<Integer>> value) throws AppException;
    Tuple<Integer, Integer, List<Integer>> get(int key) throws AppException;
    boolean containsKey(int key);
    int getFreeAddress();
    void setFreeAddress(int freeAddress);
    void update(int key, Tuple<Integer, Integer, List<Integer>> value) throws AppException;
    List<Pair<Integer, Tuple<Integer, Integer, List<Integer>>>> getSemaphoreDictionaryAsList();
    HashMap<Integer, Tuple<Integer, Integer, List<Integer>>> getToySemaphoreTable();
}
