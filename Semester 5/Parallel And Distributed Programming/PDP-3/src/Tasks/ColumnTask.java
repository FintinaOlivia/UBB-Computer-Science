package Tasks;

import DataStructures.Matrix;
import Helpers.MatrixHelpers;

public class ColumnTask implements Runnable {
    private final Integer[][] result;

    private final Integer leftItemIndex;
    private final Integer rightItemIndex;

    private final Matrix firstMatrix;
    private final Matrix secondMatrix;

    private final Integer noOfColumns, load;

    public ColumnTask(Integer[][] result, int left, int right,
                      Matrix firstMatrix, Matrix secondMatrix, Integer noOfColumns, Integer load) {
        this.result = result;

        this.leftItemIndex = left;
        this.rightItemIndex = right;

        this.firstMatrix = firstMatrix;
        this.secondMatrix = secondMatrix;

        this.noOfColumns = noOfColumns;
        this.load = load;
    }

    @Override
    public void run() {
        int i = leftItemIndex % this.noOfColumns;
        int j = leftItemIndex / this.noOfColumns;

        for (int index = 0; index < load; ++index) {
            this.result[i][j] = MatrixHelpers.getCell(firstMatrix, secondMatrix, i, j);
            ++i;
            if (i == this.noOfColumns) {
                i = 0;
                ++j;
            }
        }
    }
}
