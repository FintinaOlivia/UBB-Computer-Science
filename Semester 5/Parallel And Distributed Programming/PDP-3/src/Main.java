import DataStructures.ApproachType;
import DataStructures.Matrix;
import Helpers.MatrixHelpers;
import Tasks.ColumnTask;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Main {
    public static Integer noOfColumnsM1, commonNoOfRowsM1ColM2, noOfRowsM2;

    public static Integer numberOfTasks;

    public static Matrix firstMatrix;
    public static Matrix secondMatrix;

    public static ApproachType approachType;

    public static void getUserInput() {
        Scanner scanner = new Scanner(System.in);

        noOfColumnsM1 = 9;
        commonNoOfRowsM1ColM2 = 9;
        noOfRowsM2 = 7;

        numberOfTasks = 4;

        System.out.println("Would you like to choose the default settings or input custom?");
        System.out.print("Default: \n" +
                "First Matrix: " + noOfColumnsM1 + " columns, " + commonNoOfRowsM1ColM2 + " rows\n" +
                "Second Matrix: " + commonNoOfRowsM1ColM2 + "  columns, " + noOfRowsM2 + " rows\n" +
                "Number of threads: " + numberOfTasks +"\n"
        );
        System.out.print("> default / custom: ");
        String response = scanner.nextLine();

        if (!response.equals("custom") && !response.equals("default")) {
            System.out.println("Invalid input: please try again using the right input.");
        }

        if (response.equals("custom")) {

            System.out.print("Number of columns of the first matrix: ");
            noOfColumnsM1 = scanner.nextInt();
            System.out.print("Number of rows of the first matrix, number of columns of the second matrix: ");
            commonNoOfRowsM1ColM2 = scanner.nextInt();
            System.out.print("Number of rows of the second matrix: ");
            noOfRowsM2 = scanner.nextInt();

            System.out.print("Desired approach - CLASSIC or THREAD_POOL: ");
            approachType = ApproachType.valueOf(scanner.next());

            System.out.println("Number of threads: ");
            numberOfTasks = scanner.nextInt();
        } else if(!response.equals("default")) {
            System.out.println("Invalid input: please try again using the right input.");
        }

        System.out.print("Desired approach: CLASSIC/ THREAD_POOL/ BOTH: ");
        approachType = ApproachType.valueOf(scanner.next().toUpperCase());

        generateMatrices();
    }

    public static void generateMatrices() {
        firstMatrix = new Matrix(noOfColumnsM1, commonNoOfRowsM1ColM2);
        secondMatrix = new Matrix(commonNoOfRowsM1ColM2, noOfRowsM2);
    }

    public static Matrix productByTasks() throws InterruptedException {
        Integer[][] result = new Integer[noOfColumnsM1][noOfRowsM2];
        List<Thread> threads = addToList(result, firstMatrix, secondMatrix, noOfColumnsM1, noOfRowsM2);
        for (Thread thread : threads)
            thread.start();
        for (Thread thread : threads)
            thread.join();
        return new Matrix(result);
    }

    public static Matrix productByThreadPool() throws InterruptedException {
        ThreadPoolExecutor executor = (ThreadPoolExecutor) Executors.newFixedThreadPool(Math.max(2,numberOfTasks/2));
        Integer[][] result = new Integer[noOfColumnsM1][noOfRowsM2];

        List<Runnable> tasks = addToList(result, firstMatrix, secondMatrix, noOfColumnsM1, noOfRowsM2);

        for (Runnable task : tasks)
            executor.execute(task);
        executor.shutdown();

        while (!executor.awaitTermination(1, TimeUnit.DAYS)){
            System.out.println("An error must have occurred.");
        }
        return new Matrix(result);
    }

    private static <TEntity> List<TEntity> addToList(Integer[][] result,
                                                     Matrix firstMatrix, Matrix secondMatrix, int noOfColumnsM1, int noOfRowsM2) {
        List<TEntity> list = new ArrayList<>();
        int loadPerThread = noOfColumnsM1*noOfRowsM2/ numberOfTasks;
        int remainder = noOfColumnsM1*noOfRowsM2 % numberOfTasks;

        for (int i = 0; i < numberOfTasks; ++i) {
            int left = i * loadPerThread;
            int right = Math.min((i+1) * loadPerThread, noOfColumnsM1*noOfRowsM2);
            if(i == numberOfTasks - 1) {
                right += remainder;
                loadPerThread += remainder;
            }

            System.out.println("Left: " + left);
            System.out.println("Right: " + right);
            System.out.print("Load: ");
            System.out.println(right - left);
            System.out.println();

            list.add((TEntity) new Thread(new ColumnTask(result, left, right, firstMatrix, secondMatrix, noOfColumnsM1, loadPerThread)));
        }
        return list;
    }

    private static void checkMultiplicationResult(Matrix sequentialResult, Matrix computedProduct){
        if (sequentialResult.equals(computedProduct))
            System.out.println("Check passed: The sequential result and the computed result are equal.");
        else System.out.println("Check failed: The sequential result and the computed result are not equal.");
    }

    public static void main(String[] args) throws InterruptedException {
        getUserInput();

        long startTime = System.nanoTime();
        Matrix sequentialResult = MatrixHelpers.multiply(firstMatrix, secondMatrix);
        long endTime = System.nanoTime();
        System.out.println("Sequential multiplication time: " + (endTime - startTime) / 1_000_000 + " ms");

        Matrix computedProduct;
        if (approachType.equals(ApproachType.CLASSIC)) {
            startTime = System.nanoTime();
            computedProduct = productByTasks();
            endTime = System.nanoTime();
            System.out.println("Task-based multiplication time: " + (endTime - startTime) / 1_000_000 + " ms");
            checkMultiplicationResult(sequentialResult, computedProduct);
        } else if(approachType.equals(ApproachType.THREAD_POOL)) {
            startTime = System.nanoTime();
            computedProduct = productByThreadPool();
            endTime = System.nanoTime();
            System.out.println("Thread pool-based multiplication time: " + (endTime - startTime) / 1_000_000 + " ms");
            checkMultiplicationResult(sequentialResult, computedProduct);
        } else if(approachType.equals(ApproachType.BOTH)) {
            startTime = System.nanoTime();
            computedProduct = productByTasks();
            endTime = System.nanoTime();
            System.out.println("Task-based multiplication time: " + (endTime - startTime) / 1_000_000 + " ms");
            checkMultiplicationResult(sequentialResult, computedProduct);

            startTime = System.nanoTime();
            computedProduct = productByThreadPool();
            endTime = System.nanoTime();
            System.out.println("Thread pool-based multiplication time: " + (endTime - startTime) / 1_000_000 + " ms");
            checkMultiplicationResult(sequentialResult, computedProduct);
        }
    }
}