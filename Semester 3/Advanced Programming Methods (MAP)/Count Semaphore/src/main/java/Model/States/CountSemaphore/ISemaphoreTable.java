package Model.States.CountSemaphore;

import Exceptions.AppException;
import Model.ADTs.List.ADT_I_List;
import javafx.util.Pair;

import java.util.HashMap;
import java.util.List;

public interface ISemaphoreTable {
        void put(int key, Pair<Integer, List<Integer>> value) throws AppException;
        Pair<Integer, List<Integer>> get(int key) throws AppException;
        boolean containsKey(int key);
        int getFreeAddress();
        void setFreeAddress(int freeAddress);
        void update(int key, Pair<Integer, List<Integer>> value) throws AppException;
        HashMap<Integer, Pair<Integer, List<Integer>>> getSemaphoreTable();
        List<Pair<Pair<Integer, Integer>, List<Integer>>> getSemaphoreDictionaryAsList();
        void setSemaphoreTable(HashMap<Integer, Pair<Integer, List<Integer>>> newSemaphoreTable);
}
