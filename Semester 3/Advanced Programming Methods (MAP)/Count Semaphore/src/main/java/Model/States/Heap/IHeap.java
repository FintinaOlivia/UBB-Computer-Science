package Model.States.Heap;

import Model.States.Heap.Exceptions.InvalidAddressException;
import Model.Values.IValue;

import java.util.Map;

public interface IHeap {
    int allocate(IValue value);

    void deallocate(int address) throws InvalidAddressException;

    void write(int address, IValue value) throws InvalidAddressException;

    IValue read(int address) throws InvalidAddressException;

    public Map<Integer, IValue> toMap();
}
