package Model.States.CountSemaphore;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_Dictionary;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.ADTs.List.ADT_I_List;
import Model.ADTs.List.ADT_List;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.locks.ReentrantLock;

public class SemaphoreTable implements ISemaphoreTable {

    private HashMap<Integer, Pair<Integer, List<Integer>>> semaphoreTable;
    ReentrantLock lock;
    private int freeLocation = 0;

    public SemaphoreTable() {
        this.semaphoreTable = new HashMap<>();
        this.lock = new ReentrantLock();
    }

    @Override
    public void put(int key, Pair<Integer, List<Integer>> value) throws AppException {
        synchronized (this) {
            if (!semaphoreTable.containsKey(key)) {
                semaphoreTable.put(key, value);
            } else {
                throw new AppException("Semaphore table already contains the key!");
            }
        }
    }

    @Override
    public Pair<Integer, List<Integer>> get(int key) throws AppException {
        synchronized (this) {
            if (semaphoreTable.containsKey(key)) {
                return semaphoreTable.get(key);
            } else {
                throw new AppException(String.format("Semaphore table doesn't contain the key %d!", key));
            }
        }
    }

    @Override
    public boolean containsKey(int key) {
        synchronized (this) {
            return semaphoreTable.containsKey(key);
        }
    }

    @Override
    public int getFreeAddress() {
        synchronized (this) {
            freeLocation++;
            return freeLocation;
        }
    }

    @Override
    public void setFreeAddress(int freeAddress) {
        synchronized (this) {
            this.freeLocation = freeAddress;
        }
    }

    @Override
    public void update(int key, Pair<Integer, List<Integer>> value) throws AppException {
        synchronized (this) {
            if (semaphoreTable.containsKey(key)) {
                semaphoreTable.replace(key, value);
            } else {
                throw new AppException("Semaphore table doesn't contain key");
            }
        }
    }

    @Override
    public HashMap<Integer, Pair<Integer, List<Integer>>> getSemaphoreTable() {
        synchronized (this) {
            return semaphoreTable;
        }
    }

    @Override
    public void setSemaphoreTable(HashMap<Integer, Pair<Integer, List<Integer>>> newSemaphoreTable) {
        synchronized (this) {
            this.semaphoreTable = newSemaphoreTable;
        }
    }

//    HashMap<Integer, Pair<Integer, List<Integer>>> to list

    public List<Pair<Pair<Integer, Integer>, List<Integer>>> getSemaphoreDictionaryAsList() {
        this.lock.lock();
        List<Pair<Pair<Integer, Integer>, List<Integer> > > answer = new ArrayList<>();
        this.semaphoreTable.forEach((x, y) -> {
            answer.add(new Pair<>(new Pair<>(x, y.getKey()), y.getValue()));
        });
        this.lock.unlock();
        return answer;
    }

    @Override
    public String toString() {
        return semaphoreTable.toString();
    }
}
