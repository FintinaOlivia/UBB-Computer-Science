package tests;

import module.Cube;
import module.Sphere;

public class TestModule {
    public static void testCube() {
        // System.out.println("TestModule.test()");
        Cube cube1 = new Cube();
        Cube cube2 = new Cube(2);
        Cube cube3 = new Cube(27,3);

        float volume1 = cube1.getVolume();
        float volume2 = cube2.getVolume();
        float volume3 = cube3.getVolume();

        assert(volume1 == 0);
        assert(volume2 == 8);
        assert(volume3 == 27);

        System.out.println("Test Cube: passed");
    }

    public static void testSphere(){
        // System.out.println("Test Sphere");
        Sphere sphere1 = new Sphere();
        Sphere sphere2 = new Sphere(2);
        Sphere sphere3 = new Sphere(27,3);

        float volume1 = sphere1.getVolume();
        float volume2 = sphere2.getVolume();
        float volume3 = sphere3.getVolume();

        assert(volume1 == 0);
        assert(volume2 == 33.510002);
        assert(volume3 == 113.0976);

        System.out.println("Test Sphere: passed");
    }

    public static void test(){
        testCube();
        testSphere();
    }
}
