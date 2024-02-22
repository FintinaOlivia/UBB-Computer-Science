package Model.ADTs.Dictionary;

import Model.ADTs.Dictionary.Exceptions.KeyNotFoundException;

import java.util.List;
import java.util.Map;

public interface ADT_I_Dictionary<Key, Value> {

    boolean isDefined(Key key);

    void add(Key key, Value value);

    void update(Key key, Value value) throws KeyNotFoundException;

    void remove(Key key) throws KeyNotFoundException;

    Value getValueForKey(Key key) throws KeyNotFoundException;

    String toString();

    ADT_I_Dictionary<Key, Value> clone();

    List<Key> getAllKeys();

    Map<Key,Value> toMap();

}
