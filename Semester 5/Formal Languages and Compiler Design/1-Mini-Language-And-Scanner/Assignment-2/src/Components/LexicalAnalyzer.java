package Components;

import Assets.Constants;
import DataStructures.Pair;
import Helpers.FileHandler;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

public class LexicalAnalyzer {
    private final ArrayList<String> operators = new ArrayList<>();
    private final ArrayList<String> separators = new ArrayList<>();
    private final ArrayList<String> reservedWords = new ArrayList<>();

    private final String filePath;
    private final SymbolTable constantsTable = new SymbolTable();
    private final SymbolTable identifiersTable = new SymbolTable();
    private final ProgramInternalForm pif;


    public LexicalAnalyzer(String filePath) {
        initializeLanguageSpecificTokens();
        this.filePath = filePath;
        this.pif = new ProgramInternalForm();
    }

    public void run() {
        this.scan();

        String result = "Constants Table" +
                this.constantsTable +
                "\n\n" +

                "Identifiers Table" +
                this.identifiersTable +
                "\n";

        FileHandler.writeToFile(filePath.replace(".ubb", "ST.out"), result);
        FileHandler.writeToFile(filePath.replace(".ubb", "PIF.out"), this.pif);
    }

    private List<Pair<String, Pair<Integer, Integer>>> parseBySeparators(){
        try{
            String content = FileHandler.readFromFile(filePath);
            String separatorsString = this.separators.stream().reduce("", (a,b)->(a + b));
            StringTokenizer tokenizer = new StringTokenizer(content, separatorsString, true);

            List<String> tokens = Collections.list(tokenizer)
                    .stream()
                    .map(t->(String) t)
                    .collect(Collectors.toList());

            return tokenize(tokens);
        }
        catch (FileNotFoundException e){
            e.printStackTrace();
        }

        return null;
    }

    private List<Pair<String, Pair<Integer, Integer>>> tokenize(List<String> parsedBySeparators){

        List<Pair<String, Pair<Integer, Integer>>> resultedTokens = new ArrayList<>();
        boolean isStringConstant = false;
        boolean isCharConstant = false;

        StringBuilder currentToken = new StringBuilder();
        int numberLine = 1;
        int numberColumn = 1;

        for(String term: parsedBySeparators){
            switch (term) {
                case "\"":
                    currentToken.append(term);
                    if (isStringConstant) {
                        resultedTokens.add(new Pair<>(currentToken.toString(), new Pair<>(numberLine, numberColumn)));
                        currentToken = new StringBuilder();
                    }
                    isStringConstant = !isStringConstant;
                    break;
                case "'":
                    if (isCharConstant) {
                        currentToken.append(term);
                        resultedTokens.add(new Pair<>(currentToken.toString(), new Pair<>(numberLine, numberColumn)));
                        currentToken = new StringBuilder();
                    }
                    else {
                        currentToken.append(term);
                    }
                    isCharConstant = !isCharConstant;
                    break;
                case "\n":
                    numberLine++;
                    numberColumn = 5;
                    break;
                default:
                    if (isStringConstant) {
                        currentToken.append(term);
                    } else if (isCharConstant) {
                        currentToken.append(term);
                    } else if (!term.equals(" ")) {
                        resultedTokens.add(new Pair<>(term, new Pair<>(numberLine, numberColumn)));
                        numberColumn += term.length() + 1;
                    }
                    break;
            }
        }

        if (!currentToken.isEmpty()) {
            resultedTokens.add(new Pair<>(currentToken.toString(), new Pair<>(numberLine, numberColumn)));
        }

        return resultedTokens;
    }

    public void scan(){

        List<Pair<String, Pair<Integer, Integer>>> tokens = parseBySeparators();
        AtomicBoolean lexicalErrorExists = new AtomicBoolean(false);

        if(tokens == null){
            return;
        }

        tokens.forEach(element -> {
            String token = element.getFirstTerm();
            if(this.reservedWords.contains(token)) {
                this.pif.addToken(new Pair<>(token, new Pair<>(-1, -1)), TokenTypes.RESERVED_WORD);

            } else if(this.operators.contains(token)){
                this.pif.addToken(new Pair<>(token, new Pair<>(-1, -1)), TokenTypes.OPERATOR);

            } else if(this.separators.contains(token)){
                this.pif.addToken(new Pair<>(token, new Pair<>(-1, -1)), TokenTypes.SEPARATOR);

            } else if(Pattern.compile("^0|[-|+][1-9]([0-9])*|'[1-9]'|'[a-zA-Z]'|\\s*\"[^\"]*\\s*\"$")
                    .matcher(token).matches()) {
                this.constantsTable.add(token);
                this.pif.addToken(new Pair<>(token, constantsTable.findPositionOfTerm(token)), TokenTypes.CONSTANT);
            }
            else if(Pattern.compile("[a-zA-Z_][a-zA-Z_0-9]*").matcher(token).matches()) {
                this.identifiersTable.add(token);
                this.pif.addToken(new Pair<>(token, identifiersTable.findPositionOfTerm(token)), TokenTypes.IDENTIFIER);

            } else {
                Pair<Integer, Integer> pairLineColumn = element.getSecondTerm();
                System.out.println("Error at line: " + pairLineColumn.getFirstTerm()
                        + " and column: " + pairLineColumn.getSecondTerm()
                        + ", invalid token: " + element.getFirstTerm());
                lexicalErrorExists.set(true);
            }
        });

        if(!lexicalErrorExists.get()){
            System.out.println("Program is lexically correct!");
        }

    }

    private void initializeLanguageSpecificTokens() {
        TokenTypes currentCategory = null;
        this.separators.addAll(List.of(" ", "\n", "\t", "##", "//"));

        try (BufferedReader reader = new BufferedReader(new FileReader(Constants.tokenPath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) {
                    continue;
                }

                switch (line) {
                    case "[OPERATOR]":
                        currentCategory = TokenTypes.OPERATOR;
                        continue;
                    case "[SEPARATOR]":
                        currentCategory = TokenTypes.SEPARATOR;
                        continue;
                    case "[RESERVED_WORD]":
                        currentCategory = TokenTypes.RESERVED_WORD;
                        continue;
                    default:
                        if (currentCategory != null) {
                            switch (currentCategory) {
                                case OPERATOR -> this.operators.add(line);
                                case SEPARATOR -> this.separators.add(line);
                                case RESERVED_WORD -> this.reservedWords.add(line);
                            }
                        }
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
