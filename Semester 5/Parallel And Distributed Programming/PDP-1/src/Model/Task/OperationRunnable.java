package Model.Task;
import Model.Bill;
import Repository.InventoryRepositoryInterface;

import java.util.List;

public class OperationRunnable implements Runnable {

    private final InventoryRepositoryInterface inventory;
    private final List<Bill> billList;

    public OperationRunnable(InventoryRepositoryInterface inventory, List<Bill> billList) {
        this.inventory = inventory;
        this.billList = billList;
    }

    @Override
    public void run() {
        try {
            billList.forEach(inventory::processBill);
            inventory.checkInventory();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}