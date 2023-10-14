package module;

public class Cylinder implements Object {
    float edge;
    float volume;

    public Cylinder(float edge) {
        this.edge = edge;
        //All cylinders have height 5
        this.volume = (float) (5 * Math.PI * Math.pow(edge, 2));
    }

    @Override
    public float getVolume() {
        return this.volume;
    }

    @Override
    public float getParameter() {
        return this.edge;
    }

    public String toString(){
        return "Cylinder with edge " + this.edge + " and volume " + this.volume + "\n";
    }
}
