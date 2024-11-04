package DataStructures;

import java.util.Random;

public class Matrix {
    private final Integer[][] matrix;
    private final Integer nrOfColumns, nrOfRows;

    public Matrix(Integer[][] matrix) {
        this.matrix = matrix;
        this.nrOfColumns = matrix.length;
        this.nrOfRows = matrix[0].length;
    }

    public Matrix(int columns, int rows) {
        this.matrix = new Integer[columns][rows];
        this.nrOfColumns = columns;
        this.nrOfRows = rows;

        Random random = new Random();
        for (int i = 0; i < columns; ++i)
            for (int j = 0; j < rows; ++j)
                matrix[i][j] = random.nextInt(10);
    }

    public int getElementOnPosition(int i, int j) {
        return matrix[i][j];
    }

    public Integer getNrOfColumns() {
        return nrOfColumns;
    }

    public Integer getNrOfRows() {
        return nrOfRows;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < this.nrOfColumns; i++) {
            for (int j = 0; j < this.nrOfRows; j++) {
                builder.append(matrix[i][j]).append(" ");
            }
            builder.append("\n");
        }
        return builder.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Matrix objMatrix))
            return false;
        if (!nrOfColumns.equals(objMatrix.nrOfColumns) || !nrOfRows.equals(objMatrix.nrOfRows))
            return false;
        for (int i = 0; i < nrOfColumns; ++i)
            for (int j = 0; j < nrOfRows; ++j)
                if (!matrix[i][j].equals(objMatrix.matrix[i][j]))
                    return false;
        return true;
    }
}