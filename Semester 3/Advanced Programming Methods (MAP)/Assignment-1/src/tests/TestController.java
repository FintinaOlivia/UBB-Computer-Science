package tests;

import controller.Controller;
import module.Sphere;
import repository.Repository;
import module.Cube;

public class TestController {
    public static void test(){
        Repository repository = new Repository();
        Controller controller = new Controller(repository);

        controller.addItem(new Cube(5));
        controller.addItem(new Cube(10));
        controller.addItem(new Sphere(5));

        try {
            controller.addItem(new Sphere(-5));
            System.out.println("Test AddItem: Passed (test)");
        } catch (Exception e) {
            System.out.println("Test AddItem: Failed (test)");
        }

//        int length = controller.getCurrentSize();
//        System.out.println("Length " + length);
//        for(int i = 0; i < length; i++){
//            System.out.println(controller.getAll().get(i).getVolume());
//        }

        if(controller.filter(150).size() != 2){
            System.out.println("Test Filter: Failed");
        }
        else{
            System.out.println("Test Filter: Passed");
        }
    }

}
