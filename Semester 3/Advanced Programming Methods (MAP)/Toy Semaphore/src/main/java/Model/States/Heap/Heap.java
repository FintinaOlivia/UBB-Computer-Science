package Model.States.Heap;

import Exceptions.AppException;
import Model.ADTs.Dictionary.ADT_Dictionary;
import Model.ADTs.Dictionary.ADT_I_Dictionary;
import Model.ADTs.Dictionary.Exceptions.KeyNotFoundException;
import Model.States.Heap.Exceptions.InvalidAddressException;
import Model.Values.IValue;

import java.util.Map;

public class Heap implements IHeap{
    ADT_I_Dictionary<Integer, IValue> heap;
    Integer nextFreeAddress;

    public Heap() {
        this.heap = new ADT_Dictionary<>();
        this.nextFreeAddress = 1;
        // 0 is reserved for null, which is not a valid address
    }

    @Override
    public int allocate(IValue value) {
        heap.add(nextFreeAddress, value);
        nextFreeAddress += 1;
        return nextFreeAddress - 1;
    }

    @Override
    public void deallocate(int address) throws InvalidAddressException {
        try {
            heap.remove(address);
        } catch (KeyNotFoundException e) {
            throw new InvalidAddressException("Address " + Integer.toString(address) + " out of bounds.");
        }
    }

    @Override
    public void write(int address, IValue value) throws InvalidAddressException {
        if(!heap.getAllKeys().contains(address)) {
            throw new InvalidAddressException("Address "
                    + Integer.toString(address)
                    + " out of bounds.");
        }
        heap.add(address, value);

    }

    @Override
    public IValue read(int address) throws InvalidAddressException {
        try {
            return heap.getValueForKey(address);
        } catch (KeyNotFoundException e) {
            throw new InvalidAddressException("Address "
                    + Integer.toString(address)
                    + " out of bounds.");
        }
    }

    @Override
    public Map<Integer, IValue> toMap() {
        return heap.toMap();
    }

    @Override
    public String toString(){
        StringBuilder answer = new StringBuilder("Heap:\n");
        try{
            for(int key: heap.getAllKeys()){
                answer.append(key).append("(").append(heap.getValueForKey(key).getType().toString())
                        .append(")").append(":-> ").
                        append(heap.getValueForKey(key).toString()).append("\n");
            }
        }catch(AppException exception){
            throw new RuntimeException(exception.getMessage());
        }
        return answer.toString();
    }
}
