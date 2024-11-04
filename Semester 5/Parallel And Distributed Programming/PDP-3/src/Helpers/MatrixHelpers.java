package Helpers;

import DataStructures.Matrix;

public class MatrixHelpers {
    public static int getCell(Matrix firstMatrix, Matrix secondMatrix, int a, int b) {
        int result = 0;
        for (int i = 0; i < firstMatrix.getNrOfRows(); ++i)
            result += firstMatrix.getElementOnPosition(a, i) * secondMatrix.getElementOnPosition(i, b);
        return result;
    }

    public static Matrix multiply(Matrix firstMatrix, Matrix secondMatrix) {
        Integer[][] product = new Integer[firstMatrix.getNrOfColumns()][secondMatrix.getNrOfRows()];
        for (int i = 0; i < firstMatrix.getNrOfColumns(); ++i)
            for (int j = 0; j < secondMatrix.getNrOfRows(); ++j)
                product[i][j] = getCell(firstMatrix, secondMatrix, i, j);
        return new Matrix(product);
    }

}
