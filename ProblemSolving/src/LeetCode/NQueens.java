package LeetCode;


import java.util.ArrayList;
import java.util.List;

public class NQueens {

    public static void main(String[] args) {
        System.out.println(solveNQueens(4));
        System.out.println(solveNQueens(5));
    }

    // Time complexity: O(n!), space complexity: O(n^2)
    public static List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        queens(0, new boolean[n][n], res);
        return res;
    }

    private static void queens(int curr, boolean[][] board, List<List<String>> res) {
        if (curr == board.length) {
            res.add(createAnswer(board));
        } else {
            for (int i = 0; i < board.length; i++) {
                if (isValid(board, curr, i)) {
                    board[curr][i] = true;
                    queens(curr + 1, board, res);
                    board[curr][i] = false;
                }
            }
        }
    }

    private static boolean isValid(boolean[][] board, int row, int col) {
        for (boolean[] booleans : board) {
            if (booleans[col]) {
                return false;
            }
        }

        int maxLeft = Math.min(row, col);
        for (int i = 1; i <= maxLeft; i++) {
            if (board[row - i][col - i]) {
                return false;
            }
        }

        int maxRight = Math.min(row, board.length - 1 - col);
        for (int i = 1; i <= maxRight; i++) {
            if (board[row - i][col + i]) {
                return false;
            }
        }

        return true;
    }

    private static List<String> createAnswer(boolean[][] board) {
        List<String> res = new ArrayList<>();
        for (boolean[] booleans : board) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < board.length; j++) {
                if (booleans[j]) {
                    sb.append("Q");
                } else sb.append(".");
            }
            res.add(sb.toString());
        }

        return res;
    }
}
