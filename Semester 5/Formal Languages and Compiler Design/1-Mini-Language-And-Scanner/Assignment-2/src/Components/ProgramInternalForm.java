package Components;

import DataStructures.Pair;

import java.util.ArrayList;
import java.util.List;

public class ProgramInternalForm {
    private List<Pair<String, Pair<Integer, Integer>>> tokenPositions;
    private List<TokenTypes> tokenTypes;

    public ProgramInternalForm() {
        this.tokenPositions = new ArrayList<>();
        this.tokenTypes = new ArrayList<>();
    }

    public void addToken(Pair<String, Pair<Integer, Integer>> pair, TokenTypes type){
        this.tokenPositions.add(pair);
        this.tokenTypes.add(type);
    }

    @Override
    public String toString(){
        StringBuilder computedString = new StringBuilder();
        for(int i = 0; i < this.tokenPositions.size(); i++) {
            computedString.append("Token { ")
                    .append(this.tokenPositions.get(i).getFirstTerm())
                    .append(" } - Position in Symbol Table: ")
                    .append(this.tokenPositions.get(i).getSecondTerm())
                    .append(" -> ")
                    .append(tokenTypes.get(i))
                    .append("\n");
        }

        return computedString.toString();
    }
}
