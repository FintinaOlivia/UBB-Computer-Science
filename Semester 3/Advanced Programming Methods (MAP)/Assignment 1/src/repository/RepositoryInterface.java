package repository;

import module.Object;

public interface RepositoryInterface {
    boolean addItem(Object object);
    boolean removeItem(Object object);
    Object[] getAll();
    int getCurrentSize();
}
