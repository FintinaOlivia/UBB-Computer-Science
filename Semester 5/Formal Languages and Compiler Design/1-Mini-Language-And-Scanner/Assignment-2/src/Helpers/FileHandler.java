package Helpers;

import DataStructures.HashTable;

import java.io.*;
import java.util.Scanner;

public class FileHandler {
    public static void populateSymbolTable(String filename, HashTable table) {
        try (BufferedReader reader = new BufferedReader(new java.io.FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                table.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static String readFromFile(String filePath) throws FileNotFoundException {
        StringBuilder fileContent = new StringBuilder();
        Scanner scanner = new Scanner(new File(filePath));
        while(scanner.hasNextLine()){
            fileContent.append(scanner.nextLine()).append("\n");
        }

        return fileContent.toString().replace("\t", "");
    }

    public static void writeToFile(String filePath, Object object) {
        try(PrintStream printStream = new PrintStream(filePath)) {
            printStream.println(object);
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
