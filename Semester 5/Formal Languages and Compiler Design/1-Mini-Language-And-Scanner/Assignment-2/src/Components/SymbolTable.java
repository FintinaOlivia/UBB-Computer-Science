package Components;

import DataStructures.HashTable;

public class SymbolTable extends HashTable {

    public SymbolTable(int size) {
        super(size);
    }

    public SymbolTable() {
        this(2);
    }
}
