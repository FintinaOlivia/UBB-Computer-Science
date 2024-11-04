package Service;

import Model.Bill;
import Model.Product;
import Model.Task.OperationRunnable;
import Repository.InventoryRepositoryInterface;

import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class InventoryService {
    private final InventoryRepositoryInterface inventory;
    private List<Product> productList;

    public InventoryService(InventoryRepositoryInterface inventory) {
        this.inventory = inventory;
        this.productList = new ArrayList<>();
    }

    private List<AbstractMap.SimpleEntry<Product, Integer>> generateProductList(int numberOfProducts,
                                                                                int initialQuantity) {
        List<AbstractMap.SimpleEntry<Product, Integer>> productList = new ArrayList<>();
        this.productList = new ArrayList<>();

        for (int index = 0; index < numberOfProducts; index++) {
            String productName = GeneratorService.generateRandomString();
            int productPrice = GeneratorService.generateRandomInt(5, 100);
            Product product = new Product(productName, productPrice);

            productList.add(new AbstractMap.SimpleEntry<>(product, initialQuantity));
            this.productList.add(product);
        }

        return productList;
    }

    private List<Bill> generateBillList(int numberOfProducts, int numberOfBills) {
        List<Bill> billList = new ArrayList<>();

        for (int index = 0; index < numberOfBills; index++){
            Collections.shuffle(this.productList);
            List<Product> products = this.productList.subList(0, numberOfProducts);


            List<AbstractMap.SimpleEntry<Product, Integer>> billProducts = products.stream()
                    .map(product ->
                            new AbstractMap.SimpleEntry<>(product, GeneratorService.generateRandomInt(5, 15)))
                    .collect(Collectors.toList());

            Bill bill = new Bill(billProducts);
            billList.add(bill);
        }

        return billList;

    }

    public double runOperations(int numberOfTests, int numberOfProducts, int initialQuantity,
                                int numberOfBills, int threadCount){
        List<Thread> threads = new ArrayList<>();

        List<Long> runTimes = new ArrayList<>();

        for(int index = 0; index < numberOfTests; index++){
            inventory.resetStock(generateProductList(numberOfProducts, initialQuantity));

            for(int i = 0; i < threadCount; i++){
                List<Bill> billList = generateBillList(numberOfProducts, numberOfBills);

                OperationRunnable operationRunnable = new OperationRunnable(inventory, billList);

                Thread thread = new Thread(operationRunnable);

                threads.add(thread);
                thread.start();
            }

            Long startTime = System.currentTimeMillis();


            for(Thread thread: threads){
                try {
                    thread.join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            inventory.checkInventory();

            Long endTime = System.currentTimeMillis();

            Long runTime = (endTime - startTime);
            runTimes.add(runTime);
        }

        return runTimes.stream().reduce(0L, Long::sum) / (double) numberOfTests;
    }
}