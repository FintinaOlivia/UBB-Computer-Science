import Components.LexicalAnalyzer;

public class Main {
    public static void main(String[] args) {
        LexicalAnalyzer scanner1 = new LexicalAnalyzer("src/Assets/Files/p1.ubb");
        LexicalAnalyzer scanner2 = new LexicalAnalyzer("src/Assets/Files/p2.ubb");
        LexicalAnalyzer scanner3 = new LexicalAnalyzer("src/Assets/Files/p3.ubb");
        LexicalAnalyzer scanner4 = new LexicalAnalyzer("src/Assets/Files/p1error.ubb");

        System.out.println("\n");
        System.out.println("p1.ubb");
        scanner1.run();
        System.out.println("\n");

        System.out.println("p2.ubb");
        scanner2.run();
        System.out.println("\n");

        System.out.println("p3.ubb");
        scanner3.run();
        System.out.println("\n");

        System.out.println("p1error.ubb");
        scanner4.run();
        System.out.println("\n");
    }
}