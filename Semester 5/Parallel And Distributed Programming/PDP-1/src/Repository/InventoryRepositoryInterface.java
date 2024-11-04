package Repository;

import Model.Bill;
import Model.Product;

import java.util.AbstractMap;
import java.util.List;

public interface InventoryRepositoryInterface {
    void resetStock(List<AbstractMap.SimpleEntry<Product, Integer>> productList);
    void checkInventory();
    void processBill(Bill bill);
}