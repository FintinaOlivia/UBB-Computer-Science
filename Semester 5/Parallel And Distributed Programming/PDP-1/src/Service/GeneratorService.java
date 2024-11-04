package Service;

import java.util.Random;


public class GeneratorService {
    private static final Random random = new Random();

    public GeneratorService() {

    }

    public static String generateRandomString(){
        int leftLimit = 97;
        int rightLimit = 122;
        int targetStringLength = 10;
        Random random = new Random();


        return random.ints(leftLimit, rightLimit + 1)
                .limit(targetStringLength)
                .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
                .toString();
    }

    public static int generateRandomInt(int low, int high){
        return random.ints(low, high).limit(1).sum();
    }
}