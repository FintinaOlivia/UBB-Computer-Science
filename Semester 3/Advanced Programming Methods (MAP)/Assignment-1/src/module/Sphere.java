package module;

public class Sphere implements Object {
    public float volume;
    public float radius;

    public Sphere(float volume, float radius){
        this.volume = volume;
        this.radius = radius;
    }

    public Sphere(float radius){
        this.radius = radius;
        this.volume = (float) (4 / 3 * 3.1415 * radius * radius * radius);
    }

    public Sphere(){
        this(0,0);
    }

    @Override
    public float getVolume() {
        return this.volume;
    }

    public float getParameter(){
        return this.radius;
    }

    public String toString(){
        return "Sphere with radius " + this.radius + " and volume " + this.volume + "\n";
    }
}
