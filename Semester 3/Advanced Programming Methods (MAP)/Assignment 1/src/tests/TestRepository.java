package tests;

import module.Cube;
import module.Object;
import module.Sphere;
import repository.Repository;

public class TestRepository {
    public static void test() {
        Repository repository = new Repository();
        Cube object1 = new Cube(5);
        Cube object2 = new Cube(10);
        Sphere object3 = new Sphere(5);
        Sphere object4 = new Sphere(10);

        repository.addItem(object1);
        repository.addItem(object2);
        repository.addItem(object3);
        repository.addItem(object4);

        Object[] objects = repository.getAll();
        for(int i = 0; i < repository.getCurrentSize(); i++) {
            if(objects[i] != repository.getAll()[i]) {
                System.out.println("Test AddItem: Failed");

            }
        }
        System.out.println("Test AddItem: Passed");

        repository.removeItem(object1);
        if(repository.getCurrentSize() != 3) {
            System.out.println("Test Remove: Lack of Implementation");
            return;
        }

    }
}
