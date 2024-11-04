import Repository.InventoryRepositoryInterface;
import Repository.ProductInventoryRepository;
import Service.InventoryService;

public class Main {
    public static void main(String[] args) {
        InventoryRepositoryInterface inventory = new ProductInventoryRepository();

        InventoryService inventoryService = new InventoryService(inventory);

        System.out.println("Benchmark: "
                + inventoryService.runOperations(20, 100, 1000000, 100,100)
                +"ms per test.");

    }
}