package LeetCode;


public class SearchA2DMatrix {

    public static void main(String[] args) {
        System.out.println(searchMatrix(new int[][]{
                        {1, 3, 5, 7},
                        {10, 11, 16, 20},
                        {23, 30, 34, 60}},
                3));
        System.out.println(searchMatrix(new int[][]{
                        {1, 3, 5, 7},
                        {10, 11, 16, 20},
                        {23, 30, 34, 60}},
                13));
        System.out.println(searchMatrix(new int[][]{
                        {1}},
                0));
    }

    public static boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length - 1;
        int column = 0;

        while (row >= 0 && column < matrix[0].length) {
            if (matrix[row][column] == target) {
                return true;
            }
            if (matrix[row][column] < target) {
                column++;
            } else {
                row--;
            }
        }

        return false;
    }
}
