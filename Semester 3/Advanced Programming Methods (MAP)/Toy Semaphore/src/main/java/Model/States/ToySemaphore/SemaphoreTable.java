package Model.States.ToySemaphore;

import Exceptions.AppException;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.locks.ReentrantLock;

public class SemaphoreTable implements ISemaphoreTable {
    private HashMap<Integer, Tuple<Integer, Integer, List<Integer>>> toySemaphoreTable;
    private int freeLocation = 0;

    ReentrantLock lock;

    public SemaphoreTable() {
        this.toySemaphoreTable = new HashMap<>();
        this.lock = new ReentrantLock();
    }

    @Override
    public void put(int key, Tuple<Integer, Integer, List<Integer>> value) throws AppException {
        synchronized (this) {
            if (!toySemaphoreTable.containsKey(key)) {
                toySemaphoreTable.put(key, value);
            } else {
                throw new AppException("Toy semaphore table already contains the key");
            }
        }
    }

    @Override
    public Tuple<Integer, Integer, List<Integer>> get(int key) throws AppException {
        synchronized (this) {
            if (toySemaphoreTable.containsKey(key)) {
                return toySemaphoreTable.get(key);
            } else {
                throw new AppException("Toy semaphore table doesn't contain the key");
            }
        }
    }

    @Override
    public boolean containsKey(int key) {
        synchronized (this) {
            return toySemaphoreTable.containsKey(key);
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
    public void update(int key, Tuple<Integer, Integer, List<Integer>> value) throws AppException {
        synchronized (this) {
            if (toySemaphoreTable.containsKey(key)) {
                toySemaphoreTable.replace(key, value);
            } else {
                throw new AppException("Toy semaphore table doesn't contain key!");
            }
        }
    }

    @Override
    public HashMap<Integer, Tuple<Integer, Integer, List<Integer>>> getToySemaphoreTable() {
        synchronized (this) {
            return toySemaphoreTable;
        }
    }

    @Override
    public List<Pair<Integer, Tuple<Integer, Integer, List<Integer>>>> getSemaphoreDictionaryAsList() {
        this.lock.lock();
        List<Pair<Integer, Tuple<Integer, Integer, List<Integer>>>> result = new ArrayList<>();
        for (Integer key : toySemaphoreTable.keySet()) {
            result.add(new Pair<>(key, toySemaphoreTable.get(key)));
        }
        this.lock.unlock();
        return result;
    }

    @Override
    public String toString() {
        synchronized (this) {
            StringBuilder result = new StringBuilder();
            result.append("Semaphore Table:\n");
            for (Integer key : toySemaphoreTable.keySet()) {
                result.append(key.toString()).append(" -> ").append(toySemaphoreTable.get(key).toString()).append("\n");
            }
            return result.toString();
        }
    }
}
