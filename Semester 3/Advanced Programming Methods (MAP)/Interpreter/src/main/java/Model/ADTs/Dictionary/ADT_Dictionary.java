package Model.ADTs.Dictionary;

import Model.ADTs.Dictionary.Exceptions.KeyNotFoundException;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ADT_Dictionary<Key, Value> implements ADT_I_Dictionary<Key, Value> {
    HashMap<Key, Value> dictionary;

    public ADT_Dictionary() {
        this.dictionary = new HashMap<>();
    }

    @Override
    public boolean isDefined(Key key) {
        return this.dictionary.containsKey(key);
    }

    @Override
    public void add(Key key, Value value) {
        this.dictionary.put(key, value);
    }

    @Override
    public void update(Key key, Value value) throws KeyNotFoundException {
        this.dictionary.put(key, value);
    }

    @Override
    public void remove(Key key) throws KeyNotFoundException {
        this.dictionary.remove(key);
    }

    @Override
    public Value getValueForKey(Key key) {
        return this.dictionary.get(key);
    }

    @Override
    public String toString() {
        return "ADT_Dictionary{" +
                "dictionary=" + dictionary +
                '}';
    }

    @Override
    public ADT_I_Dictionary<Key, Value> clone() {
        ADT_I_Dictionary<Key, Value> clone = new ADT_Dictionary<Key, Value>();
        for (Key key : this.dictionary.keySet()) {
            clone.add(key, this.dictionary.get(key));
        }
        return clone;
    }

    @Override
    public List<Key> getAllKeys() {
        return new ArrayList<>(this.dictionary.keySet());
    }

    @Override
    public Map<Key, Value> toMap() {
        return this.dictionary;
    }
}
