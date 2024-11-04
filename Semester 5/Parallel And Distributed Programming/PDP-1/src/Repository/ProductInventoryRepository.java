package Repository;

import Model.Bill;
import Model.Product;

import java.util.*;

public class ProductInventoryRepository implements InventoryRepositoryInterface {
    private Map<Product, Integer> initialStock;
    private Map<Product, Integer> currentStock;
    private int income;
    private final List<Bill> processedBills;

    public ProductInventoryRepository(){
        this.initialStock = new HashMap<>();
        this.currentStock = new HashMap<>();
        this.income = 0;
        this.processedBills = new ArrayList<>();
    }

    @Override
    public synchronized void resetStock(List<AbstractMap.SimpleEntry<Product, Integer>> productList) {
        this.initialStock = new HashMap<>();
        this.currentStock = new HashMap<>();

        productList.forEach(product -> {
            initialStock.put(product.getKey(), product.getValue());
            currentStock.put(product.getKey(), product.getValue());
        });
    }

    @Override
    public synchronized void checkInventory() {
        System.out.println("Checking inventory!");
        int expectedSum = this.processedBills.stream()
                .map(Bill::getTotalSum)
                .reduce(0, Integer::sum);

        if (expectedSum != this.income) {
            System.out.println("Inventory check failed - money laundering is going on");
        } else {
            System.out.println("Inventory check successful - it's not much, but it's honest work");
        }

    }

    @Override
    public void processBill(Bill bill) {
        for (AbstractMap.SimpleEntry<Product, Integer> billProduct: bill.getProductList()) {
            currentStock.computeIfPresent(billProduct.getKey(), (_, quantity) -> {
                if (billProduct.getValue().compareTo(quantity) <= 0) {
                    return quantity - billProduct.getValue();
                } else {
                    System.out.println("Insufficient stock - visiting Selgros soon");
                    return quantity;
                }
            });
        }

        synchronized (this) {
            this.income += bill.getTotalSum();
            this.processedBills.add(bill);
        }
    }
}