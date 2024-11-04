package Model;

import java.util.AbstractMap.SimpleEntry;
import java.util.List;

public class Bill {
    private List<SimpleEntry<Product, Integer>> productList;
    private int totalSum;

    public Bill(List<SimpleEntry<Product, Integer>> productList){
        this.productList = productList;
        this.totalSum = computeTotalSum();
    }

    private int computeTotalSum() {
        return productList.stream()
                .map(product -> product.getKey().getPrice() * product.getValue())
                .reduce(0, Integer::sum);
    }

    public int getTotalSum() {
        return totalSum;
    }

    public List<SimpleEntry<Product, Integer>> getProductList() {
        return productList;
    }

    public void setTotalSum(int totalSum) {
        this.totalSum = totalSum;
    }

    public void setProductList(List<SimpleEntry<Product, Integer>> productList) {
        this.productList = productList;
    }
}