package DataStructures;

import java.util.ArrayList;

public class HashTable {
    private Integer size;
    private Integer elementCount;
    private ArrayList<ArrayList<String>> table;
    private static final Double LOAD_FACTOR_THRESHOLD = 0.75;

    public HashTable(Integer size) {
        this.size = size;
        this.elementCount = 0;
        this.table = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            this.table.add(new ArrayList<>());
        }
    }

    public Pair<Integer, Integer> findPositionOfTerm(String term) {
        int pos = hash(term);

        if (!table.get(pos).isEmpty()) {
            ArrayList<String> elems = this.table.get(pos);
            for (int i = 0; i < elems.size(); i++) {
                if (elems.get(i).equals(term)) {
                    return new Pair<>(pos, i);
                }
            }
        }
        return null;
    }

    public Integer getSize() {
        return size;
    }

    private Integer hash(String key) {
        int hash = 0;
        int prime = 31;
        for (int i = 0; i < key.length(); i++) {
            hash = prime * hash + key.charAt(i);
        }
        return Math.abs(hash) % size;
    }

    public boolean containsTerm(String term) {
        return this.findPositionOfTerm(term) != null;
    }

    public boolean add(String term) {
        if (containsTerm(term)) {
            return false;
        }

        Integer pos = hash(term);
        ArrayList<String> elems = this.table.get(pos);
        elems.add(term);
        elementCount++;

        if (getLoadFactor() > LOAD_FACTOR_THRESHOLD) {
            resize();
        }

        return true;
    }

    private double getLoadFactor() {
        return (double) elementCount / size;
    }

    private void resize() {
        int newSize = size * 2;
        ArrayList<ArrayList<String>> newTable = new ArrayList<>();
        for (int i = 0; i < newSize; i++) {
            newTable.add(new ArrayList<>());
        }

        for (ArrayList<String> bucket : table) {
            for (String term : bucket) {
                int newPos = hashWithNewSize(term, newSize);
                newTable.get(newPos).add(term);
            }
        }

        this.table = newTable;
        this.size = newSize;
    }

    private int hashWithNewSize(String key, int newSize) {
        int hash = 0;
        int prime = 31;
        for (int i = 0; i < key.length(); i++) {
            hash = prime * hash + key.charAt(i);
        }
        return Math.abs(hash) % newSize;
    }

    @Override
    public String toString() {
        return "\n{ "
                + "elements = "
                + table
                + ", "
                + "size = "
                + size + " }";
    }
}

