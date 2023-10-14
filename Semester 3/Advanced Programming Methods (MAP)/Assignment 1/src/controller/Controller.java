package controller;

import module.Object;
import repository.Repository;
import repository.RepositoryInterface;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Controller {
    RepositoryInterface repository;

    public Controller(RepositoryInterface repository) {
        this.repository = repository;
    }

    public Controller() {
        this.repository = new Repository();
    }

    public void addItem(Object object) {
        if(object.getVolume() > 0 && object.getParameter() > 0){
            repository.addItem(object);
        }else{
            throw new RuntimeException("Please add a valid volume");
        }
    }

    public void removeItem(Object object) {
        if(!repository.removeItem(object)){
            throw new RuntimeException("Could not remove object");
        }
    }

    public List<Object> getAll() {
        List<Object> list = new ArrayList<>();
        for(int i =0; i<this.repository.getCurrentSize(); i++)
            list.add(repository.getAll()[i]);
        return list;
    }

    public int getCurrentSize() {
        return repository.getCurrentSize();
    }

    public List<Object> filter(float volume){
        if(volume < 0){
            throw new RuntimeException("Please add a valid volume");
        }else{
            if (volume == 0) {
                throw new RuntimeException("Please add a non-zero volume");
            } else {
                List<Object> filteredList = new ArrayList<>();

                for(Object object : getAll()) {
                    if (object.getVolume() > volume)
                        filteredList.add(object);
                }
                return filteredList;
            }
        }

    }
}
