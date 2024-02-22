package Controller;

import Model.States.Heap.Exceptions.InvalidAddressException;
import Model.States.Heap.IHeap;
import Model.States.ProgState;
import Model.Types.ReferenceType;
import Model.Values.IValue;
import Model.Values.ReferenceValue;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class GarbageCollector {
    public static void runGarbageCollector(List<ProgState> states){
        if(states.size() < 1){
            return ;
        }
        IHeap heap = states.get(0).getHeap();
        List<Integer> activeAddresses = states.stream().flatMap(e -> GarbageCollector.getActiveAddressesForState(e).stream()).toList();
        heap.toMap().keySet().stream().filter(e -> !activeAddresses.contains(e)).forEach(e -> {
            try {
                heap.deallocate(e);
            } catch (InvalidAddressException ex) {
                throw new RuntimeException(ex);
            }
        });
    }

    private static List<Integer> getActiveAddressesForState(ProgState state) {
        return state.getSymTable().toMap().values().stream()
                .filter(e -> e.getType() instanceof ReferenceType)
                .map(e -> (ReferenceValue) e)
                .flatMap(value -> {
                    List<Integer> addresses = new ArrayList<Integer>();
                    while (true) {
                        if(value.getAddress() == 0){
                            break;
                        }
                        addresses.add(value.getAddress());
                        IValue next_value;
                        try {
                            next_value = state.getHeap().read(value.getAddress());
                        } catch (InvalidAddressException e) {
                            throw new RuntimeException(e);
                        }
                        if (!(next_value.getType() instanceof ReferenceType)) {
                            break;
                        }
                        value = (ReferenceValue) next_value;
                    }
                    return addresses.stream();
                }).collect(Collectors.toList());
    }
}
