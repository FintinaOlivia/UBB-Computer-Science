package repository;

import module.Object;

//import java.util.Arrays;
//import org.apache.commons.lang3.ArrayUtils;

public class Repository implements RepositoryInterface{
    Object[] objects;
    int currentSize;


    public Repository() {
        this.objects = new Object[100];
        this.currentSize = 0;
    }

    @Override
    public boolean addItem(Object object) {
        objects[currentSize++] = object;
        return true;
    }

    @Override
    public boolean removeItem(Object object) {
        for(int i = 0; i < currentSize; i++){
            if(objects[i].equals(object)){
                objects[i] = objects[currentSize - 1];
                objects[currentSize - 1] = null;
                currentSize--;
                return true;
            }
        }
        return false;
    }

    @Override
    public Object[] getAll() {
        return objects;
    }

    @Override
    public int getCurrentSize() {
        return this.currentSize;
    }
}
