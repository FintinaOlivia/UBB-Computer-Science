package DataStructures;

public class Pair<TFirst, TSecond> {
    private final TFirst firstTerm;
    private final TSecond secondTerm;

    public Pair(TFirst first, TSecond second) {
        this.firstTerm = first;
        this.secondTerm = second;
    }

    public TFirst getFirstTerm() {
        return this.firstTerm;
    }

    public TSecond getSecondTerm() {
        return this.secondTerm;
    }

    @Override
    public String toString() {
        return "{"+ firstTerm
                + ", " + secondTerm
                + '}';
    }
}
