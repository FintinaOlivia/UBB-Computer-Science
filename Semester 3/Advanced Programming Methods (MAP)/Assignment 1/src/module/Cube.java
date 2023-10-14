package module;

import java.beans.ConstructorProperties;

public class Cube implements Object{
    public float volume;
    public float edge;

    public Cube(float volume, float edge){
        this.volume = volume;
        this.edge = edge;
    }

    public Cube(float edge){
        this.edge = edge;
        this.volume = edge * edge * edge;
    }
    public Cube(){
        this(0,0);
    }

    @Override
    public float getVolume() {
        return this.volume;
    }

    public float getParameter() {
        return this.edge;
    }

    public String toString(){
        return "Cube with edge " + this.edge + " and volume " + this.volume + "\n";
    }
}
